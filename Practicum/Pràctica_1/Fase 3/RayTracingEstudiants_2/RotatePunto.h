#ifndef ROTATEPUNTO_H
#define ROTATEPUNTO_H

#include "TG.h"

class RotatePunto : public TG
{
public:
    RotatePunto(glm::vec3 rot,glm::vec3 punt, float a);
    glm::vec3 getPunt();
    glm::vec3 rotate;
    glm::vec3 punt;
    float angle;
    ~RotatePunto();
};

#endif // ROTATEPUNTO_H
