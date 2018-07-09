# B07

GiV - P1
----------  

## Abstract

En esta segunda parte de las prácticas nos hemos centrado en las visualizaciones proyectivas (Z-Buffer) programando la targeta gráfica usando shaders con GLSL.

Programando la targeta gráfica directamente conseguimos evitar las transferencias de memoria entre los procesadores de la GPU y la CPU, optimizando el tiempo de visualización.
En esta gráfica se manipula la geometria de los objetos y/o los colores de la imagen.

En nuestro trabajo hemos implementado la iluminación de escena con diferentes modelos locales de shading: Gouraud, Phong y Toon.
También hemos implementado la funcionalidad de las texturas, podiendo aplicar así a cualquier objeto compuesto por triangulos una textura determinada, eso sí, con una serie de restricciones como que las coordenadas tienen que ser potencias de 2.


## Features

*(NOTA: Que partes habéis implementado y que miembro del grupo lo ha hecho. Editar la lista que tenéis a continuación añadiendo a continuación del item la persona que ha trabajado en el)*

- Classes Llum i Material
    - [ Blai, Alex, Jordi ] 
- Shading
    - [ Blai, Alex, Jordi ] Gouraud
    - [ Blai, Alex, Jordi ] Phong
    - [ Blai ]              Toon
- Textures
    - [ Blai, Alex, Jordi ]

# Screenshots

* Las capturas estan en la carpeta "Screenshots" de este mismo repo

# Extensiones

Las partes opcionales realizadas son:

* Tipo de luz Spotlight: funciona tanto con Goraud o Phong, además de con o sin texturas. 

* Toon shading: hemos realizado su correspondiente Vertex y Fragment Shader

* Texturas con Gouraud Shading. Para activarlas, hemos creado una opción extra en el menú de la ventana del programa, llamada GoraudTex

* Un 'if' que controla si el objeto pasado tiene o no las coordenadas de las texturas en el. De esta forma, evitamos que el programa "pete" si no las tiene cargadas.

# Respuesta a las preguntas del enunciado

* _Pots explicar per què l'interior de cada triangle es veu
de diferents colors?_
Perquè calcula el color segons les normals.
* _En el vector de llums posa una llum de cada tipus i comprova que es passen bé els tres tipus de llums. Què contindrà el "struct" de la GPU?_
``` struct llums {
    vec4 posicio;
    vec4 direccio;
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float angle;
    vec3 attenuacio;
    int num;
};
```
* _Passa la posició de l'observador de la classe càmera a la GPU per a poder fer el càlcul del vector H. En la classe Camera utilitza el mètode toGPU per a passar l'observador als shaders per a que es passi la posició de l'observador cada vegada que s'actualitza la posició de la càmera amb el ratolí. Com serà aquesta variable al shader? Uniform? O IN?_
```
uniform vec4 obs
```
* _Si vols utilitzar diferents shaders en temps d'execució raona on s'inicialitzaran els shaders i com controlar quin shader s'usa? Cal tornar a passar l'escena a la GPU quan es canvia de shader? I també la càmera?_
Els shaders s'inicialitzen amb el mètode initShadersGPU de la classe GLWidget. Per controlar el tipus de shader que s'utilitza tenim un array de programes del qual seleccionem el shader que necessitem en cada moment. En crear la finestra i carregar un objecte s'en carrega un per defecte i després segons l'opció seleccionada al menú es va canviant.
Al seleccionar una determinada opció el que fem es carregar el programa adecuat i cridem el mètode bind(), passem la nova escena a la gpu  i cridem a updateGL(). No cal tornar a passar la càmara.

* _Implementa el Phong-shading quan es premi la tecla Alt+2. Quina diferència hi ha amb el Gouraud-shading? On l'has de codificar? Necessites uns nous vertex-shader i fragment-shader?_
En Phong cada polígon representat té un vector normal per vèrtex; la iluminació es realitza interpolant els vectors de la superfície i calculant el color per a cada punt d'interès. Per això realitzem els càlculs al fragment shader.
En Gourard cada polígon té un vector normal per vèrtex, però en lloc d'interpolar els vectors, el color de cada vèrtex es calcula i s'interpola a través de la superfície del polígon. Realitzem els càlculs al vertex shader.
La diferencia de codificació entre els dos ha estat mínima, canviar el codi del vertex al fragment shader per Phong i modificar les variables entrada i sortida.



 
# Additional Information
^^^^^^^^^^^^^^^^^^^^^^

Esta practica nos ha llevado aproximadamente entre 5 o 10 horas por cada componente del grupo, asi que diriamos que en total unas 30 o 20 horas en total. Concretamente, la parte que nos ha llevado más tiempo fue el primer shading (Goraud) con su correspondiente paso de las normales. Más que nada, lo complicado fue entender el formato del código, no la teoria detrás de Goraud.

* La primera dificultad, por lo tanto, fue como se hacía el paso de CPU a GPU. Con Material no tubimos mucho problema, pero con las luzes ya era otra cosa. Había un error en el código que nos llevo un buen tiempo: era _BufferLlum[%1].posicio_ y no _BufferLlum[% i ].posicio_.

* La segunda dificultad fue el paso de las normales. No entendíamos el metodo _make_ de Object.cpp y sus correspondintes buffers.

* Finalmente, la última dificultad fue el paso de coordenadas de Texturas, porque pensábamos que había algo mal en el código cuando en verdad era que no todos los _.obj_ que había en _resources_ tenían sus coordenadas en él.


