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
	gameObjects.push_back(new Cube(glm::vec3(-0.6f, 0.f, 0.f), glm::vec3(0), glm::vec3(1.f)));
	gameObjects.push_back(new Troll(glm::vec3(0.f, 0.f, 0.f), glm::vec3(0), glm::vec3(0.5f), MODEL_MANAGER.models[0]));
}

void GameObjectManager::Render()
{
	for (GameObject* gObj : gameObjects)
	{
		if (gObj->GetIsActive())
			gObj->Render();
	}
}

void GameObjectManager::InitProgramsValues()
{
	for (GameObject* gObj : gameObjects)
		gObj->InitProgramValues();
}

