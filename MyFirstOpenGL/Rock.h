#pragma once
#include "GameObject.h"
#include "Model.h"

class Rock : public GameObject
{
private:
	GLuint uvVBO;
	glm::mat4 rotationMatrixX;

public:
	Rock(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model);

	virtual void Render(int index) override;

	void InitProgramValues(int index) override;
};
