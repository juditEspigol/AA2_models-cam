#version 440 core

layout(location = 0) in vec3 position;

uniform mat4 translationMatrix;
uniform mat4 rotationMatrix;
uniform mat4 scaleMatrix;

void main() {

	gl_Position = vec4(position, 1.0);
}