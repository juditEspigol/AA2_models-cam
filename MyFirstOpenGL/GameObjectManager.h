#pragma once

#include "Cube.h"
#include "Camera.h"
#include "Troll.h"
#include "Rock.h"

#define GAMEOBJECT_MANAGER GameObjectManager::Instance()

class GameObjectManager
{
private:

	GameObjectManager() = default;

	GameObjectManager(const GameObjectManager&) = delete;
	GameObjectManager& operator =(const GameObjectManager&) = delete;

public:

	inline static GameObjectManager& Instance()
	{
		static GameObjectManager gameObjectManager;
		return gameObjectManager;
	}
	~GameObjectManager();

	Camera* camera; 
	std::vector<GameObject*> gameObjects;

	void CreateGameObjects();

	void InitProgramsValues();

	void Update(float _dt);
	void Render();
};