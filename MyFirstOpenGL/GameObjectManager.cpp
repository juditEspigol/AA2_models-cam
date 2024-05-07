#include "GameObjectManager.h"

#include "ModelManager.h"

GameObjectManager::~GameObjectManager()
{
	delete camera; 

	for (GameObject* gObj : gameObjects)
		delete gObj;
}

void GameObjectManager::CreateGameObjects()
{
	// Set camera
	camera = new Camera(45.f, 0.1f, 10.f, 0); 

	// Set game objects
	//gameObjects.push_back(new Cube(glm::vec3(0.5, 0.5, 0), glm::vec3(0.f, 45.f, 0.f), glm::vec3(0.7), 0)); 
	gameObjects.push_back(new Troll(glm::vec3(0.f, 0.5f, 0.f), glm::vec3(20, 0, 0), glm::vec3(0.25f), 1, MODEL_MANAGER.models[0]));
	//gameObjects.push_back(new Troll(glm::vec3(0.5, 0.5, 0), glm::vec3(0, 295, 0), glm::vec3(0.35f), 1, MODEL_MANAGER.models[0]));
	//gameObjects.push_back(new Troll(glm::vec3(-2.f, -2.3f, 0.f), glm::vec3(0, 75, 0), glm::vec3(0.35f), 0, MODEL_MANAGER.models[0]));
	//gameObjects.push_back(new Rock(glm::vec3(-2.f, -5.0f, 0.7f), glm::vec3(0, 0, 0), glm::vec3(0.1f), 0, MODEL_MANAGER.models[1]));
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
		gObj->Render();
}

void GameObjectManager::InitProgramsValues()
{
	camera->InitProgramValues(); 

	for (GameObject* gObj : gameObjects)
		gObj->InitProgramValues();
}

