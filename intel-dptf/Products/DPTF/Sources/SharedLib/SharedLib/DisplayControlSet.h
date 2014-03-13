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

#include "DisplayControl.h"
#include "BasicTypes.h"
#include <vector>

class XmlNode;

class DisplayControlSet final
{
public:

    DisplayControlSet(const std::vector<DisplayControl>& displayControl);
    UIntN getCount(void) const;
    const DisplayControl& operator[](UIntN index) const;
    Bool operator==(const DisplayControlSet& rhs) const;
    Bool operator!=(const DisplayControlSet& rhs) const;
    UIntN getControlIndex(Percentage brightness);
    XmlNode* getXml(void);

private:

    std::vector<DisplayControl> m_displayControl;
};