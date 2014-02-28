/******************************************************************************
** Copyright (c) 2014 Intel Corporation All Rights Reserved
**
** Licensed under the Apache License, Version 2.0 (the "License"); you may not
** use this file except in compliance with the License.
**
** You may obtain a copy of the License at
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
** WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
**
** See the License for the specific language governing permissions and
** limitations under the License.
**
******************************************************************************/

#include "Temperature.h"
#include "DptfExceptions.h"
#include "XmlNode.h"
#include "StatusFormat.h"
#include "GccFix.h"

Temperature::Temperature(void) : m_temperature(invalidTemperature)
{
}

Temperature::Temperature(UInt32 temperature) : m_temperature(temperature)
{
    if (temperature > maxValidTemperature && temperature != invalidTemperature)
    {
        throw dptf_exception("Temperature out of valid range");
    }
}

UInt32 Temperature::getTemperature() const
{
    return m_temperature;
}

Bool Temperature::isTemperatureValid() const
{
    return isTemperatureValid(m_temperature);
}

Bool Temperature::operator==(const Temperature& rhs) const
{
    // Do not throw an exception if temperature is not valid.
    return (this->getTemperature() == rhs.getTemperature());
}

Bool Temperature::operator!=(const Temperature& rhs) const
{
    // Do not throw an exception if temperature is not valid.
    return !(*this == rhs);
}

Bool Temperature::operator>(const Temperature& rhs) const
{
    throwIfTemperatureNotValid(this->getTemperature(), rhs.getTemperature());
    return (this->getTemperature() > rhs.getTemperature());
}

Bool Temperature::operator>=(const Temperature& rhs) const
{
    throwIfTemperatureNotValid(this->getTemperature(), rhs.getTemperature());
    return (this->getTemperature() >= rhs.getTemperature());
}

Bool Temperature::operator<(const Temperature& rhs) const
{
    throwIfTemperatureNotValid(this->getTemperature(), rhs.getTemperature());
    return (this->getTemperature() < rhs.getTemperature());
}

Bool Temperature::operator<=(const Temperature& rhs) const
{
    throwIfTemperatureNotValid(this->getTemperature(), rhs.getTemperature());
    return (this->getTemperature() <= rhs.getTemperature());
}

std::string Temperature::toString() const
{
    if (isTemperatureValid())
    {
        return GccFix::to_string(m_temperature) + "C"; // TODO: adjust for when we get 10th degrees C
    }
    else
    {
        return "_C"; // TODO: adjust for when we get 10th degrees C
    }
}

XmlNode* Temperature::getXml(std::string tag)
{
    return XmlNode::createDataElement(tag, StatusFormat::friendlyValue(m_temperature));
}

Bool Temperature::isTemperatureValid(UInt32 temperature) const
{
    return ((temperature <= maxValidTemperature) && (temperature != invalidTemperature));
}

void Temperature::throwIfTemperatureNotValid(UInt32 lhs, UInt32 rhs) const
{
    if (isTemperatureValid(lhs) == false || isTemperatureValid(rhs) == false)
    {
        throw dptf_exception("Temperature is not valid.");
    }
}
