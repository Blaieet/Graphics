#ifndef METAL_H
#define METAL_H

#include "Material.h"

class Metal: public Material
{
public:
    Metal(const vec3& color, const vec3& ambi, const vec3& spec, float shin);
    virtual ~Metal();
    virtual bool scatter(const Ray& r_in, const HitInfo& rec, vec3& color, std::vector<Ray>& r_out) const;
};

#endif // METAL_H
