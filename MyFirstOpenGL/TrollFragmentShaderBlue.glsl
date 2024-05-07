#version 440 core

uniform vec2 windowSize;
uniform sampler2D textureSampler;

in vec2 uvsFragmentShader;

out vec4 fragColor;


void main() {
        
       vec2 adjustedTexCoord = vec2(uvsFragmentShader.x, 1.0 - uvsFragmentShader.y);

       vec4 ambientColor = texture(textureSampler, adjustedTexCoord);
       vec3 color = vec3(0.3, 0.6, 1.0);

       fragColor =  vec4((ambientColor.rgb * color), 1.0);

}