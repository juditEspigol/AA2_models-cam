#include "GameObjectManager.h"
#include "ModelManager.h"

GameObjectManager::~GameObjectManager()
{
	for (GameObject* gObj : gameObjects)
	{
		delete gObj;
	}
}

void GameObjectManager::CreateFigures()
{
	gameObjects.push_back(new GameObject(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0), glm::vec3(0.25f), MODEL_MANAGER.models[0],
		"VS.glsl", "TrollGeometryShader.glsl", "FS_YellowOrange.glsl", GL_TEXTURE0, "Assets/Textures/Troll.png", false));
	gameObjects.push_back(new GameObject(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0, 0, 0), glm::vec3(0.25f), MODEL_MANAGER.models[0],
		"VS.glsl", "TrollGeometryShader.glsl", "TrollFragmentShaderGrey.glsl", GL_TEXTURE0, "Assets/Textures/Troll.png", true));
}

void GameObjectManager::Render()
{
	for (GameObject* gObj : gameObjects)
	{
		gObj->Render();
	}
}

void GameObjectManager::InitProgramsValues()
{
	for (GameObject* gObj : gameObjects)
	{
		gObj->InitProgramValues();
	}
}

