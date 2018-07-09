#pragma once

#define GLUT
//#define ANIM

// Depenent de quina variable de precompilacio esta definida,
// s'inclou un o un altre .h

#ifdef GLUT
#include "RayTracingGLU.h"
#else
#ifndef ANIM
#include "RayTracingPPM.h"
#else
#include "AnimPPM.h"
#endif
#endif

#include "SceneFactoryBasica.h"
#include "Realisticscenefactory.h"

Render *rIntern;
