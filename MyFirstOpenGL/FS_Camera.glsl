#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

in vec2 uvsFragmentShader;

out vec4 fragColor;

void main() {
	//fragColor = vec4(0, 0, 0, 1.0);
       vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);
       fragColor = texture(textureSampler, adjustedTexCoord);  

}