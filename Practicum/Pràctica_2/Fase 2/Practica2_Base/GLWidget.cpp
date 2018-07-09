#include <math.h>
#include <QtDebug>
#include <QString>
#include "GLWidget.h"
#include "./animations/Animation.h"


GLWidget::GLWidget(QWidget *parent) : QGLWidget(QGLFormat(QGL::SampleBuffers), parent) {

    setFocusPolicy( Qt::StrongFocus );
    scene = new Scene();
    scene->setCamera(new Camera(this->size().width(), this->size().height()));
    emit ObsCameraChanged(scene->camera);
    emit FrustumCameraChanged(scene->camera);
}

GLWidget::GLWidget(const QGLFormat &glf, QWidget *parent) : QGLWidget(glf, parent) {

    setFocusPolicy( Qt::StrongFocus );
    scene = new Scene();
    scene->setCamera(new Camera(this->size().width(), this->size().height()));
    emit ObsCameraChanged(scene->camera);
    emit FrustumCameraChanged(scene->camera);
}
GLWidget::~GLWidget() {
    makeCurrent();
    delete scene;
}

/* Interacció amb GL i inicialització de shaders */

/**
 * @brief GLWidget::initializeGL()
 */
void GLWidget::initializeGL() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_RGBA);
    glEnable(GL_DOUBLE);

    qglClearColor(QColor(0,199,140));

    initShadersGPU();

    // Creacio d'una Light per apoder modificar el seus valors amb la interficie
    Light *l = new Light(Puntual);
    scene->addLight(l);
    Light *ll = new Light(Direccional);
    scene->addLight(ll);


    scene->camera->init(this->size().width(), this->size().height(), scene->capsaMinima);

    scene->toGPU(program);
    emit ObsCameraChanged(scene->camera);
    emit FrustumCameraChanged(scene->camera);

    glViewport(scene->camera->vp.pmin[0], scene->camera->vp.pmin[1], scene->camera->vp.a, scene->camera->vp.h);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

}

/**
 * @brief GLWidget::paintGL()
 */
void GLWidget::paintGL() {
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    scene->camera->toGPU(program);
    scene->draw();
}

/**
 * @brief GLWidget::resizeGL()
 */
void GLWidget::resizeGL(int width, int height) {

    glViewport(scene->camera->vp.pmin[0], scene->camera->vp.pmin[1], scene->camera->vp.a, scene->camera->vp.h);

    scene->camera->vp.a = width;
    scene->camera->vp.h = height;

    scene->camera->CalculaWindow(scene->capsaMinima);

    updateGL();
}

/**
 * @brief GLWidget::initShadersGPU
 */
void GLWidget::initShadersGPU(){


    initShader("://resources/vphongShaderTex.glsl","://resources/fphongShaderTex.glsl",2);
    initShader("://resources/vshader1Goraud.glsl", "://resources/fshader1Goraud.glsl",0);
    initShader("://resources/vphongShader.glsl", "://resources/fphongShader.glsl",1);
    initShader("://resources/vToonShader.glsl","://resources/fToonShader.glsl",3);

    //Textures + Goraud Shading.
    initShader("://resources/vshader1GoraudTex.glsl", "://resources/fshader1GoraudTex.glsl",4);
    initShader("://resources/vphongShaderTex.glsl","://resources/fphongShaderTex.glsl",2);



}

QSize GLWidget::minimumSizeHint() const {
    return QSize(50, 50);
}

QSize GLWidget::sizeHint() const {
    return QSize(400, 400);
}

/**
 * @brief GLWidget::initShader()
 * Compila i linka el vertex i el fragment shader
 */
void GLWidget::initShader(const char* vShaderFile, const char* fShaderFile,int numprog){
    QGLShader *vshader = new QGLShader(QGLShader::Vertex, this);
    QGLShader *fshader = new QGLShader(QGLShader::Fragment, this);

    vshader->compileSourceFile(vShaderFile);
    fshader->compileSourceFile(fShaderFile);

    programes[numprog] = new QGLShaderProgram(this);
    programes[numprog] = new QGLShaderProgram(this);
    programes[numprog]->addShader(vshader);
    programes[numprog]->addShader(fshader);
    programes[numprog]->link();
    programes[numprog]->bind();
    program = programes[numprog];
}

