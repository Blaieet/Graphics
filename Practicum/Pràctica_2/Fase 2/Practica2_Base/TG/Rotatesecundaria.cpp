#include "Rotatesecundaria.h"

RotateSecundaria::RotateSecundaria(float graus, vec3 axis): rotacio(axis)
{
    matTG = RotateX(graus * axis.x) * RotateY(graus * axis.y) * RotateZ(graus * axis.z);
}
