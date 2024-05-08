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
	gameObjects.push_back(new Cube(glm::vec3(-0.6f, 0.f, 0.f), glm::vec3(0), glm::vec3(1.f),
		"VS_Cubes.glsl", "TrollGeometryShader.glsl", "FS_YellowOrange.glsl"));
	gameObjects.push_back(new Troll(glm::vec3(0.f, 0.f, 0.f), glm::vec3(20, 0, 0), glm::vec3(0.25f), MODEL_MANAGER.models[0],
		"TrollVertexShader.glsl", "TrollGeometryShader.glsl", "TrollFragmentShaderGrey.glsl", GL_TEXTURE0, "Assets/Textures/Troll.png"));
}

void GameObjectManager::Render()
{
	int i = 0;
	for (GameObject* gObj : gameObjects)
	{
		gObj->Render(i);
		i++;
	}
}

void GameObjectManager::InitProgramsValues()
{
	int i = 0;
	for (GameObject* gObj : gameObjects)
	{
		gObj->InitProgramValues(i);
		i++;
	}

}

