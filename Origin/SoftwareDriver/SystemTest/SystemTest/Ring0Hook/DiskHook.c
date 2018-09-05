#include "../Driver/Driver.h"

NTSTATUS EnumDiskAddress(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength, size_t* Resquestlength)
{
	if (!OutputBufferLength)
		return STATUS_BUFFER_TOO_SMALL;
	UNICODE_STRING mou;
	PDRIVER_OBJECT DriverObject = NULL; //���̵��������󣬱��������Ϊ����ж��ʱ��ԭ���ķַ�����
	RtlInitUnicodeString(&mou, L"\\Driver\\disk");
	NTSTATUS status = ObReferenceObjectByName(&mou,
		OBJ_CASE_INSENSITIVE,
		NULL,
		0,
		*IoDriverObjectType,
		KernelMode,
		NULL,
		(PVOID*)&DriverObject);
	if (!NT_SUCCESS(status))
	{
		return status;
	}

	size_t OutputBufferlength = 0;
	PDWORD64 buffer = NULL;
	status = WdfRequestRetrieveOutputBuffer(Request, IRP_MJ_MAXIMUM_FUNCTION * sizeof(DWORD64), &buffer, &OutputBufferlength);

	if (!NT_SUCCESS(status))
	{
		if (STATUS_BUFFER_TOO_SMALL == status)
		{
			status = WdfRequestRetrieveOutputBuffer(Request, sizeof(WORD), &buffer, &OutputBufferlength);
			if (NT_SUCCESS(status))
			{
				*buffer = IRP_MJ_MAXIMUM_FUNCTION * sizeof(DWORD64);
				*Resquestlength = OutputBufferlength;
				status = STATUS_SUCCESS;
			}
		}
		return status;
	}
	RtlZeroMemory(buffer, OutputBufferlength);
	*Resquestlength = OutputBufferlength;

	if (MmIsAddressValid(DriverObject))
	{
		if (DriverObject->MajorFunction)
			for (int i = 0; i <= IRP_MJ_MAXIMUM_FUNCTION; i++)
			{
				KdPrint(("Func Name: %s, Address: 0x%llX\n", IPR_FUNC_NAME[i], (DWORD64)DriverObject->MajorFunction[i]));
				*buffer = (DWORD64)DriverObject->MajorFunction[i];
				buffer++;
			}
	}
	ObDereferenceObject(DriverObject);
	return status;
}