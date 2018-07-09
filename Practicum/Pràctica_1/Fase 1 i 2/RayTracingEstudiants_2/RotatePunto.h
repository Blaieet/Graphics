#ifndef ROTATEPUNTO_H
#define ROTATEPUNTO_H

#include "TG.h"

class RotatePunto : public TG
{
public:
    RotatePunto(glm::vec3 rot, float a);
    glm::vec3 rotate;
    float angle;
    ~RotatePunto();
};

#endif // ROTATEPUNTO_H
