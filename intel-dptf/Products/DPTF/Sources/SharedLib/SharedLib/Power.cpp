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

#include "Power.h"
#include "DptfExceptions.h"
#include "StatusFormat.h"
#include "XmlNode.h"
#include "GccFix.h"

Power::Power(void) : m_power(invalidPower)
{
}

Power::Power(UInt32 power) : m_power(power)
{
    if (power > maxValidPower && power != invalidPower)
    {
        throw dptf_exception("Power value " + GccFix::to_string(power) + " out of valid range.");
    }
}

UInt32 Power::getPower() const
{
    return m_power;
}

Bool Power::isPowerValid() const
{
    return isPowerValid(m_power);
}

Bool Power::operator==(const Power& rhs) const
{
    return (this->getPower() == rhs.getPower());
}

Bool Power::operator!=(const Power& rhs) const
{
    return !(*this == rhs);
}

Bool Power::operator>(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());
    return (this->getPower() > rhs.getPower());
}

Bool Power::operator>=(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());
    return (this->getPower() >= rhs.getPower());
}

Bool Power::operator<(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());
    return (this->getPower() < rhs.getPower());
}

Bool Power::operator<=(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());
    return (this->getPower() <= rhs.getPower());
}

Power Power::operator+(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());
    return Power(this->getPower() + rhs.getPower());
}

Power Power::operator-(const Power& rhs) const
{
    throwIfInvalidPower(this->getPower(), rhs.getPower());

    if (rhs.getPower() > this->getPower())
    {
        throw dptf_exception("Invalid power subtraction requested.  rhs > lhs.");
    }

    return Power(this->getPower() - rhs.getPower());
}

std::string Power::toString() const
{
    return GccFix::to_string(m_power) + "mW";
}

XmlNode* Power::getXml(void)
{
    return getXml("");
}

XmlNode* Power::getXml(std::string tag)
{
    return XmlNode::createDataElement(tag, StatusFormat::friendlyValue(m_power));
}

Bool Power::isPowerValid(UInt32 power) const
{
    return ((power <= maxValidPower) && (power != invalidPower));
}

void Power::throwIfInvalidPower(UInt32 lhs, UInt32 rhs) const
{
    if (isPowerValid(lhs) == false || isPowerValid(rhs) == false)
    {
        throw dptf_exception("Power is invalid.");
    }
}
