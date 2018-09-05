//#include "stdafx.h"
#include "PCI defination.h"
#include <tchar.h>

BOOL openpci(const TCHAR * filename, ios_base::openmode mode, const USHORT VendorID, wstring& VendorString)
{
	TCHAR* tmp = new TCHAR[1024];
	ULONG tmpVendorId = 0;
	size_t ipos = 0;
	wstring tmpVendorString = _T("");
	wstring FileString = _T("");
	::ZeroMemory(tmp, 1024);
	wifstream in;
	in.open(filename, mode);
	if (!in.is_open())
	{
		OutputDebugString(_T("���ļ�ʧ��"));
		return FALSE;
	}
	while (in.getline(tmp, 1024))
	{
		if (*tmp == ';' || *tmp == '[' || *tmp == '#' || *tmp == NULL)		continue;
		FileString = tmp;
		if (*tmp == '\t')
		{
			continue;
			// Its DeviceID or SubVendorID
		}
		swscanf_s(tmp, _T("%x  "), &tmpVendorId);
		ipos = FileString.find(_T("  "));
		tmpVendorString = FileString.substr(ipos + 1, FileString.size());
		if (tmpVendorId == VendorID)
		{
			VendorString = tmpVendorString;
			break;
		}
		tmpVendorString = _T("");
		FileString = _T("");
		::ZeroMemory(tmp, 1024);
	}
	in.close();
	if (tmp)
	{
		delete[] tmp;
		tmp = NULL;
	}
	if (VendorString == _T(""))		return FALSE;
	return TRUE;
}



