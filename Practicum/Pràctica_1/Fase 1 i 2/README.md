# B07

GiV - P1
----------  

## Abstract

En esta primera práctica hemos realizado el algorismo de RayTracing. Concretamente, hemos usado esta técnica para representar en una escena los fenómenos de "sombra" y "reflejos" de una luz.

En primer lugar, hemos creado distintos objetos geométricos (esfera, triangulo y plano) y hemos visto cómo se trata su intersección con nuestro "Ray". En segundo lugar, hemos añadido objetos .OBJ que están representados por mallas de triangulos. Finalmente, hemos programado algunas de sus correspondientes transformaciones geométricas: rotación, translación y escalamiento. 

La segunda fase es la que contiene el _quid_ de la práctica, ya que es donde se realiza la iluminación de la escena con al algoritmo de Blinn-Phong. Concretamente, primero hemos creado una clase _Light_, la cual trata la fuente de luz de nuestra escena. Segundo, hemos programado el algoritmo de Blinn-Phong. Este, es el responsable de dar color a la escena, teniendo en cuenta la luz presente en ella (y sus tres componentes) y los reflejos y sombras que derivan de su intersección con objectos.

Para estudiar mejor el comportameinto de la luz al interseccionar con objetos, hemos creado 2 materiales: Metal y Transparent. En consecuencia, hemos visto cómo "rebota" la luz en cada uno de ellos y su interacción junto al material "Lambertian" ya proporcionado.

Finalmente, hemos creado una escena final que integra los resultados de cada fase.

## Features

*(NOTA: Que partes habéis implementado y que miembro del grupo lo ha hecho. Editar la lista que tenéis a continuación añadiendo a continuación del item la persona que ha trabajado en el)*

- Figures
    - [ Jordi, Alex y Blai (en clase) ] Plane
    - [ Jordi y Blai ] Triangle
    - [ Jordi, Alex y Blai ] Sphere
    - [ Alex y Blai ] Boundary Object
- Blinn-Phong
    - [ Blai y Alex ] Light
    - [ Blai ] Basic Blinn-Phong
    - [ Jordi, Alex y Blai ] Recursive Blinn-Phong
- Material
    - [ Jordi ] Metal
    - [ Jordi ] Transparent
- Animaciones
    - [ Alex la de los .OBJ sobretodo, Jordi y Blai (y Alex) el resto ] aplicaTG i escenas

# Screenshots

* Las capturas estan en la carpeta "Screenshots" de este mismo repo

# Extensiones

* Hemos realizado la fuzzyness del metal. Para comprobarlo, hace falta descomentar las líneas presentes en el metodo scatter de la clase Metal.

# Respuesta a las preguntas del enunciado

* _Com calcularàs el centre del teuobjecte per a fer les rotacions en relació al seu centre?_

Esfera ya tiene centro. Con el triangulo, hemos decidido usar el baricentro, es decir, la suma de cada componente de cada vertice dividida entre 3. Con los objetos .OBJ, hemos encontrado el màximo y el mínimo de cada componente y la hemos dividido entre dos.

* _En el cas que hi hagi un objecte entre la llum i el punt on s'està calculant la il·luminació, quina component de la fórmula de Blinn-Phong s'haurà de tenir en compte?_

En la componente de la sombra. Al calcular el rayo, se tiene que multiplicar el punto de intersección por el lightvector, y no poner a infinito. De esta forma, si hay un objeto detrás de la luz, no nos hará sombra

* _On afegiries un atribut numSamples que defineixi el nombre de rajos per píxel i així controlar aquest fet?_

Lo hemos puesto como atributo de la clase Camara.

* _Aquest fet s'anomena Gamma Correction. Es tracta de fer l'arrel quadrada de cada canal del color just abans de pintar-lo. On faràs aquesta correcció?_

En la classe Render

* _Veuràs el material Lambertià dóna objectes molt rugosos donada l’aleatorietat del raig reflectit. com modificaries el mètode per a que donés més d'un raig reflectit ? Com el tractaries des del mètode ComputeColor?_

No lo hemos implementado, pero creemos que se deberían añadir más rayos para que ya no sea aleatorio, y luego tratarlo en el ComputeColor como tal.


_En afegir materials transparents, pots calcular les ombres segons el color del material transparent que traspassa la llum? Què has de modificar en la teva pràctica?_

Sí, es tan fácil como sumar (1-hitInfo-mat.ptr->kt) al resultado del color de Blinn Phong + la recursividad del metodo Compute Color.


 
# Additional Information
^^^^^^^^^^^^^^^^^^^^^^

No podemos aproximar las horas con exactitud pero seguro que hemos realizado más de 10 cada componente del grupo, por lo tanto, unas 30 horas conjuntas.

* La primera dificultad fue recordar las matemáticas detás de las transformaciones geométricas y convertirlas en código. De hecho, en los .OBJ alguna transformacion no acaba de salir del todo bien.

* La segunda dificultad fue la classe Transparent. En primer lugar, hacíamos comprobaciones innecesarias y en segundo lugar no tratábamos que reflect podía devolver zero. En consecuencia, esferas transparentes con componentes negativas no funcionaban ya que estábamos dividiendo por zero.

* La tercera dificultad y más grande, fue en la sombra. Causó que cada uno de nosotros empezará el proyecto de zero varias veces. Al final solo era un paréntesis: la componente sombra debe multiplicar la componente difosa y specular, y no era así ya que nos faltaba un paréntesis. Sin estos paréntesis, la esfera pequeña seguía siendo iluminada.

