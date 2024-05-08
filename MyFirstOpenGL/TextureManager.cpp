#include "TextureManager.h"


TextureManager::TextureManager()
{
	//Troll texture
	textureInfo.push_back(stbi_load("Assets/Textures/Troll.png", &width, &heigth, &nrChannels, 4));

	////Rock texture
	//textureInfo.push_back(stbi_load("Assets/Textures/Rock.png", &width, &heigth, &nrChannels, 4));
}

void TextureManager::InitTexture()
{		
	// Defnimos el canal de textura abierto
	glActiveTexture(GL_TEXTURE0);

	for (int i = 0; i < textureInfo.size(); i++)
	{
		glGenTextures(1, &textureId);

		// Vinculo la textura con el canal de textura
		glBindTexture(GL_TEXTURE_2D, textureId);

		// Configurar textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Cargar textura
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureInfo[i]);

		// Generar mipmaps
		glGenerateMipmap(GL_TEXTURE_2D);

		// liberamos recursos
		stbi_image_free(textureInfo[i]);
	}
}
