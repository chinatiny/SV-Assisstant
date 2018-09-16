#pragma once
/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-10-27
Description:�������ж�ȡIO Memory PCI MSR SuperIO SPD�ȵ���Ϣ
**************************************************/
#include <algorithm>
#include "Load/Driver.h"

//-----------------------------------------------------------------------------
//
// Global
//
//-----------------------------------------------------------------------------

extern HANDLE gHandle;
extern TCHAR gDriverPath[MAX_PATH];

#define		EC_SC					0x66
#define		EC_DATA					0x62
#define		RD_EC					0x80
#define		WR_EC					0x81
#define		BE_EC					0x82
#define		BD_EC					0x83
#define		QR_EC					0x84

class CRing0
{
public:
	CRing0();
	~CRing0();
	/**************************************************
	*@Function				RdMsr
	*@brief					��ȡMSR��ֵ
	*@author				��˶
	*@param
		*@Index				IN ����MSR������
		*@threadAffinityMask�����߳������еĺ���
		*@Data				OUT ���MSR��ֵ��64λ
	*@return
		*@BOOL				�Ƿ�ɹ�
	***************************************************/
	BOOL RdMsr(IN DWORD Index, OUT DWORD64& Data);

	/**************************************************
	*@Function				WrMsr
	*@brief					дMSR��ֵ
	*@author				��˶
	*@param
		*@Index				IN ����MSR������
		*@threadAffinityMask�����߳������еĺ���
		*@Data				IN ��Ҫд��MSR��ֵ��64λ
	*@return
		*@BOOL				�Ƿ�ɹ�
	***************************************************/
	BOOL WrMsr(IN DWORD Index, IN DWORD64 Data);

	BOOL RdTsc(OUT DWORD64 & Data);

	BOOL RdTscTx(IN DWORD threadAffinityMask, OUT DWORD64 & Data);

	/**************************************************
	*@Function				RdMsr
	*@brief					��ȡMSR��ֵ
	*@author				��˶
	*@param
		*@Index				IN ����MSR������
		*@threadAffinityMask�����߳������еĺ���
		*@Data				OUT ���MSR��ֵ��64λ
	*@return
	*@BOOL				�Ƿ�ɹ�
	***************************************************/
	BOOL RdMsrTx(IN DWORD Index, IN DWORD threadAffinityMask, OUT DWORD64& Data);

	/**************************************************
	*@Function				WrMsr
	*@brief					дMSR��ֵ
	*@author				��˶
	*@param
		*@Index				IN ����MSR������
		*@threadAffinityMask�����߳������еĺ���
		*@Data				IN ��Ҫд��MSR��ֵ��64λ
	*@return
	*@BOOL				�Ƿ�ɹ�
	***************************************************/
	BOOL WrMsrTx(IN DWORD Index, IN DWORD threadAffinityMask, IN DWORD64 Data);

	/**********************************************************************
	*@Function				RdIOPort
	*@brief					��ȡIO Port��ֵ
	*@author				��˶
	*@param
		*@IO_Port_Addr		IN IO Port�ĵ�ַ
		*@IO_DataSize		IN IO ������ݵĴ�С 1��2��4��8��16��32bits��
		*@IO_Data			OUT �����IO Port�е�ֵ
	*@return
	*@BOOL				�Ƿ�ɹ�
	**************************************************************************/
	BOOL RdIOPort(IN USHORT IO_Port_Addr, IN USHORT IO_DataSize, OUT DWORD& IO_Data);

	/**********************************************************************
	*@Function				WrIOPort
	*@brief				д��IO Port��ֵ
	*@author			��˶
	*@param
		*@IO_Data			IN ����IO Port��ֵ
		*@IO_DataSize		IN IO ������ݵĴ�С 1��2��4��8��16��32bits��
	*@IO_Port_Addr		IN ����IO Port�ĵ�ַ
	*@return
		*@BOOL				�Ƿ�ɹ�
	**************************************************************************/
	BOOL WrIOPort(IN USHORT IO_Port_Addr, IN USHORT IO_DataSize, IN ULONG IO_Data);

	/**************************************************************************
	*@Function				RdMemory
	*@brief					��ȡ�ڴ��ֵ
	*@author				��˶
	*@param
		*@IO_Port_Addr		IN ����Memory�ĵ�ַ
		*@IO_DataSize		IN Memory ������ݵĴ�С 1��2��4��8��16��32bits��
		*@IO_Data			OUT �����Memory�е�ֵ
	*@return
		*@BOOL				�Ƿ�ɹ�
	***************************************************************************/
	BOOL RdMemory(IN ULONGLONG Memory_Addr, IN USHORT Mem_DataSize, OUT DWORD& Memory_Data);
	
