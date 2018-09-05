#pragma once

/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-12-13
Description: ��ȡEmbedded Controller����Ϣ
**************************************************/

#include "../../../../ACPI/ACPI/ACPI.h"

#define MK_PCIEADDR(bus, dev, func, off) (ULONG)(((bus & 0xFF) << 20) | (dev & 0x1F) << 15 | (func & 0x07) << 12 | off)

/**************************************************************
*@Function				Initialize
*@brief					����ACPI dll
*@author				��˶
*@param
	*@hMoudle			IN Dll����ģ������Ե�ַ
*@return
	*@BOOL				�����Ƿ�ɹ�
****************************************************************/
BOOL Initialize(HMODULE& hMoudle);

/**************************************************************
*@Function				Free
*@brief					�ͷ�dll
*@author				��˶
*@param
	*@hMoudle			IN Dll����ģ������Ե�ַ
*@return
	*@BOOL				�ͷ��Ƿ�ɹ�
****************************************************************/
void Free(HMODULE& hMoudle);

/**************************************************************
*@Function				GetPCIEBaseAddress
*@brief					��ȡPCIE��Memoryӳ���еĵ�ַ
*@author				��˶
*@param
	*@PCIE_BaseAddress	OUT ���PCIE Configuration Space ���ڴ��еĻ���ַ
*@return
	*@BOOL				��ȡPCIE����ַ�Ƿ�ɹ�
****************************************************************/
BOOL GetPCIEBaseAddress(_Out_ ULONGLONG& PCIE_BaseAddress);

/**************************************************************
*@Function				GetPCIEConfigSpace
*@brief					��ȡPCIE Configuration Space
*@author				��˶
*@param
	*@PCIE_BaseAddress	IN PCIE�ڴ��ַ
	*@Data				INOut PCIE���ÿռ�����
	*@DataSize			INOut PCIE���ÿռ��С
*@return
	*@BOOL				��ȡConfiguration Space�Ƿ�ɹ�
****************************************************************/
BOOL GetPCIEConfigSpace(const ULONGLONG PCIE_BaseAddress, PVOID* Data, size_t DataSize);