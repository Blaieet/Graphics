#include "Scene.h"

float epsilon = 0.0001f;
const int MAXDEPTH = 10;

Scene::Scene()
{

}

Scene::~Scene()
{
    // TODO Fase 1: Quan s'incloguin nous objectes, cal retocar aquest destructor
    for(unsigned int i = 0; i < objects.size(); ++i){
        if(objects[i]){
            if (dynamic_cast<Sphere*>(objects[i]))
                    delete (Sphere *)(objects[i]);
            else if (dynamic_cast<Plane*>(objects[i]))
                    delete (Plane *)(objects[i]);
            else if (dynamic_cast<Triangle*>(objects[i]))
                    delete (Triangle *)(objects[i]);
            else if (dynamic_cast<BoundaryObject*>(objects[i]))
                    delete (BoundaryObject *)(objects[i]);
        }
        if (i < lights.size()) {
            if(lights[i]){
                delete (Light *)(lights[i]);
            }
        }

    }
    delete cam;
}

/*
** TODO: Metode que testeja la interseccio contra tots els objectes de l'escena (Fase 1)
**
** Si un objecte es intersecat pel raig, el parametre  de tipus IntersectInfo conte
** la informació sobre la interesccio.
** El metode retorna true si algun objecte es intersecat o false en cas contrari.
**
*/
bool Scene::hit(const Ray& raig, float t_min, float t_max, HitInfo& info) const {

    //return true;
    // TODO FASE 0 i FASE 1: Heu de codificar la vostra solucio per aquest metode substituint el 'return true'
    // Una possible solucio es cridar el mètode hit per a tots els objectes i quedar-se amb la interseccio
    // mes propera a l'observador, en el cas que n'hi hagi més d'una.
    // Cada vegada que s'intersecta un objecte s'ha d'actualitzar el HitInfo del raig,
    // pero no en aquesta funcio.
    bool h = false;
    float hit_min = t_max;
    HitInfo hitinfo;

    for (int i = 0; i < objects.size(); i++) {
        if (objects[i]->hit(raig, t_min, t_max, hitinfo)) {
            if (hitinfo.t < hit_min) {
                hit_min = hitinfo.t;
                info = hitinfo;
                h = true;
            }
        }
    }

    return h;
}


/*
** TODO: Funcio ComputeColor es la funcio recursiva del RayTracing.
** A modificar en la Fase 2 de l'enunciat per incloure Blinn-Phong  i ombres
** A modificar en la Fase 2 per a tractar reflexions i transparències
**
*/
vec3 Scene::ComputeColor (Ray &ray, int depth ) {

    vec3 color;
    vec3 ray2;
    vec3 c;
    std::vector<Ray> raigos;


    /* TODO Fase 0: Canviar segons les instruccions de l'enunciat
     * TODO Fase 2: Canviar aquesta assignacio pel color basat amb la il.luminacio basada amb Phong-Blinn segons
     * el material de l'objecte i les llums per la fase 2 de la practica
     * En aquesta fase 2,  cal fer que tambe es tinguin en compte els rebots de les reflexions.

       Inicialment s'ha posat la direccio del raig per tenir un color diferents per a cada pixel pero
       hitInfo ha d'anar tenint el color actualitzat segons els rebots.
    */


    ray2 = normalize(ray.direction);

    HitInfo hitinfo = HitInfo();
    bool hitted = hit(ray, epsilon, 1000, hitinfo);

    if (hitted && depth <= MAXDEPTH) {

        //CALCUL DEL RAIG QUE RETORNA
        c = vec3(0.0f);

        hitinfo.mat_ptr->scatter(ray, hitinfo, c, raigos);

        color = blinnPhong(hitinfo.p, hitinfo.normal, hitinfo.mat_ptr) + ComputeColor(raigos.back(), depth+1) * c;

    } else {
        color = vec3(0,0,0);
    }
    return color;
}

vec3 Scene::blinnPhong(vec3 puntInter, vec3 normal, const Material *material){
    vec3 color;
    vec3 lightVector;
    vec3 viewPoint;

    vec3 vectorMigH;
    float distancia;
    float aDescomptar;
    float fOmbra;

    //AmbientColor
    color =  this->ambient * material->ambient;
    for (int i = 0; i < lights.size(); i++) {
        lightVector = normalize(lights[i]->getPos() - puntInter);
        viewPoint = normalize(cam->origin - puntInter);
        vectorMigH = normalize(lightVector + viewPoint);

        //Intensitat Llum.
        //Norma del vector (Com de llarg es)
        distancia = sqrt(pow(lightVector.x, 2) + pow(lightVector.y, 2) + pow(lightVector.z, 2));
        aDescomptar = lights[i]->getAte1() + (lights[i]->getAte2() * pow(distancia,2));

        //Ombra
        fOmbra = 1.0f;
        Ray r = Ray(puntInter+0.01f*lightVector, lightVector);
        fOmbra = calculOmbra(r);

        //Part difosa
        float nDotL = dot(lightVector, normal);
        //angle
        nDotL = std::max(nDotL,0.0f);
        vec3 partDifosa = (lights[i]->getDiff() * material->diffuse) * nDotL;

        //Part Especular
        float nDotH = dot(vectorMigH, normal);
        //Angle
        nDotH = std::max(nDotH,0.0f);
        vec3 partSpecular = (lights[i]->getSpec() * material->specular) * pow(nDotH, material->shineness);


        color += aDescomptar * ((lights[i]->getAmbi() * material->ambient) + fOmbra * (partDifosa + partSpecular));

    }

    return color;

}

float Scene::calculOmbra(Ray& r) {
    HitInfo hi = HitInfo();
    bool hitted = hit(r, epsilon, 1000, hi);

    if(hitted) {
        return 0.0f;
    }
    return 1.0f;
}

void Scene::setAmbient(vec3 amb) {
    ambient = amb;
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i< objects.size(); i++) {
        if (dynamic_cast<Animable*>(objects[i]) ) objects[i]->update(nframe);
    }
}

