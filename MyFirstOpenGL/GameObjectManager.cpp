#include "GameObjectManager.h"

GameObjectManager::~GameObjectManager()
{
	delete camera; 

	for (GameObject* gObj : gameObjects)
		delete gObj;
}

void GameObjectManager::CreateGameObjects()
{
	// Set camera
	camera = new Camera(45.f, 0.1f, 10.f); 

	// Set game objects
	gameObjects.push_back(new Cube(glm::vec3(0.5, 0.5, 0.f), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.7f)));
}

void GameObjectManager::Update(float _dt)
{
	camera->Update(_dt); 

	for (GameObject* gObj : gameObjects) 
		gObj->Update(_dt);
}

void GameObjectManager::Render()
{
	camera->Render();

	for (GameObject* gObj : gameObjects)
	{
		if (gObj->GetIsActive())
			gObj->Render();
	}
}

void GameObjectManager::InitProgramsValues()
{
	camera->InitProgramValues(); 

	for (GameObject* gObj : gameObjects)
		gObj->InitProgramValues();
}

