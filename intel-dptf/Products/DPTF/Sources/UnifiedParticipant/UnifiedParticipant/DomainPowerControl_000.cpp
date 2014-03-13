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

#include "DomainPowerControl_000.h"


DomainPowerControl_000::DomainPowerControl_000(ParticipantServicesInterface* participantServicesInterface)
{
    // Do nothing.  Not an error.
}

PowerControlDynamicCapsSet DomainPowerControl_000::getPowerControlDynamicCapsSet(UIntN participantIndex, UIntN domainIndex)
{
    throw not_implemented();
}

PowerControlStatusSet DomainPowerControl_000::getPowerControlStatusSet(UIntN participantIndex, UIntN domainIndex)
{
    throw not_implemented();
}

void DomainPowerControl_000::setPowerControl(UIntN participantIndex, UIntN domainIndex, const PowerControlStatusSet& powerControlStatusSet)
{
    throw not_implemented();
}

void DomainPowerControl_000::clearCachedData(void)
{
    // Do nothing.  Not an error.
}

XmlNode* DomainPowerControl_000::getXml(UIntN domainIndex)
{
    throw not_implemented();
}

void DomainPowerControl_000::updateBasedOnConfigTdpInformation(UIntN participantIndex, UIntN domainIndex,
    ConfigTdpControlSet configTdpControlSet, ConfigTdpControlStatus configTdpControlStatus)
{
    throw not_implemented();
}