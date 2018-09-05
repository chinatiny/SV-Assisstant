/**

*Copyright (C), 2017-.

*@file CPUID For AMD.h���洢��ʽ��UNICODE

*@brief ��ȡAMD��CPUID��Ϣ

*@author ��˶

*@version 1.0

*@date 2017.9.22

*@History: �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���

*<p>ʱ�� �汾 ���� ˵��</p>

*/
#pragma once
#include "CPUIDinfo.h"
/**

*@class Get_Info_For_AMD �����ļ�CPUID For AMD.h "~/CPUID For AMD.h"

*@author ��˶

*@brief ��ȡAMD����Ϣ

*<br>

*��CPUID��AMD���ֲ���н�����

*/
class Get_Info_For_AMD : virtual public Get_cpuid, private UnCopyable
{
public:
	Get_Info_For_AMD();
	~Get_Info_For_AMD();
	/**

	*@brief ���ؽ��������Ϣ

	*@author ��˶

	*@param ��

	*@return ��

	*/
	CPUID_Data Return_info() const;

	/**

	*@brief ����ԭʼ�����Ϣ

	*@author ��˶

	*@param ��

	*@return ��

	*/
	CPU_RES Return_CPUID() const;

	/**

	*@brief				����CPUID��ֵ �̳���Get_cpuid����

	*@author			��˶

	*@param				��

	*@return			��

	*/
	void UPdate();

private:

	/**

	*@brief ����AMD CPUID = 1�ĺ���

	*@author ��˶

	*@param ��

	*@return

	*@TRUE ��ȡ���

	*@FALSE ��ȡʧ��

	*/
	bool AMD_Get_Standard_Feature(int ECX, int EDX);

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

	*@brief ����AMD CPUID = 0x80000001�ĺ���

	*@author ��˶

	*@param ��

	*@return

	*@TRUE ��ȡ���

	*@FALSE ��ȡʧ��

	*/
	bool AMD_Get_Extended_Feature(int ECX, int EDX);
	int find_location(vector<wstring> vecIntegerArray, wstring search_string);
	/**

	*@brief ����AMD CPUID�ĺ���

	*@author ��˶

	*@param ��

	*@return

	*@TRUE ��ȡ���

	*@FALSE ��ȡʧ��

	*/
	bool excute_CPUID_FOR_AMD();
private:
	/**

	@brief ����������CPUID��Ϣ�ṹ

	*/
	CPUID_Data AMD_Data;
	/**

	@brief ����CPUID����ֵ�Ľṹ

	*/

	CPU_RES AMD_cpuRegister;
};