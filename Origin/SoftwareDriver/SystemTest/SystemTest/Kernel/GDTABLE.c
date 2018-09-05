#include "../Driver/Driver.h"
#pragma intrinsic(_sgdt) 
/*
���ݣ�Table 3-1. Code- and Data-Segment Types������WINDBG��dg����塣
*/
const char SegmentTypes[][256] = {
	"<Reserved>",//Data Read-Only��д�ǣ�Data RO��Ҳ����Ϊ�ǣ� <Reserved>������ṹ��UINT64��ȫ��Ϊ�㣬Ҳ����Ϊ��Reserved��
	"Data RO AC",//Data Read-Only, accessed
	"Data RW",//Data Read/Write
	"Data RW AC",//Data Read/Write, accessed
	"Data RO ED",//Data Read-Only, expand-down
	"Data RO ED AC",//Data Read-Only, expand-down, accessed
	"Data RW ED",//Data Read/Write, expand-down
	"Data RW ED AC",//Data Read/Write, expand-down, accessed

	"Code EO",//Code Execute-Only
	"Code EO AC",//Code Execute-Only, accessed
	"Code RE",//Code Execute/Read �ӿո��Ա���ʾ�Ķ��롣
	"Code RE AC",//Code Execute/Read, accessed
	"Code EO CO",//Code Execute-Only, conforming
	"Code EO CO AC",//Code Execute-Only, conforming, accessed
	"Code RE CO",//Code Execute/Read, conforming
	"Code RE CO AC",//Code Execute/Read, conforming, accessed
	"TSS32 Busy ",//���Ҳ����ʾֻҪʶ����TSS�����ݡ�
	"TSS32 Avl" //�����X86�ϳ����ˡ�
};

