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
	gameObjects.push_back(new Troll(glm::vec3(0.f, -1.2f, 0.f), glm::vec3(0), glm::vec3(0.25f), MODEL_MANAGER.models[0]));
	gameObjects.push_back(new Troll(glm::vec3(2.f, -2.3f, 0.f), glm::vec3(0, 255, 0), glm::vec3(0.35f), MODEL_MANAGER.models[0]));
	gameObjects.push_back(new Troll(glm::vec3(-2.f, -2.3f, 0.f), glm::vec3(0, 75, 0), glm::vec3(0.35f), MODEL_MANAGER.models[0]));
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

