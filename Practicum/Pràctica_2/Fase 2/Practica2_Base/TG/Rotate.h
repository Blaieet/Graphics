#ifndef ROTATE_H
#define ROTATE_H

#include "TG.h"


class Rotate : public TG
{
public:
    vec3 rot;
    Rotate(float graus, vec3 axis);
};

#endif // ROTATE_H
