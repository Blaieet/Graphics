#include "Light.h"

/**
 * @brief Light::Light
 * @param t
 */
Light::Light(LightType t) {
    this->diffuse = vec3(0.9f);
    this->specular = vec3(0.5f);
    this->ambient = vec3(0.2f);
    this->attenuacio = vec3(1.0f,0.0f,0.0f);
    setTipusLight(t);

}

/**
 * @brief Light::getDiffuseIntensity
 * @return
 */
vec3 Light::getId() {
    return this->diffuse;
}

/**
 * @brief Light::setId
 * @param i
 */
void Light::setId(vec3 i) {
    this->diffuse = i;

}

/**
 * @brief Light::getLightPosition
 */
vec4 Light::getLightPosition() {
    return this->posicio;
}

/**
 * @brief Light::setLightPosition
 * @param v
 */
void Light::setLightPosition(vec4 v) {
    this->posicio = v;
}


/**
 * @brief Light::getIa
 * @return
 */
vec3 Light::getIa() const
{
    return this->ambient;
}

/**
 * @brief Light::setIa
 * @param value
 */
void Light::setIa(const vec3 &value)
{
    this->ambient *= value;

}

/**
 * @brief Light::getIs
 * @return
 */
vec3 Light::getIs() const
{
    return this->specular;
}

/**
 * @brief Light::setIs
 * @param value
 */
void Light::setIs(const vec3 &value)
{
    this->specular *= value;
}

/**
 * @brief Light::getCoeficients
 * @return
 */
vec3 Light::getCoeficients() const
{
    return this->attenuacio;
}

/**
 * @brief Light::setCoeficients
 * @param value
 */
void Light::setCoeficients(const vec3 &value)
{
    this->attenuacio = value;
}


/**
 * @brief Light::getTipusLight
 *
 */
LightType Light::getTipusLight() const
{
    // TO DO: A canviar a la fase 1 de la practica 2
    if (this->angle != 0.0) { //Si te angle es Spotlight
        return Spot;
    } else if (this->posicio.x != 0.0 && this->posicio.y != 0.0 && this->posicio.z != 0.0
               && this->posicio.w != 0.0) {
        return Puntual;
    } else {
        return Direccional;
    }
}

/**
 * @brief Light::setTipusLight
 * @param value
 */
void Light::setTipusLight(const LightType &value)
{
    switch(value) {
        case Spot:
            this->posicio = vec4(-1.5,-1.5,1.0,0.0);
            this->direccio = vec4(1.0,0.0,1.0,0.0);
            this->angle = 0.45;
            break;
        case Direccional:
            this->posicio = vec4(0.5,0.5,1.0,0);
            this->direccio = vec4(1.0,0,1.0,0.0);
            this->angle = 0.0;
            break;
        case Puntual:
            this->posicio = vec4(0,30,0);
            this->direccio = vec4(0.0);
            this->angle = 0.0;
            break;
    }
}
