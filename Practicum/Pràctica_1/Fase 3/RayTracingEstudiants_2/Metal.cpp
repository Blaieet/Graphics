#include "Metal.h"

Metal::Metal(const vec3& color, const vec3& ambi, const vec3& spec, float shin):Material()
{
    diffuse = color;
    ambient = ambi;
    specular = spec;
    transparent = vec3(0.0f);

    this->shineness = shin;

}

Metal::~Metal()
{}

bool Metal::scatter(const Ray &r_in, const HitInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {

    //Si es vol fuzzyness, descomentar:

    float fuzz = drand48();
    vec3 target = reflect(normalize(rec.p - r_in.initialPoint()), rec.normal) + vec3(fuzz) * this->RandomInSphere();
    //vec3 target = reflect(normalize(rec.p - r_in.initialPoint()), rec.normal);
    r_out.push_back(Ray(rec.p, target));
    color += specular;
    return true;
}
