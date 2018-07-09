#include "Lambertian.h"

Lambertian::Lambertian(const vec3& color, const vec3& ambi, const vec3& spec, float shin): Material()
{
    diffuse = color;
    ambient = ambi;
    specular = spec;
    this->shineness = shin;

}

Lambertian::~Lambertian()
{
}

bool Lambertian::scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const  {
    vec3 target = rec.p + rec.normal + this->RandomInSphere();
    r_out.push_back( Ray(rec.p, target-rec.p));
    color = diffuse;
    //color += diffuse; //+ ?
    return true;
}

