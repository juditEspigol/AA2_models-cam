#version 440 core

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in vec2 uvsGeomretryShader[];
out vec2 uvsFragmentShader;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

void main(){

	for(int i = 0; i < gl_in.length(); i++){
		gl_Position = projectionMatrix * viewMatrix * gl_in[i].gl_Position;
		uvsFragmentShader = uvsGeomretryShader[i];
		EmitVertex();
	}

	EndPrimitive();
}