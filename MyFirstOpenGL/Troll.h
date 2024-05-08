#pragma once
#include "GameObject.h"
#include "MatrixUtilities.h"
#include "Model.h"

class Troll : public GameObject
{
private:

	glm::mat4 translationMatrix;
	glm::mat4 rotationMatrix;
	glm::mat4 scaleMatrix;

	glm::mat4 rotationMatrixX;

	GLuint uvVBO;

public:

	Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, unsigned int _indexProgram, Model _model);

	void InitProgramValues() override;

	virtual void Update(float _dt) override;
	virtual void Render() override;

	void CreateShaderProgram() override;
};