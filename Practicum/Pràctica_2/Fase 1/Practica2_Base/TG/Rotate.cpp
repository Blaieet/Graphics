#include "Rotate.h"

Rotate::Rotate(float graus, vec3 axis)
{
    matTG = RotateX(graus* axis.x) * RotateY(graus*axis.y) *
            RotateZ(graus * axis.z);

}
