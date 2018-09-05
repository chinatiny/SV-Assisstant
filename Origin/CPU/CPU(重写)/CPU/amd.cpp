#include "stdafx.h"
#include "amd.h"

using namespace std;

AMD::AMD() : f1_ecx{ 0 }, f1_edx{ 0 }, f7_ecx{ 0 }, f7_ebx{ 0 }, f81_ecx{ 0 }, f81_edx{ 0 }
{
}

AMD::~AMD()
{
}

void AMD::Init(void)
{
	array<int, 4> cpuid__;
	__cpuidex(cpuid__.data(), 0, 0);
	nIds_ = cpuid__[0];
	__cpuid(cpuid__.data(), 0x80000000);
	nExIds_ = cpuid__[0];
	for (int i = 0; i <= nIds_; i++)
	{
		int sub = 0;
		__cpuidex(cpuid__.data(), i, sub);
		data__.emplace_back(cpuid__);
		nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
		switch (i)
		{
		case 4:
			while (true)
			{
				__cpuidex(cpuid__.data(), i, ++sub);
				if ((cpuid__[0] & 0xf) == 0)
					break;
				else
				{
					data__.emplace_back(cpuid__);
					nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
				}
			}
			break;
		case 0x7:
			sub = cpuid__[0];
			for (int j = 1; j < sub; j++)
			{
				__cpuidex(cpuid__.data(), i, j);
				data__.emplace_back(cpuid__);
				nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | j);
			}
			break;
		case 0x0B:
			while (true)
			{
				__cpuidex(cpuid__.data(), i, ++sub);
				if ((cpuid__[2] & 0xff00) == 0)
					break;
				else
				{
					data__.emplace_back(cpuid__);
					nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
				}
			}
			break;
		case 0x0D:
			while (true)
			{
				__cpuidex(cpuid__.data(), i, ++sub);
				if (!cpuid__[0] && !cpuid__[1] && !cpuid__[2] && !cpuid__[3])
					break;
				else
				{
					data__.emplace_back(cpuid__);
					nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
				}
			}
			break;
		case 0x0F:
			__cpuidex(cpuid__.data(), i, 1);
			data__.emplace_back(cpuid__);
			nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | 1);
		case 0x10:
			for (int j = 1; j < 4; j++)
			{
				__cpuidex(cpuid__.data(), i, j);
				data__.emplace_back(cpuid__);
				nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | j);
			}
			break;
		case 0x12:
			__cpuidex(cpuid__.data(), i, ++sub);
			data__.emplace_back(cpuid__);
			nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
			while (true)
			{
				__cpuidex(cpuid__.data(), i, ++sub);
				if ((cpuid__[0] & 0xF) == 0x001B)
				{
					data__.emplace_back(cpuid__);
					nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
				}
				else
					break;

			}
			break;
		case 0x14:
			__cpuidex(cpuid__.data(), i, ++sub);
			data__.emplace_back(cpuid__);
			nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
			break;
		case 0x17:
			sub = cpuid__[0];
			for (int j = 1; j < sub; j++)
			{
				;
				__cpuidex(cpuid__.data(), i, j);
				data__.emplace_back(cpuid__);
				nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | j);
			}
			break;
		case 0x18:
			while (true)
			{
				__cpuidex(cpuid__.data(), i, ++sub);
				if (cpuid__[0] || (cpuid__[3] & 0xF))
					break;
				else
				{
					data__.emplace_back(cpuid__);
					nIdsLeaf.emplace_back((i << 16) | (i & 0xFFFF0000) | sub);
				}
			}
			break;
		default:
			break;
		}
	}
	for (int i = 0x80000000; i <= nExIds_; i++)
	{
		__cpuid(cpuid__.data(), i);
		extdata__.emplace_back(cpuid__);
	}
}

