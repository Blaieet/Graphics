#include "TG.h"

TG::TG()
{
// matTG = mat4();
}

TG::~TG()
{
    //matTG = mat4(1.0f);
}

mat4 TG::getTG() {
    return matTG;
}
