#include "Translate1.h"

Translate1::Translate1(vec3 trasl): traslation(trasl)
{
    //Find translate function in mat.h
    matTG = Translate(traslation);
}