void AMD::UpDateData(void)
{
	char vendor[0x20];
	memset(vendor, 0, 0x20);
	*reinterpret_cast<int*>(vendor) = data__[0][1];
	*reinterpret_cast<int*>(vendor + 4) = data__[0][3];
	*reinterpret_cast<int*>(vendor + 8) = data__[0][2];
	Manufacturer = vendor;
	if (nIds_ > 1)
	{
		Family = (data__[1][0] & CPUID_Family) >> 8;
		Model = (data__[1][0] & CPUID_Model) >> 4;
		Stepping = (data__[1][0] & CPUID_Stepping) >> 0;
		ExtFamily = ((data__[1][0] & CPUID_Extended_Family) >> 20) + Family;
		ExtModel = (((data__[1][0] & CPUID_Extended_Model) >> 16) << 4) + Model;
		f1_ecx = data__[1][2];
		f1_edx = data__[1][3];
	}
	if (nIds_ > 7)
	{
		int t = findcpuid(0x00070000);
		if (t != -1)
		{
			f7_ecx = data__[t][2];
			f7_ebx = data__[t][1];
		}
	}
	if (nExIds_ > 1)
	{
		f81_ecx = extdata__[1][2];
		f81_edx = extdata__[1][3];
	}
	ExecFeature();

	ExecCache();
}

void AMD::ExecFeature()
{
	Feature.AMDFeature.SSE3 = f1_ecx[0];
	Feature.AMDFeature.PCLMULQDQ = f1_ecx[1];
	Feature.AMDFeature.MONITOR = f1_ecx[3];
	Feature.AMDFeature.SSSE3 = f1_ecx[9];
	Feature.AMDFeature.FMA = f1_ecx[12];
	Feature.AMDFeature.CMPXCHG16B = f1_ecx[13];
	Feature.AMDFeature.SSE41 = f1_ecx[19];
	Feature.AMDFeature.SSE42 = f1_ecx[20];
	Feature.AMDFeature.POPCNT = f1_ecx[23];
	Feature.AMDFeature.AES = f1_ecx[25];
	Feature.AMDFeature.XSAVE = f1_ecx[26];
	Feature.AMDFeature.OSXSAVE = f1_ecx[27];
	Feature.AMDFeature.AVX = f1_ecx[28];
	Feature.AMDFeature.F16C = f1_ecx[29];
	Feature.AMDFeature.RDRAND = f1_ecx[30];

	Feature.AMDFeature.FPU = f1_edx[0];
	Feature.AMDFeature.VME = f1_edx[1];
	Feature.AMDFeature.DE = f1_edx[2];
	Feature.AMDFeature.PSE = f1_edx[3];
	Feature.AMDFeature.TSC = f1_edx[4];
	Feature.AMDFeature.MSR = f1_edx[5];
	Feature.AMDFeature.PAE = f1_edx[6];
	Feature.AMDFeature.MCE = f1_edx[7];
	Feature.AMDFeature.CMPXCHG8B = f1_edx[8];
	Feature.AMDFeature.APIC = f1_edx[9];
	Feature.AMDFeature.SysEnterSysExit = f1_edx[11];
	Feature.AMDFeature.MTRR = f1_edx[12];
	Feature.AMDFeature.PGE = f1_edx[13];
	Feature.AMDFeature.MCA = f1_edx[14];
	Feature.AMDFeature.CMOV = f1_edx[15];
	Feature.AMDFeature.PAT = f1_edx[16];
	Feature.AMDFeature.PSE36 = f1_edx[17];
	Feature.AMDFeature.CLFSH = f1_edx[19];
	Feature.AMDFeature.MMX = f1_edx[23];
	Feature.AMDFeature.FXSR = f1_edx[24];
	Feature.AMDFeature.SSE = f1_edx[25];
	Feature.AMDFeature.SSE2 = f1_edx[26];
	Feature.AMDFeature.HTT = f1_edx[28];

	Feature.AMDFeature.LahfSahf = f81_ecx[0];
	Feature.AMDFeature.CmpLegacy = f81_ecx[1];
	Feature.AMDFeature.SVM = f81_ecx[2];
	Feature.AMDFeature.ExtApicSpace = f81_ecx[3];
	Feature.AMDFeature.AltMovCr8 = f81_ecx[4];
	Feature.AMDFeature.ABM = f81_ecx[5];
	Feature.AMDFeature.SSE4A = f81_ecx[6];
	Feature.AMDFeature.MisAlignSse = f81_ecx[7];
	Feature.AMDFeature._3DNowPrefetch = f81_ecx[8];
	Feature.AMDFeature.OSVW = f81_ecx[9];
	Feature.AMDFeature.IBS = f81_ecx[10];
	Feature.AMDFeature.XOP = f81_ecx[11];
	Feature.AMDFeature.SKINIT = f81_ecx[12];
	Feature.AMDFeature.WDT = f81_ecx[13];
	Feature.AMDFeature.LWP = f81_ecx[15];
	Feature.AMDFeature.FMA4 = f81_ecx[16];
	Feature.AMDFeature.TBM = f81_ecx[21];
	Feature.AMDFeature.TopologyExtensions = f81_ecx[22];
	Feature.AMDFeature.PerfCtrExtCore = f81_ecx[23];
	Feature.AMDFeature.PerfCtrExtNB = f81_ecx[24];
	Feature.AMDFeature.DataBreakpointExtension = f81_ecx[26];
	Feature.AMDFeature.PerfTsc = f81_ecx[27];

	Feature.AMDFeature.SysCallSysRet = f81_edx[11];
	Feature.AMDFeature.NX = f81_edx[20];
	Feature.AMDFeature.MmxExt = f81_edx[22];
	Feature.AMDFeature.FFXSR = f81_edx[25];
	Feature.AMDFeature.Page1GB = f81_edx[26];
	Feature.AMDFeature.RDTSCP = f81_edx[27];
	Feature.AMDFeature.LM = f81_edx[29];
	Feature.AMDFeature._3DNowExt = f81_edx[30];
	Feature.AMDFeature._3DNow = f81_edx[31];
}