/** Gestio de les animacions i la gravació d'imatges ***/

void GLWidget::setCurrentFrame(){

    scene->update(currentFrame);
    updateGL();
    this->saveFrame();
    currentFrame++;

    if (currentFrame == MAXFRAMES)
        timer->stop();

}

void GLWidget::saveFrame(){
    this->grabFrameBuffer().save("screen_output_"+QVariant(currentFrame).toString()+".jpg");
}

void GLWidget::saveImage(){

    this->grabFrameBuffer().save("screen_output_"+QVariant(currentImage).toString()+".jpg");
    currentImage++;
}

/** Metodes que es criden des dels menús */


void GLWidget::newObj(QString fichero){

    qDebug() << fichero;
    Object * obj = new Object(100000, fichero);
    obj->toGPU(program);
    scene->addObject(obj);
    scene->camera->actualitzaCamera(scene->capsaMinima);

    emit ObsCameraChanged(scene->camera);
    emit FrustumCameraChanged(scene->camera);

    updateGL();
}

void GLWidget::newScene() {
    // creació de la nova Scena
    // Cal modificar si voleu afegir més escenes amb les factory

    //SceneFactory *sf = new SceneFactoryBasica();
    SceneFactory *sf = new FactoryConcurso();
    scene = sf->createScene();

    scene->toGPU(program);

    // Podeu Utilitzar l'altre constructor de Camera
    // per inicialitzar els parametres de la camara.
    scene->setCamera(new Camera(this->size().width(), this->size().height()));
    scene->camera->actualitzaCamera(scene->capsaMinima);
    scene->camera->setFrustum(171,0.01,100);

    emit ObsCameraChanged(scene->camera);
    emit FrustumCameraChanged(scene->camera);

    updateGL();

}


void GLWidget::saveAnimation() {
    // Comença el timer de l'animació
    timer = new QTimer(this);
    currentFrame=0;
    currentImage=0;
    connect(timer, SIGNAL(timeout()), this, SLOT(setCurrentFrame()));
    timer->start(10);

}

void GLWidget::activaToonShader() {
    //A implementar a la fase 1 de la practica 2
    qDebug()<<"Estic a Toon";

    program = programes[3];
    program->bind();
    scene->toGPU(program);
    updateShader();
}

void GLWidget::activaPhongShader() {
    //Opcional: A implementar a la fase 1 de la practica 2
    qDebug()<<"Estic a Phong";
    program = programes[1];
    program->bind();
    scene->toGPU(program);
    updateShader();



}

void GLWidget::activaGouraudShader() {
    qDebug()<<"Estic a Gouraud";
    program = programes[0];
    program->bind();
    scene->toGPU(program);
    updateShader();
}

void GLWidget::activaPhongTex() {
    //A implementar a la fase 1 de la practica 2
    qDebug()<<"Estic a Phong Tex";
    program = programes[2];
    program->bind();
    scene->toGPU(program);
    updateShader();
}

void GLWidget::activaGouraudTex() {
    qDebug()<<"Estic a Goraud Tex";
    program = programes[4];
    program->bind();
    scene->toGPU(program);
    updateShader();
}

void GLWidget::activaBackground() {
    //A implementar a la fase 2 de la practica 2
    qDebug()<<"Estic a Background";

}
void GLWidget::activaBumpMapping() {
    //TO DO: a implementar a la fase 2 de la practica 2
     qDebug()<<"Estic a Bump Mapping";
}

void GLWidget::activaEnvMapping() {
    //TO DO: a implementar a la fase 2 de la practica 2
    qDebug()<<"Estic a Environmental Mapping";
}

void GLWidget::activaTransparency() {
    //TO DO: a implementar a la fase 2 de la practica 2
    qDebug()<<"Estic a Transparencia";
}

//Metode  per canviar de shaders.
void GLWidget::updateShader(){
    //A implementar a la fase 1 de la practica 2

    updateGL();
}

//Metode per canviar de shaders de textures
void GLWidget::updateShaderTexture(){
    //A implementar a la fase 1 de la practica 2

}

