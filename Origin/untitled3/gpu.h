#pragma once
/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-12-13
Description: ��ȡGPU����Ϣ
**************************************************/
namespace SV_ASSIST
{
	namespace GPU
	{
		enum FanTypes
		{
			Percent = 0,
			RPM = 1
		};

		/**************************************************************
		*@Function				GPUName
		*@brief					��ȡ�Կ�������
		*@author				��˶
		*@param
		*@null
		*@return
		*@string			�Կ�����
		****************************************************************/
		const std::string GPUName();
		/**************************************************************
		*@Function				GPUBIOSVersion
		*@brief					��ȡ�Կ�BIOS��Ϣ
		*@author				��˶
		*@param
		*@null
		*@return
		*@string			�Կ�BIOS��Ϣ
		****************************************************************/
		const std::string GPUBIOSVersion();

		/**************************************************************
		*@Function				GPUtemperature
		*@brief					��ȡ�Կ��¶�
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�Կ��¶�
		****************************************************************/
		double GPUtemperature();
		/**************************************************************
		*@Function				GPUFans
		*@brief					��ȡ�Կ�����ת��
		*@author				��˶
		*@param
		*@FanTypes			IN_OUT	AMD������RPMorPer �ж�������;�������ֵ���ͣ�Nvidia����ֵ��Ч�����ط��ȵ�RPM
		*@return
		*@int				����ת��
		****************************************************************/
		int GPUFans(FanTypes & type);

		/**************************************************************
		*@Function				GPUCurrentClock
		*@brief					��ȡ�Կ�Ƶ��
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�Կ�Ƶ�� MHz
		****************************************************************/
		double GPUCurrentClock();

		/**************************************************************
		*@Function				GPUMemoryClock
		*@brief					��ȡ�Դ�Ƶ��
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�Դ�Ƶ�� MHz
		****************************************************************/
		double GPUMemoryClock();

		/**************************************************************
		*@Function				GPUPhysicalMemory
		*@brief					��ȡ�Դ��С(N������ A�����о�)
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�Դ��С
		****************************************************************/
		double GPUPhysicalMemory();

		/**************************************************************
		*@Function				GPUVirtualMemory
		*@brief					��ȡ�����Դ��С(N������)
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�����Դ��С
		****************************************************************/
		double GPUVirtualMemory();

		/**************************************************************
		*@Function				GetGPUAvailableMemory
		*@brief					��ȡ�����Դ�
		*@author				��˶
		*@param
		*@null
		*@return
		*@double			�����Դ��С
		****************************************************************/
		double GetGPUAvailableMemory();

		/**************************************************************
		*@Function				GetGPUUsasge
		*@brief					��ȡ�Կ�ʹ����
		*@author				��˶
		*@param
		*@null
		*@return
		*@int				�Կ�ʹ����(%)
		****************************************************************/
		int GetGPUUsasge();
		/**************************************************************
		*@Function				GetGPUMemoryControlUsasge
		*@brief					��ȡ�Դ�ʹ����(N������)
		*@author				��˶
		*@param
		*@null
		*@return
		*@int				�Դ�ʹ����
		****************************************************************/
		int GetGPUMemoryControlUsasge();
		/**************************************************************
		*@Function				GetGPUVideoEngineUsasge
		*@brief					��ȡ�Կ�Frame Bufferʹ����(N������)
		*@author				��˶
		*@param
		*@null
		*@return
		*@int				ʹ����
		****************************************************************/
		int GetGPUVideoEngineUsasge();
		/**************************************************************
		*@Function				UpdateDate
		*@brief					�����Կ���Ϣ
		*@author				��˶
		*@param
		*@null
		*@return
		*@null
		****************************************************************/
		void UpdateDate();
	}
}