NTSTATUS EnumGdtTable(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength, _Out_opt_ size_t* Resquestlength)
{
	if (!InputBufferLength || !OutputBufferLength)
		return STATUS_BUFFER_TOO_SMALL;
	NTSTATUS status = STATUS_SUCCESS;

	size_t InputBufferlength = 0;
	PDWORD64 InputBuffer = NULL;
	status = WdfRequestRetrieveInputBuffer(Request, 1, &InputBuffer, &InputBufferlength);
	if (!NT_SUCCESS(status))
		return status;
	size_t i = *InputBuffer;
	if (i >= KeNumberProcessors)
		i = KeNumberProcessors - 1;
	show_gdt(Request, InputBufferLength, OutputBufferLength, Resquestlength, i);

	return STATUS_SUCCESS;
};
NTSTATUS show_gdt(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength, _Out_opt_ size_t* Resquestlength, size_t i)
{
	GDTINFO GdtLimit = { 0 };
	KeSetSystemAffinityThread(i + 1);
	PKGDTENTRY64 pkgdte = KeGetPcr()->GdtBase;//û��__sgdt,Ҳ����sgdt���ָ��İ취�����������ȡ��û�г��ȡ�
	_sgdt(&GdtLimit);//һ�����0x7f.
	KeRevertToUserAffinityThread();
	SIZE_T maximun = (GdtLimit.Limit + 1) / sizeof(KGDTENTRY64);

	/*
	��ʾ��ʽ��
	CPU SN Sel        Base              Limit          Type    Pl Size Gran Pres Long Flags
	--- -- ---- ----------------- ----------------- ---------- -- ---- ---- ---- ---- --------

	ע�ͣ�CPU��SN���Լ���ӵġ�SN��Segment Name,�磺CS��DS��FS��.
	*/
	KdPrint(("Sel        Base             Limit             Type   DPl Size Gran Pres Long Flags\n"));//CPU SN 
	KdPrint(("---- ---------------- ---------------- ------------- --- ---- ---- ---- ---- --------\n"));//--- -- 
	KdPrint(("\n"));

	NTSTATUS status = STATUS_SUCCESS;
	size_t OutputBufferlength = 0;
	PGPTABLE_STRUCT buffer = NULL;
	status = WdfRequestRetrieveOutputBuffer(Request, (maximun - 1) * sizeof(GPTABLE_STRUCT), &buffer, &OutputBufferlength);
	if (!NT_SUCCESS(status))
	{
		if (STATUS_BUFFER_TOO_SMALL == status)
		{
			status = WdfRequestRetrieveOutputBuffer(Request, sizeof(WORD), &buffer, &OutputBufferlength);
			if (NT_SUCCESS(status))
			{
				*(PDWORD64)buffer = (maximun - 1) * sizeof(GPTABLE_STRUCT);
				*Resquestlength = OutputBufferlength;
				status = STATUS_SUCCESS;
			}
		}
		return status;
	}
	RtlZeroMemory(buffer, OutputBufferlength);
	*Resquestlength = OutputBufferlength;

	for (SIZE_T index = 1; index < maximun; index++)
	{
		PKGDTENTRY64 pkgdte_t = &pkgdte[index];
		SIZE_T Base = 0;
		SIZE_T Limit = 0;
		LONG  Type = 0;
		char * size = NULL;
		char * Granularity = NULL;
		char * Present = NULL;
		char * LongMode = NULL;
		int    Flags = 0;

		Base = pkgdte_t->Bits.BaseHigh;
		Base = (Base << 24);
		Base += (pkgdte_t->BaseLow + (pkgdte_t->Bits.BaseMiddle << 16));

		Limit = pkgdte_t->LimitLow + (pkgdte_t->Bits.LimitHigh << 16);

		if (pkgdte_t->Bits.DefaultBig && Base)
		{
			//�����λΪ1.��F.
			Base += 0xffffffff00000000;
		}

		if (pkgdte_t->Bits.DefaultBig && pkgdte_t->Bits.Granularity)
		{
			//�����λΪ1.��F.
			SIZE_T t = Limit;
			Limit = (Limit << 12);
			Limit += PAGE_SIZE - 1;
		}

		Type = pkgdte_t->Bits.Type;
		_bittestandreset(&Type, 4);//��Ϊ���������Sλ������Ҫ������λ��־��

		if (pkgdte_t->Bits.DefaultBig)
		{
			size = "Bg  ";//Big �ӿո���Ϊ�˶�����ʾ��
		}
		else
		{
			size = "Nb  ";//Not Big �ӿո���Ϊ�˶�����ʾ��
		}

		if (pkgdte_t->Bits.Granularity)
		{
			Granularity = "Pg  ";//Page �ӿո���Ϊ�˶�����ʾ��
		}
		else
		{
			Granularity = "By  ";//Byte �ӿո���Ϊ�˶�����ʾ��
		}

		if (pkgdte_t->Bits.Present)
		{
			Present = "P   ";//Present �ӿո���Ϊ�˶�����ʾ��
		}
		else
		{
			Present = "NP  ";//NO Present �ӿո���Ϊ�˶�����ʾ��
		}

		if (pkgdte_t->Bits.LongMode)
		{
			LongMode = "Lo  ";//Long �ӿո���Ϊ�˶�����ʾ��
		}
		else
		{
			LongMode = "Nl  ";//NO long �ӿո���Ϊ�˶�����ʾ��
		}

		Flags = (pkgdte_t->Bytes.Flags2 >> 4);//ȥ��Segment limit���Ǽ�λ��
		Flags = Flags << 8;
		Flags = Flags + pkgdte_t->Bytes.Flags1;

		KdPrint(("%04x %p %p %13s %03x %s %s %s %s 0x%04x\n",
			index * 8, //sizeof (KGDTENTRY)
			Base,
			Limit,
			SegmentTypes[Type],
			pkgdte_t->Bits.Dpl,
			size,
			Granularity,
			Present,
			LongMode,
			Flags
			));
		buffer->Base = Base;
		buffer->Flags = Flags;
		buffer->Limit = Limit;
		buffer->Index = index * 8;
		buffer->DPl = pkgdte_t->Bits.Dpl;
		RtlCopyMemory(buffer->SegmentTypes, SegmentTypes[Type], strlen(SegmentTypes[Type]));
		RtlCopyMemory(buffer->Granularity, Granularity, 2);
		RtlCopyMemory(buffer->Present, Present, 2);
		RtlCopyMemory(buffer->LongMode, LongMode, 2);
		RtlCopyMemory(buffer->size, size, 2);
		buffer++;
	}
	return STATUS_SUCCESS;
}