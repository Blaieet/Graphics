#include "RotatePunto.h"
#include <iostream>

RotatePunto::RotatePunto(glm::vec3 rot, float a): rotate(rot), angle(a)
{
    matTG = glm::rotate(glm::mat4(1.0f), angle, rotate);
    //glm::rotate_slow

}


RotatePunto::~RotatePunto(){

}