/** Mètodes que es criden des de les finestres de dialeg */

void GLWidget::setRotation(float angle, float x, float y, float z)
{
    // Rotació en coordenades de mon que es farà sobre l'escena carregada

}
void GLWidget::setTranslation(float x, float y, float z)
{
    // Translació en coordenades de mon que es farà sobre l'escena carregada

}

void GLWidget::setScale(float s)
{
    // Escala en coordenades de mon que es  farà sobre l'escena carregada
}


void GLWidget::setPerspective(float verticalAngle, float nearPlane, float farPlane)
{
    scene->camera->setFrustum(verticalAngle, nearPlane, farPlane);

    updateGL();
}

void GLWidget::setLookAt(const QVector3D &eye, const QVector3D &center, const QVector3D& up)
{
    vec4 lookfrom(eye[0], eye[1], eye[2], 1.0);
    vec4 lookat(center[0], center[1], center[2], 1.0);
    vec4 vup(up[0], up[1], up[2], 1.0);
    scene->camera->setObservador(lookfrom, lookat, vup);

    updateGL();
}

void GLWidget::setLighting(const QVector3D &lightPos, const QVector3D &Ia, const QVector3D &Id,
                           const QVector3D &Is, const QVector3D &coefs)
{
    vec4 lightPosition(lightPos[0],lightPos[1], lightPos[2], 1.0) ;
    vec3 intensityA( Ia[0], Ia[1], Ia[2]);
    vec3 intensityD( Id[0], Id[1], Id[2]);
    vec3 intensityS( Is[0], Is[1], Is[2]);

    scene->lights[0]->setIa(intensityA);
    scene->lights[0]->setId(intensityD);
    scene->lights[0]->setIs(intensityS);
    scene->lights[0]->setLightPosition(lightPosition);
    updateGL();
}

void GLWidget::setTextureFile(const QString &file)
{
    QOpenGLTexture *texture;

    texture = new QOpenGLTexture(QImage(file).mirrored());
    // TO DO: A modificar en la fase 1 de la practica 2
    // Per ara es posa la textura al primer objecte de l'escena
    scene->elements[0]->setTexture(texture);


}

/**  Mètodes d'interacció amb el ratolí */

void GLWidget::mousePressEvent(QMouseEvent *event)
{
    lastPos = event->pos();
}

void GLWidget::mouseMoveEvent(QMouseEvent *event)
{
    int dx = event->x() - lastPos.x();
    int dy = event->y() - lastPos.y();

    if (event->buttons() & Qt::LeftButton)
    {
        if(lastPos.y()!= event->y() && lastPos.x()!= event->x()) {
           setXRotation(dy);
           setYRotation(dx);
        } else if(lastPos.y()!= event->y()) {// rotar la camera
            setXRotation(dy);
        } else if (lastPos.x()!= event->x()) {
            setYRotation(dx);
        }

    } else if (event->buttons() & Qt::RightButton) {
       // Zoom: canviar la mida de la window
        if(lastPos.y()> event->y())
             Zoom(-1);
        else
             Zoom(1);
    }

    lastPos = event->pos();
}


void GLWidget::setXRotation(int angle)
{
    if (angle >0) {
        scene->camera->angX += 5;
    } else if (angle<0)
        scene->camera->angX -= 5;
    qNormalizeAngle(scene->camera->angX);

    scene->camera->rotaCamera();

    emit ObsCameraChanged(scene->camera);

    updateGL();
}

void GLWidget::setYRotation(int angle)
{
    if (angle >0) {
        scene->camera->angY += 5;
    } else if (angle<0)
        scene->camera->angY-= 5;
    qNormalizeAngle(scene->camera->angY);

    scene->camera->rotaCamera();

    emit ObsCameraChanged(scene->camera);

    updateGL();
}

void GLWidget::qNormalizeAngle(double &angle)
{
    while (angle < 0)
        angle += 360*16;
    while (angle > 360)
        angle -= 360*16;
}

void GLWidget::Zoom (int positiu) {
    scene->camera->AmpliaWindow(positiu*(0.005));

    emit FrustumCameraChanged(scene->camera);

    updateGL();
}

