#include "GameObject.h"

GameObject::~GameObject()
{
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

void GameObject::InitTexture(GLuint texture, const char* texturePath)
{
	textureInfo = stbi_load(texturePath, &width, &heigth, &nrChannels, 4);

	// Defnimos el canal de textura abierto
	glActiveTexture(texture);

	glGenTextures(1, &textureId);

	// Vinculo la textura con el canal de textura
	glBindTexture(GL_TEXTURE_2D, textureId);

	// Configurar textura
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	// Cargar textura
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureInfo);

	// Generar mipmaps
	glGenerateMipmap(GL_TEXTURE_2D);

	// liberamos recursos
	stbi_image_free(textureInfo);
}
