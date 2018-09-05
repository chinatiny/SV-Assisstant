#include "../Driver/Driver.h"
#pragma intrinsic(__sidt)
const char* const IST_NAME[] = 
{
	"Divide Error",
	"Debug",
	"NMI Interrupt Not applicable",
	"Breakpoint",
	"Overflow",
	"BOUND Range Exceeded",
	"Invalid Opcode",
	"Device Not Available",
	"Double Fault",
	"Coprocessor Segment Overrun", // Intel reserved
	"Invalid TSS",
	"Segment Not Present",
	"Stack Fault",
	"General Protection",
	"Page-Fault",
	"Intel reserved",
	"x87 FPU Floating-Point",
	"Alignment Check",
	"Machine-Check",
	"SIMD Floating-Point",
	"Virtualization",
	"Intel reserved",
	"User Defined"
};
NTSTATUS EnumIDTableAddress(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength, _Out_opt_ size_t* Resquestlength)
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
	Show_Idt(Request, InputBufferLength, OutputBufferLength, Resquestlength, i);

	return STATUS_SUCCESS;
}

NTSTATUS Show_Idt(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength, size_t* Resquestlength, int num)
{
	NTSTATUS status = STATUS_SUCCESS;
	GDTINFO idtr = { 0 };
	KeSetSystemAffinityThread(num);
	PKIDTENTRY64 idt = KeGetPcr()->IdtBase;
	__sidt(&idtr);
	KeRevertToUserAffinityThread();
	DWORD maximun = 0;
	if (idtr.Limit % sizeof(KIDTENTRY64) == 0) {//idtr.Pad[0] == 0xfff.
		maximun = idtr.Limit / sizeof(KIDTENTRY64);
	}
	else {
		maximun = idtr.Limit / sizeof(KIDTENTRY64);
		maximun++;//�����Ҳ��256.
	}


	size_t OutputBufferlength = 0;
	PIDTABLE_STRUCT buffer = NULL;
	status = WdfRequestRetrieveOutputBuffer(Request, maximun * sizeof(IDTABLE_STRUCT), &buffer, &OutputBufferlength);
	if (!NT_SUCCESS(status))
	{
		if (STATUS_BUFFER_TOO_SMALL == status)
		{
			status = WdfRequestRetrieveOutputBuffer(Request, sizeof(WORD), &buffer, &OutputBufferlength);
			if (NT_SUCCESS(status))
			{
				*(PDWORD64)buffer = maximun * sizeof(IDTABLE_STRUCT);
				*Resquestlength = OutputBufferlength;
				status = STATUS_SUCCESS;
			}
		}
		return status;
	}
	RtlZeroMemory(buffer, OutputBufferlength);
	*Resquestlength = OutputBufferlength;

	if (MmIsAddressValid(idt))
	{
		for (USHORT i = 0; i < maximun; i++)
		{
			SIZE_T ISR = 0;
			PKIDTENTRY64 pkidte_t = (idt + i);
			ISR = pkidte_t->OffsetHigh;
			ISR = (ISR << 32);
			ISR |= (DWORD)(pkidte_t->OffsetLow + (pkidte_t->OffsetMiddle << 16));
			buffer->CPUNum = num;
			buffer->InterruptAddress = ISR;
			buffer->InterruptNums = i;
			if(i <= 20)
				KdPrint(("��%d��CPU�ĵ�0x%02x�ж� ��������:%s ��ַ:0x%llX\n", num, i, IST_NAME[i], ISR));//�����Խ�һ����ȡStack����Ϣ��P2863
			else if(i > 20 && i <= 32)
				KdPrint(("��%d��CPU�ĵ�0x%02x�ж� ��������:%s ��ַ:0x%llX\n", num, i, IST_NAME[21], ISR));//�����Խ�һ����ȡStack����Ϣ��P2863
			else
				KdPrint(("��%d��CPU�ĵ�0x%02x�ж� ��������:%s ��ַ:0x%llX\n", num, i, IST_NAME[22], ISR));//�����Խ�һ����ȡStack����Ϣ��P2863
			buffer++;
		}
	}
	else
		status = STATUS_UNSUCCESSFUL;

	return status;
}
