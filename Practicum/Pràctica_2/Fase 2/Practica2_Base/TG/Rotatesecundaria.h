#ifndef ROTATESECUNDARIA_H
#define ROTATESECUNDARIA_H

#include "TG.h"

class RotateSecundaria : public TG
{
public:
    vec3 rotacio;
    RotateSecundaria(float graus, vec3 axis);
};

#endif // ROTATESECUNDARIA_H
