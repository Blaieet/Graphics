#include "RotatePunto.h"
#include <iostream>

RotatePunto::RotatePunto(glm::vec3 rot,glm::vec3 punt, float a): rotate(rot), angle(a),punt(punt)
{
    matTG = glm::rotate(glm::mat4(1.0f), angle, rotate);
    //glm::rotate_slow

}

glm::vec3 RotatePunto::getPunt(){
    return punt;
}

RotatePunto::~RotatePunto(){

}
