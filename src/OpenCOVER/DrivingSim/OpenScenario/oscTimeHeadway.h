/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */
#ifndef OSC_TIME_HEADWAY_H
#define OSC_TIME_HEADWAY_H
#include <oscExport.h>
#include <oscObjectBase.h>
#include <oscObjectVariable.h>
#include <oscVariables.h>
#include <oscConditionChoiceObject.h>
#include <oscPosition.h>

namespace OpenScenario {


/// \class This class represents a generic OpenScenario Object
class OPENSCENARIOEXPORT oscTimeHeadway: public oscConditionChoiceObject
{
public:
    oscTimeHeadway()
    {	
		OSC_ADD_MEMBER(freespace);
		OSC_OBJECT_ADD_MEMBER(position, "oscPosition");
    };
	oscBool freespace;
	oscPositionMember position;
};

typedef oscObjectVariable<oscTimeHeadway *> oscTimeHeadwayMember;

}

#endif //OSC_TIME_HEADWAY_H