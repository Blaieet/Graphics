#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Object.h"
#include "Translate.h"
#include "Scale.h"
#include "math.h"
#include "Rotate.h"

#include "RotatePunto.h"

class Triangle: public Object {
public:
    Triangle(vec3 v1, vec3 v2, vec3 v3, Material *m);
    ~Triangle() {}
    bool hit(const Ray& r, float t_min, float t_max, HitInfo& info) const;
    virtual void aplicaTG(TG *t);
    void aplicaTGObjecte(TG *t,vec3 cen);

private:
    // Centre del triangle
    vec3 vtx1, vtx2, vtx3;
    // Normal del triangle
    vec3 normal;
};


#endif // TRIANGLE_H
