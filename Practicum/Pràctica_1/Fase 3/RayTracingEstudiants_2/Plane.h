
#ifndef PLANE_H
#define PLANE_H

#include "Object.h"
#include "Translate.h"
#include "Rotate.h"

class Plane: public Object {
public:
    Plane(vec3 norm, vec3 punt, Material *m);
    ~Plane() {}
    bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
    virtual void aplicaTG(TG *t);

private:
    // La normal del pla
    vec3 normal;
    // Punt del pla
    vec3 puntp;
};

#endif // PLANE_H
