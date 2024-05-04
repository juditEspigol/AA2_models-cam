#pragma once
#include "GameObject.h"
#include "Model.h"

class Troll : public GameObject
{
private:
	GLuint uvVBO;
	glm::mat4 rotationMatrixX;

public:
	Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model);

	virtual void Render(int index) override;

	void InitProgramValues(int index) override;
};