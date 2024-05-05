#pragma once
#include "Cube.h"
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

	std::vector<GameObject*> gameObjects;

	void CreateFigures();

	void Render();

	void InitProgramsValues();
};