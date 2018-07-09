
#include "Plane.h"

Plane::Plane(vec3 norm, vec3 punt, Material *m) : Object(m)  {
    normal = norm;
    puntp = punt;
}

void Plane::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {
        // Per ara només es preveuen translacions
        vec4 c(puntp, 1.0);
        c = t->getTG() * c;
        puntp.x = c.x; puntp.y = c.y; puntp.z = c.z;
    }if (dynamic_cast<Rotate *>(t)){
        vec4 c(puntp, 1.0);
        c = t->getTG() * c;
        puntp.x = c.x; puntp.y = c.y; puntp.z = c.z;
    }


}

bool Plane::hit(const Ray& r, float t_min, float t_max, HitInfo& rec) const {

    // dot --> producte escalar, si 0: perpendiculars
    float intersection = dot(r.dirVector(), normal);

    // Mirem que el pla no estigui en paralel al raig
    if (intersection != 0) {

        float temp = dot((puntp - r.initialPoint()), normal) / intersection;

        if (temp < t_max && temp > t_min) {
            if (dot(normal, r.dirVector()) > 0) {
                rec.t = temp;
                rec.p = r.pointAtParameter(rec.t);
                rec.normal = - normal;
                rec.mat_ptr = material;
                return true;
            } else {
                rec.t = temp;
                rec.p = r.pointAtParameter(rec.t);
                rec.normal = normal;
                rec.mat_ptr = material;
                return true;
            }
        }
    }

    return false;
}
