// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // �� Windows ͷ���ų�����ʹ�õ�����

#include <windows.h>
#include <tchar.h>
#include <string>
#include <memory>
#include <vector>
#include <map>
#include <string>
#include <array>
#include <bitset>
#include <iostream>
#include "..\..\driver\Defination\Ring0Defination.h"
#include "log/easylogging++.h"
#include "log/sv_log.h"
#include "boost/format.hpp"

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

void OutputDebugPrintf(const TCHAR* strOutputString, ...);
