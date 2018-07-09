#include "Factoryconcurso.h"

FactoryConcurso::FactoryConcurso()
{

}

Scene *FactoryConcurso::createScene() {
    Scene *s = new Scene();
    // creacio de la camera
    vec3 lookfrom(60,2,3);

    vec3 lookat(0,0,0);
    float dist_to_focus = 60.0;
    float aperture = 0.1;
    int pixelsX = 600;
    int pixelsY = 400;
    s->setAmbient(vec3(0.01, 0.01, 0.01));

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 20, pixelsX, pixelsY, aperture, dist_to_focus,10);

    this->animacio(s);

    return s;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random

void FactoryConcurso::animacio(Scene *s) {

    //Creacio de les estrelles. Son esferes blanques, i per tant, no tenen animacio

    Sphere * estrellas;

    Animation *animNula = new Animation();
    animNula->transf = NULL;
    //Creem 200 esferes "petites"
    for(int i = 0; i < 200;i++){
        //Hi ha 4 posicions (4 rectangles de "la grafica". Les posicions son aleatories, pero s'ha calculat el maxim d'alçada (10.5) i d'amplada (15.5).
        //La profunditat ens es igual, la posem negativa perque no surtin davant de cap planeta
        vec3 positives = vec3(-0.1,10.5,15.5)*vec3(1,drand48(),drand48());
        vec3 negatives = vec3(-0.1,-10.5,-15.5)*vec3(1,drand48(),drand48());
        vec3 posMix = vec3(-0.1,10.5,-15.5)*vec3(1,drand48(),drand48());
        vec3 posMix2 = vec3(-0.1,-10.5,15.5)*vec3(1,drand48(),drand48());
        int random = rand() % 5;
        if(random == 0){
            estrellas = new Sphere(positives, 0.017,new Lambertian(vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1),10.0));
        }else if (random == 1){
            estrellas = new Sphere(negatives, 0.017,new Lambertian(vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1),10.0));
        } else if(random == 2) {
            estrellas = new Sphere(posMix, 0.017,new Lambertian(vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1),10.0));
        } else {
            estrellas = new Sphere(posMix2, 0.017,new Lambertian(vec3(1, 1, 1), vec3(1, 1, 1), vec3(1, 1, 1),10.0));
        }
        estrellas->addAnimation(animNula);
        s->objects.push_back(estrellas);
    }

    //Creacio del sol.
    Sphere *sol = new Sphere(vec3(0,0,0), 2.5, new Lambertian(vec3(0.925, 0.494, 0.094), vec3(0, 0, 0), vec3(0.9,0.4,0),0));
    sol->addAnimation(animNula);
    s->objects.push_back(sol);


    //Creacio de cada planeta
    Sphere *mercuri = new Sphere(vec3(0,0,2.8), 0.13, new Lambertian(vec3(1, 0, 0.1), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *venus = new Sphere(vec3(0,0,3.2),0.2,new Lambertian(vec3(0.7,0,0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *earth = new Sphere(vec3(0,3.20429,1.85), 0.28, new Lambertian(vec3(0.101, 0.568, 1), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *m = new Sphere(vec3(0,-3.61133,-2.085), 0.15, new Lambertian(vec3(0.8,0,0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *j = new Sphere(vec3(0,1.94951,-5.35625), 0.8, new Lambertian(vec3(0.980, 0.662, 0.4), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    //Saturn
    Sphere *sat = new Sphere(vec3(0,0.1,7.5), 0.7, new Lambertian(vec3(0.882, 0.458, 0.458), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));

    //Per simular l'anell de Saturn hem creat una serie d'esferes que juntes formen un anell.
    //Hem creat un vector per estalviar codi
    s->cinturo.push_back(new Sphere(vec3(0.8,0.09,8.15), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0.05,8.1), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0,7.9), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0,7.7), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0,7.5), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0.01,7.3), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0.03,7.1), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0.05,6.9), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(1,0.1,6.7), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));
    s->cinturo.push_back(new Sphere(vec3(0.8,0.19,6.6), 0.1,new Lambertian(vec3(0.6, 0.329, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0)));

    //Ura i neptu
    Sphere *u = new Sphere(vec3(0,-7.96743,-4.6), 0.45, new Lambertian(vec3(0.2,0.7,0.8), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *n = new Sphere(vec3(0,6.55643,-7.81365), 0.37, new Lambertian(vec3(0.1,0.2,0.9), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));

    //Hem simulat un meteorit que pasa per l'escena
    Sphere *meteorit = new Sphere(vec3(-1,-6.7,-7.5),0.1,new Metal(vec3(0.925, 0.494, 0.094), vec3(0.1, 0.1, 1), vec3(1, 1, 1),100.0));

    //Hem fet que els planetes rotin en sentit de les agulles del rellotge i en contra
    RotatePunto *rDreta = new RotatePunto(vec3(1,0,0),vec3(0,0,0),20);
    RotatePunto *rEsquerre = new RotatePunto(vec3(-1,0,0),vec3(0,0,0),20);

    //El meteorit no rota, es mou
    Translate *mT = new Translate(vec3(0,0,0));
    Animation *animMeteorit = new Animation();
    animMeteorit->transf = mT;

    //Creacio de l'animacio de rotacio i assignacio
    Animation *animPlaneta = new Animation();
    Animation *animPlanetaEsquerre = new Animation();
    animPlanetaEsquerre->transf =rEsquerre;
    animPlaneta->transf = rDreta;

    mercuri->addAnimation(animPlanetaEsquerre);
    venus->addAnimation(animPlaneta);
    earth->addAnimation(animPlaneta);
    m->addAnimation(animPlanetaEsquerre);
    j->addAnimation(animPlaneta);
    sat->addAnimation(animPlaneta);
    sat->addAnimation(animPlanetaEsquerre);
    u->addAnimation(animPlanetaEsquerre);
    n->addAnimation(animPlaneta);
    meteorit->addAnimation(animMeteorit);

    //Pushes
    s->objects.push_back(mercuri);
    s->objects.push_back(venus);
    s->objects.push_back(earth);
    s->objects.push_back(m);
    s->objects.push_back(j);
    s->objects.push_back(sat);
    s->objects.push_back(u);
    s->objects.push_back(n);
    s->objects.push_back(meteorit);

    //Pel cinturo
    for (int j = 0; j < s->cinturo.size(); j++) {
        s->cinturo[j]->addAnimation(animPlaneta);
        s->objects.push_back(s->cinturo[j]);
    }

    //Posem una llum que ilumina l'escena
    Light *p = new Light(vec3(13,0,0), vec3(0.3, 0.3, 0.3), vec3(0.7, 0.7, 0.7), vec3(1, 1, 1), 0.5, 0.01);
    s->lights.push_back(p);

}

