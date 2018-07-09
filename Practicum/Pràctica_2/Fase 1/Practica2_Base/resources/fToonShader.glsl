#version 330

in vec4 pos;
in vec4 norm;

uniform mat4 model_view;
uniform mat4 projection;

out vec4 color;

struct llums {
    vec4 posicio;
    vec4 direccio;
    vec3 diffuse;
    vec3 ambient;
    vec3 specular;
    float angle;
    vec3 attenuacio;
    int num;
};


uniform llums BufferLlum[20];

void main()

{

    vec3 colorG = vec3(0.0f);
    for (int i = 0; i < BufferLlum[0].num; i++) {

        //Llum direccional que apunta al origen de coordenades
        float intensitat = dot(normalize(BufferLlum[i].posicio.xyz),norm.xyz);

        if (intensitat > 0.95) {
            colorG = vec3(0.5f, 1.0f, 0.5f);
        }else if (intensitat > 0.5) {
            colorG = vec3(0.3f, 0.6f, 0.3f);
        }else if (intensitat > 0.25) {
            colorG = vec3(0.2f, 0.4f, 0.2f);
        } else {
            colorG = vec3(0.1f, 0.2f, 0.1f);
        }
    }
    color = vec4(colorG,1.0f);
}


//GURU = Color de cada normalize
//Phong = Normal de cada vertex
