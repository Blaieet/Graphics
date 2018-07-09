#include "Realisticscenefactory.h"


RealisticSceneFactory::RealisticSceneFactory()
{

}

Scene *RealisticSceneFactory::createScene() {
    Scene *s = new Scene();

    vec3 lookfrom(13,2,3);
    //vec3 lookfrom(150,50,3);
    vec3 lookat(0,0,0);
    float dist_to_focus = 10.0;
    float aperture = 0.1;
    int pixelsX = 600;
    int pixelsY = 400;
    s->setAmbient(vec3(0.01, 0.01, 0.01));

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 20, pixelsX, pixelsY, aperture, dist_to_focus,10);

    Light *l = new Light(vec3(2, 8, 10), vec3(0.3, 0.3, 0.3), vec3(0.7, 0.7, 0.7), vec3(1, 1, 1), 0.5, 0.01);
    s->lights.push_back(l);
    this->createEscena(s);
    return s;

}



void RealisticSceneFactory::createEscena(Scene *s){

    Sphere *sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5, 0.5, 0.5), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Metal(vec3(0.7,0.6,0.5), vec3(0.2, 0.2, 0.2), vec3(1,1,1),5.0));
    Sphere *sphere3 = new Sphere(vec3(0,-1,0), 1.0, new Transparent(vec3(1.0,1.0,1.0), vec3(0.2, 0.2, 0.2), vec3(1,1,1),1.5,10.0));
    Sphere *sphere4 = new Sphere(vec3(1,-1,1), 1.0, new Lambertian(vec3(0, 1, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),3.0));
    Sphere *sphere5 = new Sphere(vec3(1,2,1), 1.0, new Metal(vec3(0, 0, 1), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *sphere6 = new Sphere(vec3(2,-2,1), 1.0, new Lambertian(vec3(1, 1, 1), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *sphere7 = new Sphere(vec3(0,2,-3), 1.0, new Lambertian(vec3(1, 1, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),7.0));
    Sphere *sphere8 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.5, 0.5, 0), vec3(0.5, 0.5, 0.5), vec3(1, 1, 1),10.0));
    s->objects.push_back(new Triangle(vec3(2, 0, 1), vec3(0, 0, 1), vec3(1, 1, 1), new Lambertian(vec3(0.7, 0.5, 0.8), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),2.0)));
    s->objects.push_back(new Sphere(vec3(0, -100.5, 3), 100, new Metal(vec3(0.7,0.6,0.5), vec3(0.2, 0.2, 0.2), vec3(1,1,1),10.0)));
    Sphere *sphere9 = new Sphere(vec3(1,1.5,3), 1.0, new Lambertian(vec3(-3, 0, 3), vec3(0.1, 0.1, 0), vec3(4, 0, -1),8.0));
    s->objects.push_back(sphere8);
    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphere3);
    s->objects.push_back(sphere4);
    s->objects.push_back(sphere5);
    s->objects.push_back(sphere6);
    s->objects.push_back(sphere7);
    s->objects.push_back(sphere9);

}

