/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

//
//  Vrml 97 library
//  Copyright (C) 2001 Uwe Woessner
//
//  %W% %G%
//  VrmlNodePrecipitation.cpp
#ifdef _WIN32
#if (_MSC_VER >= 1300) && !(defined(MIDL_PASS) || defined(RC_INVOKED))
#define POINTER_64 __ptr64
#else
#define POINTER_64
#endif
#include <winsock2.h>
#include <windows.h>
#endif
#include <util/common.h>
#include <vrml97/vrml/config.h>
#include <vrml97/vrml/VrmlNodeType.h>
#include <vrml97/vrml/coEventQueue.h>

#include <vrml97/vrml/MathUtils.h>
#include <vrml97/vrml/System.h>
#include <vrml97/vrml/Viewer.h>
#include <vrml97/vrml/VrmlScene.h>
#include <cover/VRViewer.h>
#include <cover/VRSceneGraph.h>
#include <cover/coVRAnimationManager.h>
#include <cover/coVRPluginSupport.h>
#include <OpenVRUI/osg/mathUtils.h>
#include <math.h>

#include <util/byteswap.h>

#include "VrmlNodePrecipitation.h"
#include "ViewerOsg.h"
#include <osg/Quat>

static list<VrmlNodePrecipitation *> allPrecipitation;

// Precipitation factory.

static VrmlNode *creator(VrmlScene *scene)
{
    return new VrmlNodePrecipitation(scene);
}

void VrmlNodePrecipitation::update()
{
}

// Define the built in VrmlNodeType:: "Precipitation" fields

VrmlNodeType *VrmlNodePrecipitation::defineType(VrmlNodeType *t)
{
    static VrmlNodeType *st = 0;

    if (!t)
    {
        if (st)
            return st; // Only define the type once.
        t = st = new VrmlNodeType("Precipitation", creator);
    }

    VrmlNodeChild::defineType(t); // Parent class

    t->addExposedField("numPrecipitation", VrmlField::SFINT32);
    t->addExposedField("enabled", VrmlField::SFBOOL);
    t->addExposedField("loop", VrmlField::SFBOOL);
    t->addEventOut("fraction_changed", VrmlField::SFFLOAT);
    t->addEventIn("timestep", VrmlField::SFINT32);

    return t;
}

VrmlNodeType *VrmlNodePrecipitation::nodeType() const
{
    return defineType(0);
}

VrmlNodePrecipitation::VrmlNodePrecipitation(VrmlScene *scene)
    : VrmlNodeChild(scene)
    , d_numPrecipitation(0)
    , d_fraction_changed(0.0)
    , d_enabled(true)
    , d_loop(true)
{
    setModified();
    precipitationEffect = new osgParticle::PrecipitationEffect;
    precipitationEffect->rain(1.0);
    cover->getObjectsRoot()->addChild(precipitationEffect.get());
}

void VrmlNodePrecipitation::addToScene(VrmlScene *s, const char *relUrl)
{
    (void)relUrl;
    d_scene = s;
    if (s)
    {
    }
    else
    {
        cerr << "no Scene" << endl;
    }
}

// need copy constructor for new markerName (each instance definitely needs a new marker Name) ...

VrmlNodePrecipitation::VrmlNodePrecipitation(const VrmlNodePrecipitation &n)
    : VrmlNodeChild(n.d_scene)
    , d_numPrecipitation(n.d_numPrecipitation)
    , d_fraction_changed(n.d_fraction_changed)
    , d_enabled(n.d_enabled)
    , d_loop(n.d_loop)
{
    
    precipitationEffect = new osgParticle::PrecipitationEffect;
    precipitationEffect->rain(1.0);
    cover->getScene()->addChild(precipitationEffect.get());
    setModified();
}

VrmlNodePrecipitation::~VrmlNodePrecipitation()
{
    cover->getObjectsRoot()->removeChild(precipitationEffect.get());
}

VrmlNode *VrmlNodePrecipitation::cloneMe() const
{
    return new VrmlNodePrecipitation(*this);
}

VrmlNodePrecipitation *VrmlNodePrecipitation::toPrecipitation() const
{
    return (VrmlNodePrecipitation *)this;
}

void VrmlNodePrecipitation::render(Viewer *viewer)
{
    (void)viewer;
    //setModified();
}

ostream &VrmlNodePrecipitation::printFields(ostream &os, int indent)
{
    if (!d_numPrecipitation.get())
        PRINT_FIELD(numPrecipitation);
    if (!d_enabled.get())
        PRINT_FIELD(enabled);
    if (!d_loop.get())
        PRINT_FIELD(loop);
    if (!d_fraction_changed.get())
        PRINT_FIELD(fraction_changed);

    return os;
}

// Set the value of one of the node fields.

void VrmlNodePrecipitation::setField(const char *fieldName,
                                 const VrmlField &fieldValue)
{
    if
        TRY_FIELD(numPrecipitation, SFInt)
    else if
        TRY_FIELD(enabled, SFBool)
    else if
        TRY_FIELD(loop, SFBool)
    else if
        TRY_FIELD(fraction_changed, SFFloat)
    else
        VrmlNodeChild::setField(fieldName, fieldValue);

    if (strcmp(fieldName, "numPrecipitation") == 0)
    {
    }
    if (strcmp(fieldName, "timestep") == 0)
    {
    }
}

const VrmlField *VrmlNodePrecipitation::getField(const char *fieldName) const
{
    if (strcmp(fieldName, "numPrecipitation") == 0)
        return &d_numPrecipitation;
    if (strcmp(fieldName, "enabled") == 0)
        return &d_enabled;
    else if (strcmp(fieldName, "loop") == 0)
        return &d_loop;
    else if (strcmp(fieldName, "fraction_changed") == 0)
        return &d_fraction_changed;
    else
        cerr << "Node does not have this eventOut or exposed field " << nodeType()->getName() << "::" << name() << "." << fieldName << endl;
    return 0;
}
