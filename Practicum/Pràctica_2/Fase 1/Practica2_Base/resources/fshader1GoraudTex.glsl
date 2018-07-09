#version 330

in vec2 coords;
in vec4 color;

out vec4 colorOut;

uniform sampler2D texture;


void main()

{

    vec4 tex = texture2D(texture, coords);
    colorOut = color*0.25+tex.xyzw*0.75;
}

