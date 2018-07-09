#ifndef MATERIAL_H
#define MATERIAL_H

#include "./library/Common.h"
#include <QGLShaderProgram>


// TO DO: A canviar a la fase 1 de la practica 2
// Classe que representa els materials d'un objecte
class Material {


public:
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    GLfloat shineness;

    Material(vec3 diffuse, vec3 ambient, vec3 specular, GLfloat shineness);
    Material();

    void toGPU(QGLShaderProgram *program);

private:
    struct {
        GLuint ka;
        GLuint kd;
        GLuint ks;
        GLfloat shin;
    } MaterialGL;
};

#endif // MATERIAL_H
