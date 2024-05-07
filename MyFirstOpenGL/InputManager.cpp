#include "InputManager.h"

void InputManager::ChangePolygonMode()
{
	if (polygonsAreFill) {
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		polygonsAreFill = false;
	}
	else {
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		polygonsAreFill = true;
	}
}

void InputManager::SwitchActiveFigure(GameObject* _figure)
{
	_figure->SetIsActive(!_figure->GetIsActive());
}
