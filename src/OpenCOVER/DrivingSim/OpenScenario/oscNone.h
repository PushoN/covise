/* This file is part of COVISE.

You can use it under the terms of the GNU Lesser General Public License
version 2.1 or later, see lgpl-2.1.txt.

* License: LGPL 2+ */

#ifndef OSC_NONE_H
#define OSC_NONE_H

#include "oscExport.h"
#include "oscObjectBase.h"
#include "oscObjectVariable.h"


namespace OpenScenario {

/// \class This class represents a generic OpenScenario Object
class OPENSCENARIOEXPORT oscNone: public oscObjectBase
{
public:

    oscNone()
    {

    };

};

typedef oscObjectVariable<oscNone *> oscNoneMember;

}

#endif /* OSC_NONE_H */
