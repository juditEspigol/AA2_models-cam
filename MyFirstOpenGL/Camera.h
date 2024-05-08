#pragma once
#include "GameObject.h"

class Camera : public GameObject
{
private:

	float fov;
	float near;
	float far;

	glm::vec3 localVectorUp;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

public:

	Camera(float _fov, float _near, float _far, unsigned int _indexProgram,
		glm::vec3 _localVectorUp = glm::vec3(0.f, 1.f, 0.f));

	void InitProgramValues() override;

	virtual void Update(float _dt) override; 
	virtual void Render() override;

	void CreateShaderProgram() override;

	void Inputs(GLFWwindow* _window); 
};