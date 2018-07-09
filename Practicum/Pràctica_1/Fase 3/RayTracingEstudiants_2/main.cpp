#include "main.h"

// Metode principal del programa

int main(int argc, char **argv) {

    // inicialitza l'escena: el constructor de l'escena s'encarrega de
    // crear els objectes i les llums

    SceneFactory *scFac = new FactoryConcurso();

    //Si es vol la Realistic Scene, descomentar!

    //SceneFactory *scFac = new RealisticSceneFactory();

    Scene *scene = scFac->createScene();
#ifdef GLUT
    Render *render = new RayTracingGLU(scene);
#else
#ifndef ANIM
    Render *render = new RayTracingPPM(scene);
#else
    Render *render = new AnimPPM(scene);
#endif
#endif

    render->startRendering(argc, argv);

    return(0);
}
