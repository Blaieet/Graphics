#ifndef LIGHT_H
#define LIGHT_H

#include "glm/glm.hpp"
using namespace glm;

class Light
{
public:
    Light(vec3 posicio, vec3 ambient, vec3 diffuse, vec3 specular, float ate1, float ate2);
    ~Light();
    vec3 getPos();
    vec3 getAmbi();
    vec3 getDiff();
    vec3 getSpec();
    float getAte1();
    float getAte2();

private:
    vec3 position, ambient, diffuse, specular;
    float atenuacio1, atenuacio2;

};

#endif // LIGHT_H
