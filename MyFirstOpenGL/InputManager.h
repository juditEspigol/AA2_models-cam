#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "GameObject.h"

#define INPUT_MANAGER InputManager::Instance()

class InputManager
{
private:

	InputManager()
		: polygonsAreFill(true) {};

	InputManager(const InputManager&) = delete;
	InputManager& operator =(const InputManager&) = delete;

	bool polygonsAreFill;

public:

	inline static InputManager& Instance()
	{
		static InputManager inputManager;
		return inputManager;
	}

	void ChangePolygonMode();

	void SwitchActiveFigure(GameObject* _figure);
};