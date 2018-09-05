// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CPU_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CPU_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CPU_EXPORTS
#define CPU_API __declspec(dllexport)
#else
#define CPU_API __declspec(dllimport)
#endif

#include <windows.h>
#include "CPU/definition.h"

// �����Ǵ� CPU.dll ������
class CPU_API CCPU {
public:
	CCPU(void);
	// TODO:  �ڴ�������ķ�����	
	virtual void Excute(CPUID_Data* buffer, ULONG& buffer_size) = 0;
	virtual void Get_CPUID(CPU_RES* Data) = 0;
	virtual CPUID_Data Excute() = 0;

};
extern "C"
{
	CPU_API CCPU* Instantiate(void);
	CPU_API void Free(CCPU* pBase);
}





