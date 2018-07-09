#ifndef TRANSPARENT_H
#define TRANSPARENT_H

#include "Material.h"

class Transparent: public Material
{
public:
    Transparent(const vec3& color, const vec3& amb, const vec3& spec, float ref, float shin);
    virtual ~Transparent();
    virtual bool scatter(const Ray &r_in, const HitInfo &rec, vec3 &color, std::vector<Ray> &r_out) const;

    float refraction;
};

#endif // TRANSPARENT_H
