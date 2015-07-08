////////////////////////////////////////////////////////////////////////////
//
//  This file is part of RTIMULib
//
//  Copyright (c) 2014-2015, richards-tech, LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy of
//  this software and associated documentation files (the "Software"), to deal in
//  the Software without restriction, including without limitation the rights to use,
//  copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
//  Software, and to permit persons to whom the Software is furnished to do so,
//  subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in all
//  copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
//  INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
//  PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
//  HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
//  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
//  SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#include "RTIMUNull.h"
#include "RTIMUSettings.h"

RTIMUNull::RTIMUNull(RTIMUSettings *settings) : RTIMU(settings)
{
}

RTIMUNull::~RTIMUNull()
{
}

bool RTIMUNull::IMUInit()
{

    m_imuData.fusionPoseValid = false;
    m_imuData.fusionQPoseValid = false;
    m_imuData.gyroValid = false;
    m_imuData.accelValid = false;
    m_imuData.compassValid = false;
    m_imuData.IMUtemperatureValid = false;
    m_imuData.IMUtemperature = 0.0;
    m_imuData.humidityValid = false;
    m_imuData.humidity = -1.0;
    m_imuData.temperatureValid = false;
    m_imuData.temperature = 0.0;
    m_imuData.pressureValid = false;
    m_imuData.pressure = 0.0;
    m_imuData.PStemperatureValid = false;
    m_imuData.PStemperature = 0.0;
	
    return true;
}

int RTIMUNull::IMUGetPollInterval()
{
    return (100);                                           // just a dummy value really
}

bool RTIMUNull::IMURead()
{
    updateFusion();
    return true;
}

void RTIMUNull::setIMUData(const RTIMU_DATA& data)
{
    m_imuData = data;
}
