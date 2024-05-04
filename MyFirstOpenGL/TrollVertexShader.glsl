#version 440 core

layout(location = 0) in vec3 position;

uniform mat4 translationMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;

void main() {
    mat4 model = scaleMatrix;

    if(translationMatrix != 0)
        model = model * translationMatrix;

    if(rotationMatrix != 0)
        model = model * rotationMatrix;


    gl_Position = model * vec4(position, 1.0);
}