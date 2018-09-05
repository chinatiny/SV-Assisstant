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

#define READ_BIT				0x01

#define SMBUS_INTERRUPT_MASK	0x02
#define HOSTBUSY_MASK			0x01

#define SMBUS_READ_BYTE_COMMAND	0x48
#define SMBUS_READ_COMMAND		0x44

#define MAX_READ_TSC_COUNT		(2000000000 / 10)

#define PMIO_INDEX_REG			0xCD6
#define PMIO_DATA_REG			0xCD7

#define SMBUS_BAR_LOW_BYTE		0x2C
#define SMBUS_BAR_HIGH_BYTE		0x2D

#define SMBUS_STATUS_REG		0x00
#define SMBUS_SLAVE_STATUS_REG	0x01
#define SMBUS_COMMAND_REG		0x02
#define SMBUS_CONTROL_REG		0x03
#define SMBUS_HOST_CMD_REG		0x04
#define SMBUS_DATA0_REG			0x05
#define SMBUS_CLOCK_REG			0x0E

#define STATUS__COMPLETED_SUCCESSFULLY	0x02

#define SMBUS_FREQUENCY_CONST	66000000 / 4

/* I801 command constants */
#define I801_QUICK		(0 << 2)
#define I801_BYTE		(1 << 2)
#define I801_BYTE_DATA		(2 << 2)
#define I801_WORD_DATA		(3 << 2)
#define I801_BLOCK_DATA		(5 << 2)
#define I801_I2C_BLOCK_DATA	(6 << 2) /* ICH5 and later */

/* I801 Host Control register bits */
#define SMBHSTCNT_INTREN	(1 << 0)
#define SMBHSTCNT_KILL		(1 << 1)
#define SMBHSTCNT_LAST_BYTE	(1 << 5)
#define SMBHSTCNT_START		(1 << 6)
#define SMBHSTCNT_PEC_EN	(1 << 7) /* ICH3 and later */

/* I801 Hosts Status register bits */
#define SMBHSTSTS_BYTE_DONE	(1 << 7)
#define SMBHSTSTS_INUSE_STS	(1 << 6)
#define SMBHSTSTS_SMBALERT_STS	(1 << 5)
#define SMBHSTSTS_FAILED	(1 << 4)
#define SMBHSTSTS_BUS_ERR	(1 << 3)
#define SMBHSTSTS_DEV_ERR	(1 << 2)
#define SMBHSTSTS_INTR		(1 << 1)
#define SMBHSTSTS_HOST_BUSY	(1 << 0)

#define SMBUS_TIMEOUT		(10 * 1000 * 100)
#define SMBUS_BLOCK_MAXLEN	32

/* I2C controller failures */
#define 	CB_I2C_NO_DEVICE -300	/**< Device is not responding */
#define 	CB_I2C_BUSY -301	/**< Device tells it's busy */
#define 	CB_I2C_PROTOCOL_ERROR -302	/**< Data lost or spurious slave
									device response, try again? */
#define 	CB_I2C_TIMEOUT -303 /**< Transmission timed out */

#define SMBUS_ERROR			-1
#define SMBUS_WAIT_UNTIL_READY_TIMEOUT	CB_I2C_BUSY
#define SMBUS_WAIT_UNTIL_DONE_TIMEOUT	CB_I2C_TIMEOUT
#define SMBUS_WAIT_UNTIL_ACTIVE_TIMEOUT	CB_I2C_NO_DEVICE

int Platform_id;

#define INTEL_PLATFORM  0x8086ul
#define AMD_PLATFORM	0x1022ul
#define ZX_PLATFORM		0x1106ul
#define ATI_PLATFORM	0x1002ul
#define NVI_PLATFORM	0x10DEul

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
Function:       // SMBUS_Read_Byte Zhaoxin
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

NTSTATUS __stdcall SMBUS_Read_Byte_Zhaoxin(size_t Base_Address, size_t Slave_Address, size_t Offset, OUT PUCHAR Data);

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

void writePmReg(UINT8 reg, UINT8 data);

void setupFch(UINT16 SmbusBase);

int do_smbus_read_byte(unsigned int smbus_base, UINT16 device,
	unsigned int address);

int smbus_wait_until_active(UINT32 smbus_base);

int smbus_wait_until_ready(UINT32 smbus_base);

int smbus_wait_until_done(UINT32 smbus_base);
#endif