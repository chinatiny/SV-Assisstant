#include "stdafx.h"
#include "SioChip.h"
#include "..\driver\Driverdll.h"

_SioSensor::_SioSensor() : sensor{}
{
}

const SioSensor & _SioSensor::GetSensordata()
{
	return sensor;
}

void _SioSensor::UpdateData()
{
}