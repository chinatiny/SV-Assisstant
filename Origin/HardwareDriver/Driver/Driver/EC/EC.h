#pragma once
/*************************************************
Copyright: 2017 Zhaoxin BJ-SV
Author:��˶
Date:2017-12-13
Description: ��ȡEmbedded Controller����Ϣ
**************************************************/
#include "../MyDriverClass.h"
#define		EC_SC					0x66
#define		EC_DATA					0x62
#define		RD_EC					0x80
#define		WR_EC					0x81
#define		BE_EC					0x82
#define		BD_EC					0x83
#define		QR_EC					0x84

//EC Data ��256���ֽ� ����ÿһλ����ʲô��Ҫ��Ӧ��spec��ȷ��
typedef struct _Embedded_Controller_Data
{
	BYTE	Data[256];
}Embedded_Controller_Data;

/**************************************************
*@Function					GetECData
*@brief						��ȡEC����Ϣ
*@author					��˶
*@param
	*@Embedded_Controller_Data	OUT EC 256�ֽڵ���Ϣ
*@return
	*@BOOL						��ȡ�Ƿ�ɹ�
***************************************************/
BOOL GetECData(Embedded_Controller_Data& EC_Data);

/***************************************************
*@Function					SetECData
*@brief						����EC����Ϣ
*@author					��˶
*@param
	*@EC_Addr					IN Ҫ���õ�EC�ĵ�ַ
	*@EC_Write_Data				IN Ҫ���õ�EC������
*@return
*@BOOL						�����Ƿ�ɹ�
****************************************************/
BOOL SetECData(BYTE EC_Addr, BYTE EC_Write_Data);