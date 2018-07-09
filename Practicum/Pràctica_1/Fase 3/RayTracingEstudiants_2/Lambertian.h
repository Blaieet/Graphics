#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H

#include "Material.h"

class Lambertian : public Material
{

public:
    Lambertian(const vec3& color, const vec3& ambi, const vec3& spec, float shin);
    virtual ~Lambertian();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const;

};

#endif // LAMBERTIAN_H
