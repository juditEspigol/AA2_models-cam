#pragma once
#include <stb_image.h>
#include <GL/glew.h>
#include <vector>

#define TEXTURE_MANAGER TextureManager::Instance()

class TextureManager {
private:

	TextureManager();

	TextureManager(const TextureManager&) = delete;
	TextureManager& operator =(const TextureManager&) = delete;

public:

	inline static TextureManager& Instance()
	{
		static TextureManager glManager;
		return glManager;
	}

	GLuint textureId;

	int width, heigth, nrChannels;
	unsigned char* textureInfo;

	void InitTexture();

};
