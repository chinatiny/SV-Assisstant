#pragma once

typedef struct _HANDLEENTRY
{
	UINT64  phead;
	UINT64  pOwner;
	UCHAR   bType;
	UCHAR   bFlags;
	USHORT  wUniq;
}HANDLEENTRY, *PHANDLEENTRY;

typedef struct _HOOK_INFO
{
	HANDLE       hHandle;                    //���ӵľ��   �����ȫ�ֵ� ����UnhookWindowsHookEx  �ѹ���ж��  
	int          Unknown1;
	PVOID        Win32Thread;                 //һ��ָ�� win32k!_W32THREAD �ṹ���ָ��  
	PVOID        Unknown2;
	PVOID        SelfHook;                   //ָ��ṹ����׵�ַ  
	PVOID        NextHook;                   //ָ����һ�����ӽṹ��  
	int          iHookType;                 //���ӵ����ͣ� winuser.h ���ж���  
	PVOID        OffPfn;                    //���Ӻ����ĵ�ַƫ�ƣ����������ģ���ƫ��  
	int          iHookFlags;
	int          iMod;                      //���Ӻ�������ģ����������룬ͨ����ѯ WowProcess �ṹ���Եõ�ģ��Ļ���ַ��  
	PVOID        Win32ThreadHooked;         // �������������̵߳Ľṹָ�룬��֪��  
											//���滹�У�ʡ�ԡ�����  
} HOOK_INFO, *PHOOK_INFO;

NTSTATUS MsgHook_GetAddress(WDFREQUEST Request, size_t InputBufferLength, size_t OutputBufferLength);

NTSTATUS VxkCopyMemory(PVOID pDestination, PVOID pSourceAddress, SIZE_T SizeOfCopy);