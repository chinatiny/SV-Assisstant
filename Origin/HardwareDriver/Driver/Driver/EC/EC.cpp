#include "EC.h"

BOOL GetECData(Embedded_Controller_Data & EC_Data)
{
	CRing0 ring0;
	DWORD64 Data = 0;
	for (USHORT i = 0; i < 0x100; i++)
	{
		ring0.RdIOPort(EC_SC, 1, Data);
		if (Data == 0x08)
		{
			ring0.WrIOPort(EC_DATA, 1, 0x00);	// ���ڶ�״̬ʱ��ɶ�ȡ״̬
		}
		ring0.RdIOPort(EC_SC, 1, Data);
		if (Data)
		{
			OutputDebugString("EC��������\n");
			return FALSE;
		}
		ring0.WrIOPort(EC_SC, 1, RD_EC);		// ��EC����Ϊ��״̬
		ring0.RdIOPort(EC_SC, 1, Data);
		if (Data != 0x08)
		{
			OutputDebugString("��ȡECʧ��!\n");
			return FALSE;
		}
		ring0.WrIOPort(EC_DATA, 1, i);
		ring0.RdIOPort(EC_DATA, 1, Data);
		memcpy_s(&EC_Data.Data[i], 1, &Data, 1);
	}
	return TRUE;
}

BOOL SetECData(BYTE EC_Addr, BYTE EC_Write_Data)
{
	CRing0 ring0;
	DWORD64 Data = 0;
	ring0.WrIOPort(EC_SC, 1, WR_EC);	//��EC����Ϊд״̬
	ring0.RdIOPort(EC_SC, 1, Data);
	if (Data != 0x08)		return FALSE;
	ring0.WrIOPort(EC_DATA, 1, EC_Addr);	//	����ַд��EC
	ring0.WrIOPort(EC_DATA, 1, EC_Write_Data);	//������д��EC
	return TRUE;
}