	/***************************************************************************
	*@Function				WrMemory
	*@brief					д���ڴ��ֵ
	*@author				��˶
	*@param
		*@IO_Data			IN ����Memory��ֵ
		*@IO_DataSize		IN Memory ������ݵĴ�С 1��2��4��8��16��32bits��
		*@IO_Port_Addr		IN ����Memory�ĵ�ַ
	*@return
		*@BOOL				�Ƿ�ɹ�
	******************************************************************************/
	BOOL WrMemory(IN ULONGLONG Memory_Addr, IN USHORT Mem_DataSize, IN DWORD Memory_Data);

	/*************************************************
	*@Function				ReadPci
	*@brief					��PCI���ÿռ������
	*@author				��˶
	*@param
		*@bus				IN ����bus��ֵ
		*@dev				IN ����dev��ֵ
		*@func				IN ����func��ֵ
		*@pci_config		OUT ���Pci���ÿռ������
	*@return
		*@BOOL				�Ƿ�ɹ�
	**************************************************/

	BOOL ReadPci(IN USHORT bus, IN USHORT dev, IN USHORT func, OUT PCI_COMMON_CONFIG& pci_config);

	/*************************************************
	*@Function				WritePci
	*@brief					дPCI���ÿռ������
	*@author				��˶
	*@param
		*@bus				IN ����bus��ֵ
		*@dev				IN ����dev��ֵ
		*@func				IN ����func��ֵ
		*@offset			IN ����Ҫд��ƫ������ֵ
		*@Data				IN ����Ҫд�����ݵ�ֵ
	*@return
		*@BOOL				�Ƿ�ɹ�
	**************************************************/
	BOOL WritePci(IN USHORT bus, IN USHORT dev, IN USHORT func, IN UCHAR offset, IN ULONG Data);

	/*************************************************
	*@Function				ReadAllPci
	*@brief					��ȫ��PCI���ÿռ������
	*@author				��˶
	*@param
	*@return
	*@�洢λ��			���е�Pci_Config_space����
	**************************************************/
	BOOL ReadAllPci();

	/*********************************************************
	*@Function					Pci_All_Config_Space
	*@brief						����pci Config Space ȫ����Ϣ
	*@author					��˶
	*@param
	*@return
		Pci_All_Config_Space	PCI Config Space ȫ����Ϣ
	*********************************************************/
	const Pci_All_Config_Space& ReturnPCIConfigSpace();

	/**************************************************
	*@Function					GetECData
	*@brief						��ȡEC����Ϣ
	*@author					��˶
	*@param
	*@Embedded_Controller_Data	OUT EC 256�ֽڵ���Ϣ
	*@return
	*@BOOL						��ȡ�Ƿ�ɹ�
	***************************************************/
	BOOL GetECData(Embedded_Controller_Data& EC_Data);

	/***************************************************
	*@Function					SetECData
	*@brief						����EC����Ϣ
	*@author					��˶
	*@param
	*@EC_Addr					IN Ҫ���õ�EC�ĵ�ַ
	*@EC_Write_Data				IN Ҫ���õ�EC������
	*@return
	*@BOOL						�����Ƿ�ɹ�
	****************************************************/
	BOOL SetECData(BYTE EC_Addr, BYTE EC_Write_Data);

private:
	/*****************************************************************
	*@Function				CRing0_Initialize
	*@brief					��CRing0�������г�ʼ��
	*@author				��˶
	*@param					��
	*@return
		*@TRUE				��ʼ�����
		*@Others			��ȡʧ�ܣ����ص��Ǵ�����룬GetLastError()��
	******************************************************************/
	BOOL CRing0_Initialize();

	/****************************************************
	*@Function				CRing0_Destory
	*@brief					��CRing0���������˳�ʱ����
	*@author				��˶
	*@param					��
	*@return
		*@TRUE				�豸����ر����
	****************************************************/
	BOOL CRing0_Destory();

	/*************************************************************
	*@Function					find_location
	*@brief						Ѱ���ַ�����ʸ���е�λ��
	*@author					��˶
	*@param
		*@vecIntegerArray		����ʸ��
		*@search_string			����ҪѰ�ҵ��ַ���
	*@return
		*@INT64					�����ַ�����ʸ����λ�� -1����δ�ҵ�
	*************************************************************/
	template<class T>
	INT64 find_location(std::vector<T> vecIntegerArray, std::string search_string);
	explicit CRing0(const CRing0& x);
	CRing0& operator=(const CRing0& x);

public:
	USHORT  VendorID;		//�豸����Vendor
protected:
	HANDLE hdevice;			//�豸���
	TCHAR*  G_DevicePath;	//�豸��������
private:
	Pci_All_Config_Space Pci_Config_space; //PCI���ÿռ������
};