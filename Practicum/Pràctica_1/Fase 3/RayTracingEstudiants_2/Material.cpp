#include "Material.h"



Material::Material():
    diffuse(1.0f),
    ambient(1.0f),
    specular(1.0f),
    transparent(0.0f)
  { shineness = 0.0f; }

Material::~Material()
{}

vec3 Material::RandomInSphere() const {
    vec3 p;
    do {
        p = 2.0f*vec3(drand48(),drand48(),drand48()) - vec3(1,1,1);
    } while (glm::length(p) >=  1.0f);
    return p;
}

