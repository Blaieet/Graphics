#include "Triangle.h"



Triangle::Triangle(vec3 v1, vec3 v2, vec3 v3, Material *m) : Object(m)  {
    vtx1 = v1;
    vtx2 = v2;
    vtx3 = v3;
    normal = cross((v2 - v1), (v3 - v1));
}

void Triangle::aplicaTG(TG *t) {
    if (dynamic_cast<Translate *>(t)) {
        vec3 centroid(((vtx1.x + vtx2.x + vtx3.x)/3), ((vtx1.y + vtx2.y + vtx3.y)/3), ((vtx1.z + vtx2.z + vtx3.z)/3));

        vec4 v1(vtx1, 1.0);
        vec4 v2(vtx2, 1.0);
        vec4 v3(vtx3, 1.0);

        v1 = t->getTG() * v1;
        v2 = t->getTG() * v2;
        v3 = t->getTG() * v3;

        vtx1.x = v1.x; vtx1.y = v1.y; vtx1.z = v1.z;
        vtx2.x = v2.x; vtx2.y = v2.y; vtx2.z = v2.z;
        vtx3.x = v3.x; vtx3.y = v3.y; vtx3.z = v3.z;
    }
    if (dynamic_cast<Scale *>(t)) {
        vec3 centroid(((vtx1.x + vtx2.x + vtx3.x)/3), ((vtx1.y + vtx2.y + vtx3.y)/3), ((vtx1.z + vtx2.z + vtx3.z)/3));

        Translate *centre = new Translate(-centroid);

        this->aplicaTG(centre);

        vec4 v1(vtx1, 1.0);
        vec4 v2(vtx2, 1.0);
        vec4 v3(vtx3, 1.0);

        v1 = t->getTG() * v1;
        v2 = t->getTG() * v2;
        v3 = t->getTG() * v3;

        vtx1.x = v1.x; vtx1.y = v1.y; vtx1.z = v1.z;
        vtx2.x = v2.x; vtx2.y = v2.y; vtx2.z = v2.z;
        vtx3.x = v3.x; vtx3.y = v3.y; vtx3.z = v3.z;

        this->aplicaTG(new Translate(centroid));
    }

    if (dynamic_cast<Rotate *>(t)) {
        vec3 centroid(((vtx1.x + vtx2.x + vtx3.x)/3), ((vtx1.y + vtx2.y + vtx3.y)/3), ((vtx1.z + vtx2.z + vtx3.z)/3));
        Translate *centre = new Translate(-centroid);

        this->aplicaTG(centre);

        vec4 v1(vtx1, 1.0);
        vec4 v2(vtx2, 1.0);
        vec4 v3(vtx3, 1.0);

        v1 = t->getTG() * v1;
        v2 = t->getTG() * v2;
        v3 = t->getTG() * v3;

        vtx1.x = v1.x; vtx1.y = v1.y; vtx1.z = v1.z;
        vtx2.x = v2.x; vtx2.y = v2.y; vtx2.z = v2.z;
        vtx3.x = v3.x; vtx3.y = v3.y; vtx3.z = v3.z;
        this->aplicaTG(new Translate(centroid));

    }
    if (dynamic_cast<RotatePunto *>(t)) {
        //malament
        vec4 v1(vtx1, 1.0);
        vec4 v2(vtx2, 1.0);
        vec4 v3(vtx3, 1.0);

        v1 = t->getTG() * v1;
        v2 = t->getTG() * v2;
        v3 = t->getTG() * v3;

        vtx1.x = v1.x; vtx1.y = v1.y; vtx1.z = v1.z;
        vtx2.x = v2.x; vtx2.y = v2.y; vtx2.z = v2.z;
        vtx3.x = v3.x; vtx3.y = v3.y; vtx3.z = v3.z;
    }
}

void Triangle::aplicaTGObjecte(TG *t,vec3 cen) {

    vec4 v1(vtx1, 1.0);
    vec4 v2(vtx2, 1.0);
    vec4 v3(vtx3, 1.0);

    v1 = t->getTG() * v1;
    v2 = t->getTG() * v2;
    v3 = t->getTG() * v3;

    vtx1.x = v1.x; vtx1.y = v1.y; vtx1.z = v1.z;
    vtx2.x = v2.x; vtx2.y = v2.y; vtx2.z = v2.z;
    vtx3.x = v3.x; vtx3.y = v3.y; vtx3.z = v3.z;

}

bool Triangle::hit(const Ray& r, float t_min, float t_max, HitInfo& rec) const {

    float d = - dot(vtx1, normal);
    vec4 L = vec4(normal.x, normal.y, normal.z, d);
    vec4 Q = vec4(r.initialPoint().x, r.initialPoint().y, r.initialPoint().z, 1);
    vec4 V = vec4(r.dirVector().x, r.dirVector().y, r.dirVector().z, 0);

    float t = - dot(L, Q) / dot(L, V);
    vec3 p = (t * r.dirVector()) + r.initialPoint();

    float e1 = dot(cross((vtx3 - vtx1), (p - vtx1)), normal);
    float e2 = dot(cross((vtx2 - vtx3), (p - vtx3)), normal);
    float e3 = dot(cross((vtx1 - vtx2), (p - vtx2)), normal);

    if ((e1 < 0 && e2 < 0 && e3 < 0) || (e1 >= 0 && e2 >= 0 && e3 >= 0)){
        if (t < t_max && t > t_min) {
            rec.t = t;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = normal;
            rec.mat_ptr = material;
            return true;
        } else {
            rec.t = t;
            rec.p = r.pointAtParameter(rec.t);
            rec.normal = - normal;
            rec.mat_ptr = material;
            return false;
        }
    }

    return false;
}

