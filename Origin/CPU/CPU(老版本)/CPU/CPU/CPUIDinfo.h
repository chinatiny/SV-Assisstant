/**

*Copyright (C), 2017-.

*@file CPUIDinfo.h���洢��ʽ��UNICODE

*@brief ��ȡCPUID��Ϣ

*@author ��˶

*@version 1.0

*@date 2017.9.21

*@History: �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸��߼��޸����ݼ���

*<p>ʱ�� �汾 ���� ˵��</p>

*/
#pragma once

#include "definition.h"
#include<sstream>
/**

*@class Get_cpuid �����ļ���CPUIDinfo.h "~/CPUIDinfo.h"

*@author ��˶

*@brief ��ȡCPUIDֵ

*/

class Get_cpuid
{


protected:
/**

*@brief ��ȡCPUID��ֵ

*@param

*@param[OUT] buffer				EAX��EBX��ECX��EDX�е�ֵ

*@param[IN] function_id			��Ҷֵ����ŵ�EAX�У�Ĭ��Ϊ0

*@param[IN] subfunction_id		��Ҷֵ����ŵ�ECX�У�Ĭ��Ϊ0

*@return

*@GET_CPUID_SUCCESS		��ȡCPUIDֵ�ɹ�

*@ILLEGAL_OPERAND		�����˷Ƿ��Ĳ�����

*@FAILED_TO_GET_INFO	��ȡCPUIDֵʧ��

*/
	ERROR_CODE Read_CPUID(OUT int buffer[4], IN size_t function_id = 0, IN size_t subfunction_id = 0);


public:
	Get_cpuid();
	virtual ~Get_cpuid();
/**

*@brief �ж�CPU��Ʒ��

*@param ��

*@return

*@Intel �����ض���CPU

*@AMD ��AMD��CPU

*@ZhaoXin ����о��CPU

*@Others ������Ʒ�Ƶĵ�CPU��������֮��

*@FAILED ��ȡCPUID��Ʒ��ʧ��

*/
	CPU_Brands Judge_CPU_Brands();
/**

*@brief				����CPUID��ֵ

*@author			��˶

*@param				��

*@return			��

*/
	virtual void UPdate() = 0;
/**

*@brief				���ؽ�����CPUID��ֵ

*@author			��˶

*@param				��

*@return			��

*/
	virtual CPUID_Data Return_info() const = 0;

/**

*@brief				����ԭʼ��CPUID��ֵ

*@author			��˶

*@param				��

*@return			��

*/
	virtual CPU_RES Return_CPUID() const = 0;
protected:
/**

@brief ����CPUID����ʱ�ṹ

*/
	int buffer[4];
private:
	
};


