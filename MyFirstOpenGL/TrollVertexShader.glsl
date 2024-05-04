#version 440 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uvsVertexShader;

out vec2 uvsGeomretryShader;

uniform mat4 translationMatrix;
uniform mat4 rotationMatrix;
uniform mat4 rotationMatrixX;
uniform mat4 scaleMatrix;

void main() {
    mat4 model = scaleMatrix;

    if(translationMatrix != 0)
        model = model * translationMatrix;

    if(rotationMatrixX != 0)
        model = model * rotationMatrixX;

    if(rotationMatrix != 0)
        model = model * rotationMatrix;

    uvsGeomretryShader = uvsVertexShader;
    gl_Position = model * vec4(position, 1.0);
}