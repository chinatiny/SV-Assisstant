// CPU.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "../CPU/CPU/CPUIDForIntel.h"
#include "../CPU/CPU/CPUIDForAMD.h"
#include "CPU.h"


//�����ǵ������ʵ��
class CCPU_info : public CCPU
{
public:
	CCPU_info();
	~CCPU_info();
protected:
	void Excute(CPUID_Data* buffer, ULONG& buffer_size);
	void Get_CPUID(CPU_RES* Data);
	CPUID_Data Excute();
private:
	shared_ptr<Get_cpuid> info;
};

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� CPU.h

CCPU::CCPU()
{
    return;
}

CCPU_info::CCPU_info()
{
	switch (info->Judge_CPU_Brands())
	{
	case ZhaoXin:
	case Intel:
		info = make_shared<Get_Info_For_Intel>();
		break;
	case AMD:
		info = make_shared<Get_Info_For_AMD>();
		break;
	case Others:
		break;
	}
}

CCPU_info::~CCPU_info()
{
}

void CCPU_info::Excute(CPUID_Data* buffer, ULONG& buffer_size)
{
	if(info)
	{
		info->UPdate();
		CPUID_Data temp = info->Return_info();
		buffer_size = sizeof(temp);
		memcpy(buffer, &temp, sizeof(temp));
	}
}

void CCPU_info::Get_CPUID(CPU_RES* Data)
{
	if (info)
	{
		CPU_RES temp = info->Return_CPUID();
		memcpy(Data, &temp, sizeof(temp));
	}
}

CPUID_Data CCPU_info::Excute()
{
	info->UPdate();
	return info->Return_info();
}

extern "C" CPU_API CCPU* Instantiate()
{
	return new CCPU_info;
}

extern "C" CPU_API void Free(CCPU* pBase)
{
	delete pBase;
	pBase = nullptr;
}