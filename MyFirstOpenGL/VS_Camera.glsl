#version 440 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 uvsVertexShader;

out vec2 uvsGeomretryShader;

void main() {

    uvsGeomretryShader = uvsVertexShader;

    gl_Position = vec4(position, 1.0);
}