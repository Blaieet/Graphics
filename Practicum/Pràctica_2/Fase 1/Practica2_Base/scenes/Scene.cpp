#include "Scene.h"

/**
 * @brief Scene::Scene
 */
Scene::Scene() {
    // Inicialització de la capsa minima
    capsaMinima.pmin = vec3(-1.0, -1.0,-1.0);
    capsaMinima.a = 2;
    capsaMinima.h = 2;
    capsaMinima.p = 2;
    lightAmbientGlobal = vec3(0.2f);
}

/**
 * @brief Scene::~Scene
 */
Scene::~Scene() {
    elements.clear();
    lights.clear();
    delete camera;
}

/**
 * @brief Scene::addObject
 * @param obj
 */
void Scene::addObject(Object *obj) {
    elements.push_back(obj);
    calculCapsaMinCont3DEscena();
}

/**
 * @brief Scene::toGPU
 */
void Scene::toGPU(QGLShaderProgram *p) {
    setAmbientToGPU(p);
    lightsToGPU(p);
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->toGPU(p);
    }
}

/**
 * @brief Scene::draw
 */
void Scene::draw() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->draw();
    }
}

/**
 * @brief Scene::drawTexture
 */
void Scene::drawTexture() {
    for(unsigned int i=0; i < elements.size(); i++){
        elements.at(i)->drawTexture();
    }
}

/**
 * @brief Scene::getLightActual
 * @return
 */
Light* Scene::getLightActual() {
    // TO DO OPCIONAL: A modificar si es vol canviar el comportament de la GUI
    // Ara per ara dona com a Light actual la darrera que s'ha inserit
    return (lights[lights.size()-1]);
}

/**
 * @brief Scene::setLightActual
 * @param l
 */
void Scene::setLightActual(Light* l){
    lights[lights.size()-1]=l;
}



/**
 * @brief Scene::lightsToGPU
 * @param program
 */
void Scene::lightsToGPU(QGLShaderProgram *program){





    //s'utilitzarà un “vector” per que guardi un "struct" per a cada llum
    struct llums{
        GLuint position, direccio, angle;
        GLuint ambient, diffuse, specular;
        GLuint attenuacio;
        GLuint num;
    } llums[20];


    for (int i = 0; i < lights.size(); i++) {
        //gl_IdVect[ i ].ex1 = program->uniformLocation(QString("conjunt[%1]. exemple1").arg( i ));

        llums[i].position = program->uniformLocation(QString("BufferLlum[%1].posicio").arg(i));
        llums[i].direccio = program->uniformLocation(QString("BufferLlum[%1].direccio").arg(i));
        llums[i].angle = program->uniformLocation(QString("BufferLlum[%1].angle").arg(i));
        llums[i].ambient = program->uniformLocation(QString("BufferLlum[%1].ambient").arg(i));
        llums[i].diffuse = program->uniformLocation(QString("BufferLlum[%1].diffuse").arg(i));
        llums[i].specular = program->uniformLocation(QString("BufferLlum[%1].specular").arg(i));
        llums[i].attenuacio = program->uniformLocation(QString("BufferLlum[%1].attenuacio").arg(i));

        llums[i].num = program->uniformLocation(QString("BufferLlum[%1].num").arg(i));



        glUniform4fv(llums[i].position,1,lights[i]->posicio);
        glUniform4fv(llums[i].direccio,1,lights[i]->direccio);

        glUniform3fv(llums[i].ambient,1,lights[i]->ambient);
        glUniform3fv(llums[i].diffuse,1,lights[i]->diffuse);
        glUniform3fv(llums[i].specular,1,lights[i]->specular);
        glUniform1f(llums[i].angle,lights[i]->angle);
        glUniform3fv(llums[i].attenuacio,1,lights[i]->attenuacio);

        glUniform1i(llums[i].num,lights.size());
    }

}

void Scene::addLight(Light *l) {
    lights.push_back(l);

}

/**
 * @brief Scene::setAmbientToGPU
 * @param program
 */
void Scene::setAmbientToGPU(QGLShaderProgram *program){
    // TO DO: A implementar a la fase 1 de la practica 2
    GLuint globalAmbi = program->uniformLocation(QString("globalAmbient"));
    glUniform3fv(globalAmbi,1,this->lightAmbientGlobal);

}

/**
 * @brief Scene::setCamera
 * @param Camera *
 */
void Scene::setCamera(Camera *c) {
    camera = c;
}
/**
 * @brief Scene::calculCapsaMinCont3DEscena
 */

void Scene::calculCapsaMinCont3DEscena()
{
    Capsa3D c;
    vec3 pmax;

    if (elements.size()==1) {
        capsaMinima = elements[0]->calculCapsa3D();
        pmax[0] = capsaMinima.pmin[0]+capsaMinima.a;
        pmax[1] = capsaMinima.pmin[1]+capsaMinima.h;
        pmax[2] = capsaMinima.pmin[2]+capsaMinima.p;
    } else {
        capsaMinima.pmin[0]=200;
        capsaMinima.pmin[1]=200;
        capsaMinima.pmin[2]=200;
        pmax[0] = -200;
        pmax[1] = -200;
        pmax[2] = -200;
    }

    for (unsigned int i=0; i<elements.size(); i++) {
       c = elements[i]->calculCapsa3D();

       if (capsaMinima.pmin[0]>c.pmin[0]) capsaMinima.pmin[0] = c.pmin[0];
       if (capsaMinima.pmin[1]>c.pmin[1]) capsaMinima.pmin[1] = c.pmin[1];
       if (capsaMinima.pmin[2]>c.pmin[2]) capsaMinima.pmin[2] = c.pmin[2];
       if (pmax[0]<c.pmin[0]+c.a) pmax[0] = c.pmin[0]+c.a;
       if (pmax[1]<c.pmin[1]+c.h) pmax[1] = c.pmin[1]+c.h;
       if (pmax[2]<c.pmin[2]+c.p) pmax[2] = c.pmin[2]+c.p;
    }
    capsaMinima.a = pmax[0]-capsaMinima.pmin[0];
    capsaMinima.h = pmax[1]-capsaMinima.pmin[1];
    capsaMinima.p = pmax[2]-capsaMinima.pmin[2];
}

void Scene::update(int nframe) {
    for (unsigned int i = 0; i< elements.size(); i++) {
        if (dynamic_cast<Animable*>(elements[i]) ) elements[i]->update(nframe);
    }
}
