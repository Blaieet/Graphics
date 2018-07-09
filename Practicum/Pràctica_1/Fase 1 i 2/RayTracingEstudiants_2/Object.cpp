#include "Object.h"



Object::Object(Material *const mat)
  {
    material = mat;
  }

Object::~Object()
{
    // TO DO Fase 2: Quan s'incloguin nous materials, cal retocar aquest destructor
    if (dynamic_cast<Lambertian *>(material)) {
        delete (Lambertian *)material;
    } else if (dynamic_cast<Metal *>(material)) {
        delete (Metal *) material;
    } else if (dynamic_cast<Transparent *>(material)) {
        delete (Transparent *) material;
    }

}

