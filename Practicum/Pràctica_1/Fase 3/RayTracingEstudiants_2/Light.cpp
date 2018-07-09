#include "Light.h"

Light::Light(vec3 pos, vec3 ambi, vec3 diff, vec3 spec,float ate1, float ate2)
{
    position = pos;
    ambient = ambi;
    diffuse = diff;
    specular = spec;
    atenuacio1 = ate1;
    atenuacio2 = ate2;

}

Light::~Light() {

}

vec3 Light::getPos() {
    return position;
}

vec3 Light::getAmbi() {
    return ambient;
}

vec3 Light::getDiff() {
    return diffuse;
}

vec3 Light::getSpec() {
    return specular;
}

float Light::getAte1() {
    return atenuacio1;
}

float Light::getAte2() {
    return atenuacio2;
}

