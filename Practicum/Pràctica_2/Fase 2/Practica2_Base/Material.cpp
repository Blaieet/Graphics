#include "Material.h"


Material::Material(vec3 dif, vec3 amb, vec3 spe, GLfloat shi)
{
    this->diffuse = dif;
    this->ambient = amb;
    this->specular = spe;
    this->shineness = shi;
}

Material::Material()
{
    this->diffuse = vec3(0.0f,0.9f,0.0f);
    this->ambient = vec3(0.1f);
    this->specular = vec3(1.0f);
    this->shineness = 20.0f;
}

/**
 * Passa el material de CPU a GPU
 * @brief Material::toGPU
 * @param program
 */
void Material::toGPU(QGLShaderProgram *program)
{
    MaterialGL.kd = program->uniformLocation("Material.diffuse");
    MaterialGL.ka = program->uniformLocation("Material.ambient");
    MaterialGL.ks = program->uniformLocation("Material.specular");
    MaterialGL.shin = program->uniformLocation("Material.shineness");

    glUniform3fv(MaterialGL.kd, 1, this->diffuse);
    glUniform3fv(MaterialGL.ka, 1, this->ambient);
    glUniform3fv(MaterialGL.ks, 1, this->specular);
    glUniform1f(MaterialGL.shin, this->shineness);

}

