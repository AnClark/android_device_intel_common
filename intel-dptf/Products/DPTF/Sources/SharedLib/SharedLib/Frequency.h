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

#pragma once

#include "Dptf.h"

class XmlNode;

// Represents frequency in Hz

class Frequency final
{
public:

    Frequency(void);
    Frequency(UInt64 frequency);
    UInt64 getFrequency() const;
    Bool isFrequencyValid() const;
    Bool operator==(const Frequency& rhs) const;
    Bool operator!=(const Frequency& rhs) const;
    Bool operator>(const Frequency& rhs) const;
    Bool operator>=(const Frequency& rhs) const;
    Bool operator<(const Frequency& rhs) const;
    Bool operator<=(const Frequency& rhs) const;
    Frequency operator+(const Frequency& rhs) const;
    Frequency operator-(const Frequency& rhs) const;
    Frequency operator*(const Frequency& rhs) const;

    std::string toString() const;
    XmlNode* getXml(std::string tag) const;

private:

    static const UInt64 invalidFrequency = 0xFFFFFFFF;
    UInt64 m_frequency;                                             // Units:  Hz
    void throwIfFrequencyNotValid(UInt64 lhs, UInt64 rhs) const;
};