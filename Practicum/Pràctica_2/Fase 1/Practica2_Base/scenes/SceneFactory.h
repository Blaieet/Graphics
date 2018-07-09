#ifndef SCENEFACTORY_H
#define SCENEFACTORY_H

#include "Scene.h"
#include"./TG/Translate1.h"
#include "./TG/Rotate.h"
#include "./TG/Scale1.h"

class SceneFactory
{
public:
    SceneFactory();
    virtual Scene *createScene() = 0;
    virtual ~SceneFactory();
};

#endif // SCENEFACTORY_H
