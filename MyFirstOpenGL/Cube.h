#pragma once
#include "GameObject.h"
#include "MatrixUtilities.h"

class Cube : public GameObject
{
private: 

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

public: 

	Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale);

	void InitProgramValues() override;

	virtual void Update(float _dt) override;
	virtual void Render() override;
};