/**

*Copyright (C), 2017-.

*@file CPUID For Intel.h���洢��ʽ��UNICODE

*@brief ��ȡIntel��CPUID��Ϣ

*@author ��˶

*@version 1.0

*@date 2017.9.21

*@History: �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���

*<p>ʱ�� �汾 ���� ˵��</p>

*/

#pragma once
#include "CPUIDinfo.h"
/**

*@class Get_Info_For_Intel �����ļ�CPUID For Intel.h "~/CPUID For Intel.h"

*@author ��˶

*@brief ��ȡIntel����Ϣ

*<br>

*��CPUID��Intel���ֲ���н�����

*/
class Get_Info_For_Intel : virtual public Get_cpuid, private UnCopyable
{
public:
	Get_Info_For_Intel();
	~Get_Info_For_Intel();
	/**

	*@brief ����CPUID����Ϣ

	*@author ��˶

	*@param

	*@CPUID_Index		CPUID������

	*@EAX				����EAX��ֵ

	*@EBX				����EBX��ֵ

	*@ECX				����ECX��ֵ

	*@EDX				����EDX��ֵ

	*@return ��

	*/

	CPU_RES Return_CPUID() const;//IN ULONGLONG CPUID_Index, OUT int& EAX, OUT int& EBX, OUT int& ECX, OUT int& EDX

	/**

	*@brief ���ؽ��������Ϣ

	*@author ��˶

	*@param ��

	*@return ��

	*/

	CPUID_Data Return_info() const;

	/**

	*@brief				����CPUID��ֵ �̳���Get_cpuid����

	*@author			��˶

	*@param				��

	*@return			��

	*/
	void UPdate();

private:

	/**

	*@brief ����Intel CPUID�ĺ���

	*@author ��˶

	*@param ��

	*@return ��

	*/
	void excute_CPUID_FOR_Intel();
	/**

	*@brief ��ȡȫ����CPUID

	*@author ��˶

	*@param ��

	*@return

	*@TRUE ��ȡ���

	*@FALSE ��ȡʧ��

	*/
	bool Get_ALL_CPUID();

	/**

	*@brief				����CPUID�����ŵ�����Ԫ���±�

	*@author			��˶

	*@param

	*@vecIntegerArray	Ҫ��ѯ���ַ�����

	*@search_string		Ҫ��ѯ���ַ���

	*@return

	*@>0				���صĵ�ǰѰ�ҵ�λ����Ϣ

	*@-1				��ȡʧ�ܣ�û�������Ϣ

	*/
	int find_location(vector<wstring> vecIntegerArray, wstring search_string);

	/**

	*@brief				��ȡCPUID=1ʱ֧�ֵ�ָ�

	*@author			��˶

	*@param

	*@ECX				Ҫ��ѯECX��ֵ

	*@EDX				Ҫ��ѯEDX��ֵ

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/
	bool GET_FEATURE_INFO(IN int ECX, IN int EDX);

	/**

	*@brief				��ȡCPU�ļܹ�����Ϣ

	*@author			��˶

	*@param

	*@DF_DM				����DF_DM��ȷ��CPU�ļܹ�

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/
	BOOL DF_DM_info(IN UINT DF_DM);

	/**

	*@brief				��ȡCPUID=2ʱCache��������

	*@author			��˶

	*@param

	*@cacheinfo			�������Cache8λ����

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/

	void cache_Descriptors(IN unsigned char cacheinfo, vector<wstring>& Cache_Temp);
	/**

	*@brief				��ȡCPUID=6ʱ֧�ֵ�ָ�

	*@author			��˶

	*@param

	*@ECX				Ҫ��ѯECX��ֵ

	*@EBX				Ҫ��ѯEBX��ֵ

	*@EAX				Ҫ��ѯEAX��ֵ

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/

	bool GET_Power_Mgmt_INFO(IN int EAX, IN int EBX, IN int ECX);

	/**

	*@brief				��ȡCPUID=7ʱ֧�ֵ���չָ�

	*@author			��˶

	*@param

	*@ECX				Ҫ��ѯECX��ֵ

	*@EDX				Ҫ��ѯEDX��ֵ

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/
	bool GET_EXTENED_FEATURE_INFO(IN int ECX, IN int EDX);

	/**

	*@brief				��ȡCPUID=0Aʱ���ܼ��ļܹ�

	*@author			��˶

	*@param

	*@EAX				Ҫ��ѯEAX��ֵ

	*@EBX				Ҫ��ѯEBX��ֵ

	*@EDX				Ҫ��ѯEDX��ֵ

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/
	bool GET_ARCHITECTURAL_PERFORMANCE_MONITORING(IN int EAX, IN int EBX, IN int EDX);

	/**

	*@brief				��ȡCodeName

	*@author			��˶

	*@param

	*@CPUName			����CodeName��ֵ

	*@return

	*@TRUE				��ȡ���

	*@FALSE				��ȡʧ��

	*/
	bool GET_CODENAME(const string& CPUName);
	/**

	*@brief				��ȡCore�µ�CodeName

	*@author			��˶

	*@param

	*@model				����CPU���ͺ�

	*@return

	*@string			CPU�ܹ�����

	*/
	string Core_CodeName(const string & model);

	void Information_from_WMI();

	void Information_from_CPUID0();

	void Information_from_CPUID1();

	void Information_from_CPUID2();

	void Information_from_CPUID3();

	void Information_from_CPUID4();

	void Information_from_CPUID5();

	void Information_from_CPUID6();

	void Information_from_CPUID7();

	void Information_from_CPUIDA();

	void Information_from_CPUIDB();

	void Information_from_CPUIDC();

	void Information_from_CPUIDD();

public:
protected:
private:
	/**

	@brief ����CPUID����ֵ�Ľṹ

	*/

	CPU_RES Intel_cpuRegister;
	/**

	@brief ����������CPUID��Ϣ�ṹ

	*/
	CPUID_Data Intel_Data;

	int mposition;

	enum Microarchitecture
	{
		Unknown = 0,
		Core,
		Xeon,
		Itanium,
	};
};
