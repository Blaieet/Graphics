#include "Scale1.h"

Scale1::Scale1(vec3 s) : scal(s)
{
    matTG = Scale(s);
}
