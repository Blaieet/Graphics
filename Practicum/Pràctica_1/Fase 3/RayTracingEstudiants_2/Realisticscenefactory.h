#ifndef REALISTICSCENEFACTORY_H
#define REALISTICSCENEFACTORY_H

#include "SceneFactory.h"


class RealisticSceneFactory : public SceneFactory
{
public:
    RealisticSceneFactory();
    virtual Scene *createScene();
private:
    void createEscena(Scene *s);
};

#endif // REALISTICSCENEFACTORY_H
