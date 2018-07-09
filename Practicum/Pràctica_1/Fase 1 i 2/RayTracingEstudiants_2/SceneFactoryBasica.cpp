#include "SceneFactoryBasica.h"

SceneFactoryBasica::SceneFactoryBasica()
{

}

Scene *SceneFactoryBasica::createScene() {
    Scene *s = new Scene();

    // creacio de la camera
    vec3 lookfrom(13,2,3);
    //vec3 lookfrom(150,50,3);
    vec3 lookat(0,0,0);
    float dist_to_focus = 10.0;
    float aperture = 0.1;
    int pixelsX = 600;
    int pixelsY = 400;
    s->setAmbient(vec3(0.01, 0.01, 0.01));

    s->cam = new Camera(lookfrom, lookat, vec3(0,1,0), 20, pixelsX, pixelsY, aperture, dist_to_focus,10);

    // TODO Fase 0: Cal crear els objectes de l'escena i afegir-los a l'escena
    this->OneSphere(s);
    //this->MoreSpheres(s);
    //this->TwoPlanes(s);
    return s;
}

// TODO: Metode que genera una escena random de numObjects de tipus esfera, a diferents posicions,
// amb diferents radis i diferents materials. S'usa drand48 per generar numeros random

void SceneFactoryBasica::OneSphere(Scene *s) {

    Sphere *sphere = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.5, 0.5, 0.5), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *sphere2 = new Sphere(vec3(0, -100.5, -1), 100, new Lambertian(vec3(0.8, 0.8, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere *sphere3 = new Sphere(vec3(-3,1,1), 1.0, new Metal(vec3(0.7,0.6,0.5), vec3(0.2, 0.2, 0.2), vec3(0.7, 0.7, 0.7),10.0));
    Sphere *sphere4 = new Sphere(vec3(0,1,0), 1.0, new Transparent(vec3(1.0,1.0,1.0), vec3(0.2, 0.2, 0.2), vec3(1,1,1),1.5,10.0));

    Light *l = new Light(vec3(2, 8, 10), vec3(0.3, 0.3, 0.3), vec3(0.7, 0.7, 0.7), vec3(1, 1, 1), 0.5, 0.01);
    s->lights.push_back(l);
    s->objects.push_back(sphere);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphere3);
    s->objects.push_back(sphere4);

    /*Animation *anim = new Animation();
    anim->transf = new Translate(vec3(0.2));
    sphere->addAnimation(anim);*/

    /*BoundaryObject *b = new BoundaryObject("/home/blaieet/Desktop/grafics/B07/RayTracingEstudiants_2/resources/peo1K.obj", new Metal(vec3(0.7,0.6,0.5), vec3(0.2, 0.2, 0.2), vec3(0.7, 0.7, 0.7),10.0));
    s->objects.push_back(b);*/
}

void SceneFactoryBasica::MoreSpheres(Scene *s) {

    Sphere * sphere1 = new Sphere(vec3(0, 0, -1), 0.5, new Lambertian(vec3(0.8, 0.8, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere * sphere2 = new Sphere(vec3(1,-1,-1), 0.5, new Lambertian(vec3(0.8, 0.8, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Sphere * sphere3 = new Sphere(vec3(-1, 0,-1), -0.45, new Lambertian(vec3(0.8, 0.8, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));

    s->objects.push_back(sphere1);
    s->objects.push_back(sphere2);
    s->objects.push_back(sphere3);

}

void SceneFactoryBasica::TwoPlanes(Scene *s) {

    //Afegeix dos planes, iguals (comentar un) pero amb materials diferents
    Plane *plane1 = new Plane(vec3(0,1,-4), vec3(-2,-2,-2), new Lambertian(vec3(0.8, 0.8, 0), vec3(0.2, 0.2, 0.2), vec3(1, 1, 1),10.0));
    Plane *plane2 = new Plane(vec3(0,1,-4), vec3(-2,-2,-2), new Metal(vec3(0.7,0.6,0.5), vec3(0.2,0.2,0.2), vec3(0.7,0.7,0.7), 10.0));

    s->objects.push_back((plane1));
    s->objects.push_back(plane2);

}
