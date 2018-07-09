#ifndef SCENEFACTORYBASICA_H
#define SCENEFACTORYBASICA_H

#include "SceneFactory.h"

class SceneFactoryBasica : public SceneFactory
{
public:
    SceneFactoryBasica();

    virtual Scene *createScene();

private:
    void OneSphere(Scene *s);
    void MoreSpheres(Scene *s);
    void TwoPlanes(Scene *s);
};

#endif // SCENEFACTORYBASICA_H
