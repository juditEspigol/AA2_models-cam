#pragma once
#include "GameObject.h"
#include "Model.h"

class Troll : public GameObject
{
private:
	GLuint uvVBO;

public:
	Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model);

	virtual void Update(float _dt) override;

	virtual void Render() override;

	void InitProgramValues() override;
};