#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <string>
#include "ACPI Defination.h"

using namespace std;

class UnCopyable
{
protected:
	UnCopyable() {}
	~UnCopyable() {}

private:
	explicit UnCopyable(const UnCopyable& x);
	UnCopyable& operator=(const UnCopyable& x);
};


class CACPI : private UnCopyable
{
	union MADT_Interrupt_Controller
	{
		APIC_Structure								Processor_Local_APIC;
		IO_APIC_Structure							IO_APIC;
		Interrupt_Source_Override_Structure			Interrupt_Source_Override;
		NMI_Source_Structure						NMI_Source;
		Local_APIC_NMI_Structure					Local_APIC_NMI;
		Local_APIC_Address_Override_Structure		Local_APIC_Address_Override;
		IO_SAPIC_Structure							IO_SAPIC;
		Platform_Interrupt_Source_Structure			Platform_Interrupt_Sources;
		Processor_Local_X2APIC_Structure			Processor_Local_X2APIC;
		Local_X2APIC_NMI_Structure					Local_x2APIC_NMI;
		GIC_CPU_Interface_Structure					GICC;
		GIC_Distributor_Structure					GICD;
		GIC_MSI_Frame_Structure						GIC_MSI_Frame;
		GICR_Structure								GICR;
		GIC_Interrupt_Translation_Service_Structure	ITS;
	};
public:
	CACPI();
	~CACPI();

	/****************************************************
	*@Function				Excute
	*@brief					����ACPI Tableֵ
	*@author				��˶
	*@param					��
		*@Table_Type		ACPI��ͷ��
	*@return				��
	****************************************************/
	void Excute();	

private:
	/****************************************************
	*@Function				GetACPIAddress
	*@brief					��ȡACPI�����ڴ��еĵ�ַ
	*@author				��˶
	*@param
	*@other
		*@isSupportACPI		�����øñ����ж�ִ���Ƿ�ɹ�
	****************************************************/
	void GetACPIAddress();

	/****************************************************
	*@Function				GetXSDT_RSDT
	*@brief					��ȡACPI���RSDP RSDT XSDT
	*@author				��˶
	*@param
	*@other
		*@isSupportACPI		�����øñ����ж�ִ���Ƿ�ɹ�
	****************************************************/
	void GetXSDT_RSDT();


	void GetOtherTabels();
public:
	ACPI_RSDP_STRUCTURE						acpi_rsdp;
	ACPI_RSDT_STRUCTURE						acpi_rsdt;
	ACPI_XSDT_STRUCTURE						acpi_xsdt;
	ACPI_MCFG_STRUCTURE						acpi_mcfg;
	ACPI_FADT_STRUCTURE						acpi_facp;
	std::shared_ptr<ACPI_FPDT_STRUCTURE>	acpi_fpdt;
	std::shared_ptr<ACPI_FACS_STRUCTURE>	acpi_facs;
	ACPI_MADT_STRUCTURE						acpi_apic;
	ACPI_HPET_STRUCTURE						acpi_hpet;
	std::shared_ptr<ACPI_SBST_STRUCTURE>	acpi_sbst;
	std::shared_ptr<ACPI_BGRT_STRUCTURE>	acpi_bgrt;
	std::shared_ptr<ACPI_CPEP_STRUCTURE>	acpi_cpep;
	std::shared_ptr<ACPI_ECDT_STRUCTURE>	acpi_ecdt;
	
	bool isSupportACPI;	//�Ƿ�֧�ֻ�ȡACPI��
private:
	bool IsACPI1_0;
	size_t ACPIAddress;

};