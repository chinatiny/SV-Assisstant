#pragma once
#include "cpulibdefination.h"
namespace SV_ASSIST
{
	namespace CPU
	{
		/**************************************************************
		*@Function				GetCPUName
		*@brief					��ȡCPU������(Brand Name)
		*@author				��˶
		*@param
		*@
		*@return
		*@string			CPU����
		****************************************************************/
		const std::string& GetCPUName();
		/**************************************************************
		*@Function				GetProcessorID
		*@brief					��ȡ��������ID
		*@author				��˶
		*@param
		*@
		*@return
		*@string			CPU ID
		****************************************************************/
		const std::string& GetProcessorID();
		/**************************************************************
		*@Function				GetSocketDesignation
		*@brief					��ȡ�������ķ�װ��ʽ
		*@author				��˶
		*@param
		*@x
		*@return
		*@string
		****************************************************************/
		const std::string& GetSocketDesignation();

		//���ܻ���� ����MSR��ʽ
		/**************************************************************
		*@Function				GetCurrentClockSpeed
		*@brief					��ȡ�����������Ƶ�ʣ�WMI ���ܲ�׼ȷ��
		*@author				��˶
		*@param
		*@null
		*@return
		*@UINT				������Ƶ��
		****************************************************************/
		const unsigned int GetCurrentClockSpeed();

		//���ܻ����������MSR��ʽ
		/**************************************************************
		*@Function				GetExtClock
		*@brief					��ȡ��������Bus Speed
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint				��������Ƶ
		****************************************************************/
		const unsigned int GetExtClock();

		/**************************************************************
		*@Function				GetCore
		*@brief					��ȡ�����������������
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint				���������
		****************************************************************/
		const unsigned int GetCore();

		/**************************************************************
		*@Function				GetThread
		*@brief					��ȡ���������߳���
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint				�������߳���
		****************************************************************/
		const unsigned int GetThread();

		//����MSR��ʽ δ��
		/**************************************************************
		*@Function				GetRevision
		*@brief					��ȡ���������޶��汾
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint				���������޶��汾
		****************************************************************/
		const unsigned int GetRevision(); //δ��

		//���ܻ���� ����msr��ʽ
		/**************************************************************
		*@Function				GetMaxClockSpeed
		*@brief					��ȡ�����������ʱ��
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint				���ʱ��
		****************************************************************/
		const unsigned int GetMaxClockSpeed();


		/**************************************************************
		*@Function				GetUpgradeMethod
		*@brief					��ȡ�������ķ�װ��ʽ
		*@author				��˶
		*@param
		*@null
		*@return
		*@uint
		****************************************************************/
		const unsigned int GetUpgradeMethod();

		/**************************************************************
		*@Function				GetManufacturer
		*@brief					��ȡ�������ĳ���ID
		*@author				��˶
		*@param
		*@null
		*@return
		*@string			����������
		****************************************************************/
		const std::string& GetManufacturer();

		/**************************************************************
		*@Function				GetFamily
		*@brief					��ȡ��������Family
		*@author				��˶
		*@param
		*@null
		*@return
		*@short				����������
		****************************************************************/
		const short GetFamily();

		/**************************************************************
		*@Function				GetModel
		*@brief					��ȡ��������Model
		*@author				��˶
		*@param
		*@
		*@return
		*@short				Model
		****************************************************************/
		const short GetModel();
		/**************************************************************
		*@Function				GetSocketDesignation
		*@brief					��ȡ�������ķ�װ��ʽ
		*@author				��˶
		*@param
		*@x					OUT �Լ�����õ������С�ռ�һ����������Ҫ��16�ֽ�
		*@return
		*@Null
		****************************************************************/
		const short GetStepping();
		/**************************************************************
		*@Function				GetExtFamily
		*@brief					��ȡ��������Ext.Family
		*@author				��˶
		*@param
		*@null
		*@return
		*@short				Ext.Family
		****************************************************************/
		const short GetExtFamily();
		/**************************************************************
		*@Function				GetExtModel
		*@brief					��ȡ��������Ext.Model
		*@author				��˶
		*@param
		*@null
		*@return
		*@short				Ext.Model
		****************************************************************/
		const short GetExtModel();
		/**************************************************************
		*@Function				GetFeature
		*@brief					��ȡ������������
		*@author				��˶
		*@param
		*@null
		*@return
		*@CPUFeature		������֧�ֵ�����
		****************************************************************/
		const CPUFeature& GetFeature();

		/**************************************************************
		*@Function				GetCache
		*@brief					��ȡ��������Cache
		*@author				��˶
		*@param
		*@
		*@return
		*@Cache_info		һ����������Cache(��û3����Ҫ�Լ��ж�)
		****************************************************************/
		const Cache_info* GetCache();
	}
}

