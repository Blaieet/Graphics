#include "Transparent.h"

Transparent::Transparent(const vec3& color, const vec3& amb, const vec3& spec, float refraction, float shin):Material()
{
    diffuse = color;
    ambient = amb;
    specular = spec;
    transparent = vec3(1.0f);

    this->shineness = shin;
    this->refraction = refraction;
}

Transparent::~Transparent()
{}

//TRANSPARENT ORIGINAL (No funciona)

bool Transparent::scatter(const Ray &r_in, const HitInfo &rec, vec3 &color, std::vector<Ray> &r_out) const {
    vec3 normal = rec.normal;
    float N = (1.0f / refraction);

    if ((dot(normalize((rec.p - r_in.initialPoint())), normal)) > 0.0f) {
        N = (refraction / 1.0f);
        normal = -normal;
    }
    vec3 target = refract(normalize(rec.p - r_in.initialPoint()), normal, N);
    if (target.x == 0.0f && target.y == 0 && target.z == 0) {
        vec3 target = reflect(normalize(rec.p - r_in.initialPoint()), normal);
        r_out.push_back(Ray(rec.p, target));
        color += specular;
        return true;
    } else {
        r_out.push_back(Ray(rec.p, target));
        color += transparent;
        return true;
    }
}

