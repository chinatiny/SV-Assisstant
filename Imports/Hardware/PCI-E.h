#pragma once

/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-12-13
Description: ��ȡPCIE CFG����Ϣ
**************************************************/
namespace SV_ASSIST
{
	namespace PCIE
	{
		/**************************************************************
		*@Function				GetPCIEConfigSpace
		*@brief					��ȡPCIE Configuration Space
		*@author				��˶
		*@param
			*@PCIE_BaseAddress	IN PCIE�ڴ��ַ
			*@Data				INOut PCIE���ÿռ�����
			*@DataSize			INOut PCIE���ÿռ��С4096
		*@return
			*@BOOL				��ȡConfiguration Space�Ƿ�ɹ�
		****************************************************************/
		BOOL GetPCIEConfigSpace(const ULONGLONG PCIE_BaseAddress, ULONG bus, ULONG dev, ULONG func, PVOID& Data, size_t DataSize);

		/***************************************************
		*@Function					GetPCIVendorName
		*@brief						��ȡPci������
		*@author					��˶
		*@param
			*@VenderID				����ID��
			*@VenderName			���������
		*@return
			*null
		****************************************************/
		BOOL GetPCIVendorName(const USHORT VenderID, std::string & VenderName);

		/***************************************************
		*@Function					GetPCIDeviceName
		*@brief						��ȡPci������&�豸��
		*@author					��˶
		*@param
			*@VenderID				����ID��
			*@DeviceID				�豸ID��
			*@VenderName			���������
			*@DeviceName			����豸��
		*@return
			*null
		****************************************************/
		BOOL GetPCIDeviceName(const USHORT VenderID, const USHORT DeviceID, std::string& VenderName, std::string& DeviceName);

		/***************************************************
		*@Function					ExecPCIClassCode
		*@brief						����Pci�豸��classcode
		*@author					��˶
		*@param
			*@data					256Bytes��pci���ÿռ��С
			*@DeviceType			����������class code����ֵ
		*@return
			*null
		****************************************************/
		BOOL ExecPCIClassCode(const PCI_COMMON_CONFIG &data, std::string& DeviceType);

		/***************************************************
		*@Function					GetPciSpeed
		*@brief						��ȡPci�豸�ٶ�(Gen123 x16-2)
		*@author					��˶
		*@param
			*@data					pci�豸���ÿռ���Ϣ
			*@MAXSpeed				��������ٶ�
			*@CurrentSpeed			��ǰ�����ٶ�
		*@return
			*null
		****************************************************/
		BOOL GetPciSpeed(const PCI_COMMON_CONFIG &data, PCISPEED& MAXSpeed, PCISPEED& CurrentSpeed);

		/***************************************************
		*@Function					PCIstringToBDF
		*@brief						pci�ַ�ת����bus dev func
		*@author					��˶
		*@param
			*@pcistring				�����pci�ַ���
			*@bus					����bus��
			*@dev					����dev��
			*@func					����func��
		*@return
			*@BOOL					�Ƿ�ɹ�
		****************************************************/
		const BOOL PCIstringToBDF(const std::wstring& pcistring, ULONG &bus, ULONG &dev, ULONG &func);

		/***************************************************
		*@Function					GetPCIOptionROM
		*@brief						��ȡPCI Option ROM����Ϣ
		*@author					��˶
		*@param
		*@return
			*@						Option ROM����Ϣ
		****************************************************/
		const std::vector<std::pair<PCI_OPTION_ROM_HEADER, PCI_OPTION_ROM_Data_Structure>>& GetPCIOptionROM();

		/***************************************************
		*@Function					UpdateData
		*@brief						����PCI Option ROM����Ϣ
		*@author					��˶
		*@param
		*@return
		****************************************************/
		void UpdateData();
	}
}
