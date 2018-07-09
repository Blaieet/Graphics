#include "Render.h"


void Render::setScene(Scene *s) {
    scene = s;
}

// Metode Render

// Aquesta funcio transforma cada pixel a coordenades de mon i
// envia un raig des de la camera en aquella direccio cridant al metode CastRay
// i pel pintar la imatge final:
// 1) Neteja la pantalla per a visualitzar el nou frame
// 2) Envia un raig a l'escena per a cada pixel de la pantalla i utilitza el color retornat per a pintar el pixel
// 3) Actualitza la sortida corresponent segons la implementació del mètode setPixelColor de cada fill

//Precondicio:
// La Scene ha d'estar creada i inicialitzada

void Render::rendering() {
    // Recorregut de cada pixel de la imatge final
    for (int y = scene->cam->viewportY-1; y >= 0; y--) {
         for (int x = 0; x < scene->cam->viewportX; x++) {
            vec3 col(0, 0, 0);
            float u,v;

            for (int i = 0; i < scene->cam->numSamples; i++) {
                float u = float(x) / float(scene->cam->viewportX);
                float v = float(y) / float(scene->cam->viewportY);

                Ray r = scene->cam->getRay(u, v);
                col += scene->ComputeColor(r,0);
                //setPixelColor(col, x, y);
            }
            //Calculate mean color for pixel 'x' and 'y'
            col = col / vec3(scene->cam->numSamples);
            //Performing Gamma-Correction
            col.x = sqrt(col.x);
            col.y = sqrt(col.y);
            col.z = sqrt(col.z);
            setPixelColor(col, x, y);
         }
    }
}

void Render::exitRender() {
    cleanup();
}

void Render::cleanup() {
    if (scene!=NULL)  delete scene;
}

// Metode de suport que fa el rendering per a tots els Renders que no usen GLUT
void Render::startRendering(int argc, char **argv) {
    renderingScene();
}

void Render::renderingScene()  {
    initRender("resultat.ppm");
    rendering();
    exitRender();
}

