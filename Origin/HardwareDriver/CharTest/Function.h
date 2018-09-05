#pragma once

/*++

Module Name:

Function.h

Abstract:

This file contains the Function definitions.

Environment:

Kernel-mode Driver Framework

--*/


/*************************************************
Copyright:
Author:��˶
Date:2017-10-19
Description:ʵ�ֶ�Ӳ���Ķ�д����
**************************************************/
#ifndef FUNCTION_H
#define FUNCTION_H

#define MK_PCIADDR(bus, dev, func, off) (ULONG)(0x80000000L|((bus & 0xFF) << 16) | (dev & 0x1F) << 11 | (func & 0x07) << 8 | off)

//extern void Memory_Map(PULONG mmmp_entry, PULONG mmmp_count);


/*************************************************
Function:       // ReadIoPort
Description:    // ��ȡIO�ڵ�����
Calls:          // NULL
Input:          
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadIoPort(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // WriteIoPort
Description:    // ������д��IO��
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
WriteIoPort(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // ReadMsr
Description:    // ��ȡMSR������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadMsr(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // WriteMsr
Description:    // д��MSR������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
WriteMsr(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // ReadMsrThread
Description:    // ��ȡMSR������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
	Others:         // NULL
*************************************************/

NTSTATUS
ReadMsrThread(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // WriteMsrThread
Description:    // д��MSR������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
	Others:         // NULL
*************************************************/

NTSTATUS
WriteMsrThread(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);


/*************************************************
Function:       // ReadPmc
Description:    // ��ȡPMC������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadPmc(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // ReadMemory
Description:    // ��ȡ�ڴ��ַ�е�����
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadMemory(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // WriteMemory
Description:    // д���ڴ��ַ������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
WriteMemory(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // ReadPciConfig
Description:    // ��ȡPCI���ÿռ������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadPciConfig(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // WritePciConfig
Description:    // д��PCI���ÿռ�ĵ�����
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
WritePciConfig(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // ReadSPDBYTE
Description:    // ��ȡSPD������
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS
ReadSPDBYTE(
	_In_ WDFREQUEST Request,
	_In_ size_t OutputBufferLength,
	_In_ size_t InputBufferLength
);

/*************************************************
Function:       // SMBUS_Read_Byte
Description:    // ���ֽڶ�ȡSPD�е�����
Calls:          // ReadSPDBYTE
Input:
Request 
	Base_Address SMBUS�ĵ�ַ
	Slave_Address ���豸�еĵ�ַ
	Offset ��ȡ���ݵ�ƫ����
Output:         
	Data ���ֽ������ȡ������
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS __stdcall SMBUS_Read_Byte(size_t Base_Address, size_t Slave_Address, size_t Offset, OUT PUCHAR Data);

/*************************************************
Function:       // ReadITEDisk
Description:    // ��ȡITEӲ�̵�Identify
Calls:          // NULL
Input:
	Request IRP�������
	InputBufferLength ������ݵĳ���
	OutputBufferLength �������ݵĳ���
Output:         // NULL��
Return:         // ��������ֵ��˵��
Others:         // NULL
*************************************************/

NTSTATUS ReadITEDisk(
	WDFREQUEST Request,
	size_t OutputBufferLength,
	size_t InputBufferLength
);
#endif