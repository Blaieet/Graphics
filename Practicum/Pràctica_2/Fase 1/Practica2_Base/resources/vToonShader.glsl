#version 330

layout (location = 0) in vec4 vPosition;
layout (location = 1) in vec4 normals;



uniform mat4 model_view;
uniform mat4 projection;

//out vec4 color;
out vec4 pos;
out vec4 norm;


void main()
{
    gl_Position = projection*model_view*vPosition;
    gl_Position = gl_Position/gl_Position.w;

    pos = vPosition;
    norm = normals;

}



//GURU = Color de cada normalize
//Phong = Normal de cada vertex
