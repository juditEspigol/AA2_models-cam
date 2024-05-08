#pragma once
#include "GameObject.h"
#include "Model.h"

class Troll : public GameObject
{
private:
	GLuint uvVBO;

public:
	Troll(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, Model model, 
		std::string vertexShader, std::string geometryShader, std::string fragmentShader, GLuint texture, const char* texturePath);

	virtual void Render(int index) override;

	virtual void InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader) override;

	void InitProgramValues(int index) override;
};