/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

/**************************************************************************\
**                                                           (C)2005 ZAIK **
**                                                                        **
** Description: Transform structured data to a structured grid            **
**                                                                        **
**      Author: Martin Aumueller (aumueller@uni-koeln.de)                 **
**                                                                        **
\**************************************************************************/

#ifndef _GRIDTODATA_H_
#define _GRIDTODATA_H_

#include <api/coSimpleModule.h>
using namespace covise;

class GridToData : public coSimpleModule
{
private:
    // Ports:
    coInputPort *piGrid;
    coOutputPort *poData;

    // Methods:
    virtual int compute(const char *port);

public:
    GridToData(int argc, char *argv[]);
};

#endif