void AMD::ExecCache()
{
	Cache[0].Cache_level = 1;
	Cache[0].Cache_type = 'D';
	Cache[0].Cache_line_size = ((extdata__[5][2] & L1_DATA_CACHE_LINE_SIZE) >> 0);
	Cache[0].Cache_Ways = ((extdata__[5][2] & L1_DATA_CACHE_ASSOC) >> 16);
	Cache[0].Cache_Size = ((extdata__[5][2] & L1_DATA_CACHE_SIZE) >> 24);

	Cache[1].Cache_level = 1;
	Cache[1].Cache_type = 'T';
	Cache[1].Cache_line_size = ((extdata__[5][3] & L1_DATA_CACHE_LINE_SIZE) >> 0);
	Cache[1].Cache_Ways = ((extdata__[5][3] & L1_DATA_CACHE_ASSOC) >> 16);
	Cache[1].Cache_Size = ((extdata__[5][3] & L1_DATA_CACHE_SIZE) >> 24);

	Cache[2].Cache_level = 2;
	Cache[2].Cache_type = 'D';
	Cache[2].Cache_line_size = ((extdata__[6][2] & L2_DATA_CACHE_LINE_SIZE) >> 0);
	Cache[2].Cache_Ways = ((extdata__[6][2] & L2_DATA_CACHE_ASSOC) >> 12);
	//Cache[2].Cache_Ways = (unsigned int)pow(2, ((extdata__[6][2] & L2_DATA_CACHE_ASSOC) >> 12) - 1);
	Cache[2].Cache_Size = ((extdata__[6][2] & L2_DATA_CACHE_SIZE) >> 16);

	Cache[3].Cache_level = 3;
	Cache[3].Cache_type = 'D';
	Cache[3].Cache_line_size = ((extdata__[6][3] & L3_INSTRUCTION_CACHE_LINE_SIZE) >> 0);
	Cache[3].Cache_Ways = ((extdata__[6][3] & L3_INSTRUCTION_CACHE_ASSOC) >> 12);
	//Cache[3].Cache_Ways = (unsigned int)pow(2, ((extdata__[6][3] & L3_INSTRUCTION_CACHE_ASSOC) >> 12) - 1);
	Cache[3].Cache_Size = ((extdata__[6][3] & L3_INSTRUCTION_CACHE_SIZE) >> 18) * 512;
}

inline int AMD::findcpuid(int value)
{
	auto& it = find(nIdsLeaf.begin(), nIdsLeaf.end(), value);
	if (it != nIdsLeaf.end())
	{
		return distance(nIdsLeaf.begin(), it);
	}
	return -1;
}
