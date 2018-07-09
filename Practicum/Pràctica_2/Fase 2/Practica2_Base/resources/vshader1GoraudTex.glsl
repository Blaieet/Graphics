#version 330



layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 normals;
layout (location = 2) in vec2 vCoords;



uniform mat4 model_view;
uniform mat4 projection;


out vec4 color;
out vec2 coords;

struct MaterialGL{
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shineness;
};

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

uniform MaterialGL Material;
uniform int numLlums;
uniform llums BufferLlum[20];



uniform vec3 globalAmbient;

uniform vec4 obs;

float calculAtenuacio(int i) {
    vec4 raig = BufferLlum[i].posicio - vPosition;

    float a = BufferLlum[i].attenuacio[0];
    float b = BufferLlum[i].attenuacio[1];
    float c = BufferLlum[i].attenuacio[2];
    float d = length(raig);
    return 1.0/(a + b*d + c*d*d);

}

void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    coords = vCoords;


    //color = vec4(0.5f*(normals.x+1.0), 0.5f*(normals.y+1.0), 0.5f*(normals.z+1.0), 0.1f);
    //color = vec4(globalAmbient,1.0f);





    vec3 colorG = vec3(0.0f);
    vec4 L, H;
    vec4 N = vec4(normalize(normals.xyz), 0.0f);

    vec3 componentDifosa, componentAmbient, componentSpecular;

    for (int i = 0; i < BufferLlum[0].num; i++) {

        //Miro tipus de llum

        //Llum direccional
        if (BufferLlum[i].posicio == vec4(0.0f)) {
            L = normalize(-BufferLlum[i].direccio);

        //Llum Puntual
        } else if (BufferLlum[i].angle==0.0f) {
            L = vec4(normalize(BufferLlum[i].posicio.xyz - vPosition.xyz),0.0f);

        //Spotlight
        } else {
            vec4 direccioRaig = normalize(vPosition - BufferLlum[i].posicio);
            vec4 direccioSpot = normalize(BufferLlum[i].direccio);

            float angleLlumSuperficie = acos(dot(direccioRaig,direccioSpot));
            if (angleLlumSuperficie > BufferLlum[i].angle) {
                L = vec4(0.0f);
            } else {
                L = -direccioRaig;
            }
        }

        //H = L + V
        H = vec4(normalize(L.xyz + normalize(obs.xyz-vPosition.xyz)),0.0f);

        componentAmbient = BufferLlum[i].ambient * Material.ambient;
        componentDifosa = Material.diffuse * BufferLlum[i].diffuse*max(dot(L,N),0.0f);
        componentSpecular = Material.specular * BufferLlum[i].specular *pow(max(dot(N,H),0.0f),Material.shineness);

        //colorG += (componentSpecular + componentAmbient + componentDifosa) * calculAtenuacio(i)+ globalAmbient * Material.ambient;
        //colorG += (componentSpecular + componentAmbient + componentDifosa) + globalAmbient * Material.ambient;
        colorG+= calculAtenuacio(i) * (componentDifosa + componentSpecular) + componentAmbient;
    }
    colorG = globalAmbient*Material.ambient + colorG;
    color = vec4(colorG,1.0f);
}



//GURU = Color de cada normalize
//Phong = Normal de cada vertex
