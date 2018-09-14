// stdafx.cpp : ֻ������׼�����ļ���Դ�ļ�
// sv-assistant.pch ����ΪԤ����ͷ
// stdafx.obj ������Ԥ����������Ϣ

#include "stdafx.h"

// TODO: �� STDAFX.H �������κ�����ĸ���ͷ�ļ���
//�������ڴ��ļ�������
#ifdef _DEBUG
void OutputDebugPrintf(const TCHAR* strOutputString, ...)
{
	TCHAR strBuffer[4096] = { 0 };
	va_list vlArgs;
	va_start(vlArgs, strOutputString);
#ifdef UNICODE
	_vsnwprintf_s(strBuffer, 4095, strOutputString, vlArgs);
#else
	_vsnprintf_s(strBuffer, 4095, strOutputString, vlArgs);
#endif
	//vsprintf(strBuffer,strOutputString,vlArgs);
	va_end(vlArgs);
#ifdef ZX_OutputLog
	Logger::Instance()->OutputLogInfo(el::Level::Debug, strBuffer);
#endif
#ifdef UNICODE
	wcscat_s(strBuffer, 4095,L"\n");
#else
	strcat_s(strBuffer, 4095, "\n");
#endif
	OutputDebugString(strBuffer);
}
#else
void OutputDebugPrintf(const TCHAR* strOutputString, ...) 
{
#ifdef ZX_OutputLog
	TCHAR strBuffer[4096] = { 0 };
	va_list vlArgs;
	va_start(vlArgs, strOutputString);
#ifdef UNICODE
	_vsnwprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
#else
	_vsnprintf_s(strBuffer, sizeof(strBuffer) - 1, strOutputString, vlArgs);
#endif
	//vsprintf(strBuffer,strOutputString,vlArgs);
	va_end(vlArgs);
	Logger::Instance()->OutputLogInfo(el::Level::Debug, strBuffer);
#endif
}
#endif

