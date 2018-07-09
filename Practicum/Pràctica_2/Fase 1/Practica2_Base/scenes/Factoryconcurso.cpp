#include "Factoryconcurso.h"

FactoryConcurso::FactoryConcurso()
{

}

Scene *FactoryConcurso::createScene() {
    Scene *scene = new Scene();

    QString s0("://resources/models/sphere1.obj");

    Object * sol = new Object(100000, s0);


    QString s1("://resources/models/bigHero.obj");
    Object * hero= new Object(100000, s1);

    QString s2("://resources/models/wooden-wall.obj");
    Object * valla = new Object(100000, s2);

    QString s3("://resources/models/tree-toon.obj");
    Object * arbre = new Object(100000,s3);
    Object * arbre1 = new Object(100000,s3);
    Object * arbre2 = new Object(100000,s3);

    QString s4("://resources/models/basic_character.obj");
    Object * ninot = new Object(100000, s4);

    QString s5("://resources/models/cruiser.obj");
    Object * nau = new Object(100000, s5);

    QString s6("://resources/models/sphere1.obj");
    Object * pilota = new Object(100000, s6);

    pilota->setMaterial(new Material(vec3(1,0,0),vec3(0.1),vec3(1.0),100.0));
    pilota->setTexture(new QOpenGLTexture(QImage("://resources/textures/crack.jpg")));



    hero->setMaterial(new Material(vec3(0,0,0),vec3(0.1),vec3(1.0),100.0));
    valla->setMaterial(new Material(vec3(0.8,0.4,0.1),vec3(0.1),vec3(1.0),100.0));
    arbre->setMaterial(new Material(vec3(0,0.9,0),vec3(0.1),vec3(1.0),10));
    sol->setMaterial(new Material(vec3(0.9,0.9,0),vec3(0.1),vec3(1.0),200.0));
    ninot->setMaterial(new Material(vec3(0.9,0.2,0.0),vec3(0.1),vec3(1.0),50.0));
    nau->setMaterial(new Material(vec3(0,0,0.9),vec3(0.1),vec3(1.0),100.0));

    hero->setTexture(new QOpenGLTexture(QImage("://resources/textures/white.jpg")));
    valla->setTexture(new QOpenGLTexture(QImage("://resources/textures/fusta.jpg")));
    arbre->setTexture(new QOpenGLTexture(QImage("://resources/textures/treeTex.jpg")));
    arbre1->setTexture(new QOpenGLTexture(QImage("://resources/textures/treeTex.jpg")));
    arbre2->setTexture(new QOpenGLTexture(QImage("://resources/textures/treeTex.jpg")));
    sol->setTexture(new QOpenGLTexture(QImage("://resources/textures/sunText.jpg")));
    ninot->setTexture(new QOpenGLTexture(QImage("://resources/textures/ninot_resina.png")));
    nau->setTexture(new QOpenGLTexture(QImage("://resources/textures/sunText.jpg")));



    Animation *heroRight = new Animation();

    heroRight->frameIni = 3;
    heroRight->frameFinal = 5;
    heroRight->transf = new Translate1(vec3(26,0.0,0.0));
    hero->addAnimation(heroRight);

    Animation *ninotRight = new Animation();

    ninotRight->frameIni = 3;
    ninotRight->frameFinal = 5;
    ninotRight->transf = new Translate1(vec3(28.6,0.0,0.0));
    ninot->addAnimation(ninotRight);

    Animation *pilotaRight = new Animation();

    pilotaRight->frameIni = 3;
    pilotaRight->frameFinal = 5;
    pilotaRight->transf = new Translate1(vec3(26,0.0,0.0));
    pilota->addAnimation(pilotaRight);


    Animation *heroTurn = new Animation();
    heroTurn->frameIni = 0;
    heroTurn->frameFinal = 2;
    heroTurn->transf = new Rotate(-90,vec3(0.0,1.0,0.0));
    hero->addAnimation(heroTurn);

    Animation *ninotTurn = new Animation();
    ninotTurn->frameIni = 0;
    ninotTurn->frameFinal = 2;
    ninotTurn->transf = new Rotate(-70,vec3(0.0,1.0,0.0));
    ninot->addAnimation(ninotTurn);

    Animation *pilotaTurn = new Animation();
    pilotaTurn->frameIni = 0;
    pilotaTurn->frameFinal = 2;
    pilotaTurn->transf = new Rotate(-90,vec3(0.0,1.0,0.0));
    pilota->addAnimation(pilotaTurn);

    Animation *nauGran = new Animation();
    nauGran->frameIni = 0;
    nauGran->frameFinal = 2;
    nauGran->transf = new Scale1(vec3(1.5));
    nau->addAnimation(nauGran);

    Animation *solGran = new Animation();
    solGran->frameIni = 0;
    solGran->frameFinal = 2;
    solGran->transf = new Scale1(vec3(6.5));
    sol->addAnimation(solGran);

    Animation *pilotaGran = new Animation();
    pilotaGran->frameIni = 0;
    pilotaGran->frameFinal = 2;
    pilotaGran->transf = new Scale1(vec3(5.0f));
    pilota->addAnimation(pilotaGran);

    Animation *nauMov = new Animation();
    nauMov->transf = new Translate1(vec3(0.02,0.04,0));
    nau->addAnimation(nauMov);


    Animation *nauT = new Animation();
    nauT->frameIni = 0;
    nauT->frameFinal = 2;
    nauT->transf = new Translate1(vec3(-10,12,0.0));
    nau->addAnimation(nauT);

    Animation * nauR = new Animation();
    nauR->transf = new Rotate(0.9,vec3(1,0,0));
    nau->addAnimation(nauR);

    Animation *animNula = new Animation();
    animNula->transf = NULL;


    Animation *vallaLeft = new Animation();
    vallaLeft->frameIni = 0;
    vallaLeft->frameFinal = 2;
    vallaLeft->transf = new Translate1(vec3(10,0,0));

    Animation *vallaTurn = new Animation();
    vallaTurn->frameIni = 0;
    vallaTurn->frameFinal = 2;
    vallaTurn->transf = new Rotate(-10, vec3(0,1,0));


    valla->addAnimation(vallaLeft);
    valla->addAnimation(vallaTurn);

    Animation *heroAdvance = new Animation();
    heroAdvance->frameIni = 6;
    heroAdvance->frameFinal = 50;
    heroAdvance->transf = new Translate1(vec3(-0.1,0,0));
    hero->addAnimation(heroAdvance);

    Animation *ninotAdvance = new Animation();
    ninotAdvance->frameIni = 274;
    ninotAdvance->frameFinal = 324;
    ninotAdvance->transf = new Translate1(vec3(-0.1,0,0));
    ninot->addAnimation(ninotAdvance);

    Animation *pilotaAdvance = new Animation();
    pilotaAdvance->frameIni = 380;
    pilotaAdvance->frameFinal = 430;
    pilotaAdvance->transf = new Translate1(vec3(-0.1,0,0));
    pilota->addAnimation(pilotaAdvance);

    Animation *heroUp = new Animation();
    heroUp->frameIni = 51;
    heroUp->frameFinal = 100;
    heroUp->transf = new Translate1(vec3(0,0.12,0));
    hero->addAnimation(heroUp);

    Animation *ninotUp = new Animation();
    ninotUp->frameIni = 325;
    ninotUp->frameFinal = 375;
    ninotUp->transf = new Translate1(vec3(0,0.09,0));
    ninot->addAnimation(ninotUp);

    Animation *pilotaUp = new Animation();
    pilotaUp->frameIni = 431;
    pilotaUp->frameFinal = 481;
    pilotaUp->transf = new Translate1(vec3(0,0.09,0));
    pilota->addAnimation(pilotaUp);

    Animation *heroUpForward = new Animation();
    heroUpForward->frameIni = 51;
    heroUpForward->frameFinal = 105;
    heroUpForward->transf = new Translate1(vec3(-0.3,0,0));
    hero->addAnimation(heroUpForward);

    Animation *ninotUpForward = new Animation();
    ninotUpForward->frameIni = 325;
    ninotUpForward->frameFinal = 375;
    ninotUpForward->transf = new Translate1(vec3(-0.14,0,0));
    ninot->addAnimation(ninotUpForward);

    Animation *pilotaUpForward = new Animation();
    pilotaUpForward->frameIni =  431;
    pilotaUpForward->frameFinal = 486;
    pilotaUpForward->transf = new Translate1(vec3(-0.3,0,0));
    pilota->addAnimation(pilotaUpForward);

    Animation *heroDown  = new Animation();
    heroDown->frameIni = 105;
    heroDown->frameFinal = 150;
    heroDown->transf = new Translate1(vec3(0,-0.13,0));
    hero->addAnimation(heroDown);

    Animation *ninotDown  = new Animation();
    ninotDown->frameIni = 375;
    ninotDown->frameFinal = 425;
    ninotDown->transf = new Translate1(vec3(0,-0.09,0));
    ninot->addAnimation(ninotDown);

    Animation *pilotaDown  = new Animation();
    pilotaDown->frameIni = 486;
    pilotaDown->frameFinal = 520;
    pilotaDown->transf = new Translate1(vec3(0,-0.13,0));
    pilota->addAnimation(pilotaDown);

    Animation *heroDownForward = new Animation();
    heroDownForward->frameIni = 105;
    heroDownForward->frameFinal = 150;
    heroDownForward->transf = new Translate1(vec3(-0.1,0,0));
    hero->addAnimation(heroDownForward);

    Animation *ninotDownForward = new Animation();
    ninotDownForward->frameIni = 375;
    ninotDownForward->frameFinal = 425;
    ninotDownForward->transf = new Translate1(vec3(-0.13,0,0));
    ninot->addAnimation(ninotDownForward);

    Animation *pilotaDownForward  = new Animation();
    pilotaDownForward->frameIni = 486;
    pilotaDownForward->frameFinal = 520;
    pilotaDownForward->transf = new Translate1(vec3(-0.13,0,0));
    pilota->addAnimation(pilotaDownForward);

    Animation * heroLeft  =new Animation();
    heroLeft->frameIni = 151;
    heroLeft->frameFinal = 270;
    heroLeft->transf = new Translate1(vec3(-0.3,0,0));
    hero->addAnimation(heroLeft);


    Animation * ninotLeft  =new Animation();
    ninotLeft->frameIni = 425;
    ninotLeft->frameFinal = 520;
    ninotLeft->transf = new Translate1(vec3(-0.3,0,0));
    ninot->addAnimation(ninotLeft);

    Animation * pilotaLeft  =new Animation();
    pilotaLeft->frameIni = 520;
    pilotaLeft->frameFinal = 600;
    pilotaLeft->transf = new Translate1(vec3(-0.3,0,0));
    pilota->addAnimation(pilotaLeft);


    Animation *treePlace = new Animation();
    treePlace->frameIni = 0;
    treePlace->frameFinal = 2;
    treePlace->transf = new Translate1(vec3(0,2.4,-5));
    arbre->addAnimation(treePlace);

    Animation *treePlace1 = new Animation();
    treePlace1->frameIni = 0;
    treePlace1->frameFinal = 2;
    treePlace1->transf = new Translate1(vec3(-15,2.4,-5));
    arbre1->addAnimation(treePlace1);

    Animation *treePlace2 = new Animation();
    treePlace2->frameIni = 0;
    treePlace2->frameFinal = 2;
    treePlace2->transf = new Translate1(vec3(15,2.4,-5));
    arbre2->addAnimation(treePlace2);

    Animation *treeR = new Animation();
    treeR->transf = new RotateSecundaria(1.2,vec3(0,-0.02,0));
    arbre->addAnimation(treeR);
    arbre1->addAnimation(treeR);
    arbre2->addAnimation(treeR);


    Animation * sunPlace = new Animation();
    sunPlace->frameIni = 0;
    sunPlace->frameFinal = 2;
    sunPlace->transf = new Translate1(vec3(-12,15,-5));
    sol->addAnimation(sunPlace);


    scene->addObject(hero);
    scene->addObject(valla);
    scene->addObject(arbre);
    scene->addObject(arbre1);
    scene->addObject(arbre2);
    scene->addObject(sol);
    scene->addObject(ninot);
    scene->addObject(nau);
    scene->addObject(pilota);

    Light *l = new Light(Puntual);
    scene->addLight(l);
    Light *l2 = new Light(Puntual);
    l2->setLightPosition(vec4(-4,10,0,0));
    scene->addLight(l2);

    Light *solet = new Light(Spot);
    solet->setLightPosition(vec4(-12,15,-6,0));
    scene->addLight(solet);


    return scene;
}
