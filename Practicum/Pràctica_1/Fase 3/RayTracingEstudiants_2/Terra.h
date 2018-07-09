#ifndef TERRA_H
#define TERRA_H


#include "Object.h"
#include "Animation.h"
#include "Translate.h"
#include "Scale.h"
#include "RotatePunto.h"
#include "Sphere.h"

class Terra: public Object
{
public:
    Terra(vec3 cen, float r, Material *m,Sphere* t);
    virtual bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;

    virtual void aplicaTG(TG *t);
    vec3 center;
    Sphere *terra;

private:

        float radius;
};

#endif // TERRA_H


