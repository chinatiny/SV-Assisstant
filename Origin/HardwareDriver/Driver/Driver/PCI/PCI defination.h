#pragma once
#include "../MyDriverClass.h"
#include <fstream>

using namespace std;
//���ļ�

/**************************************************************
*@Function			openpci
*@brief				���ļ���ȡPCI Vendor Device string��Ϣ
*@author			��˶
*@param
	*@filename			IN Ҫ�ļ����򿪵�
	*@mode				�򿪵÷�ʽ ios::in ֻ��
	*@VendorID			IN ����Ŀ��Vendor
	*@VendorString		OUT ���VendorID��string����
*@return
	*@BOOL				��ȡ�Ƿ�ɹ�
****************************************************************/
BOOL openpci(const TCHAR * filename, ios_base::openmode mode, const USHORT VendorID, string& VendorString);