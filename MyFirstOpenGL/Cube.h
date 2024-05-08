#pragma once
#include "GameObject.h"

class Cube : public GameObject
{
private: 

public: 

	Cube()
		: GameObject() {
		vertexs = {
			-0.2f, +0.2f, -0.2f, // 3
			+0.2f, +0.2f, -0.2f, // 2
			-0.2f, -0.2f, -0.2f, // 6
			+0.2f, -0.2f, -0.2f, // 7
			+0.2f, -0.2f, +0.2f, // 4
			+0.2f, +0.2f, -0.2f, // 2
			+0.2f, +0.2f, +0.2f, // 0
			-0.2f, +0.2f, -0.2f, // 3
			-0.2f, +0.2f, +0.2f, // 1
			-0.2f, -0.2f, -0.2f, // 6
			-0.2f, -0.2f, +0.2f, // 5
			+0.2f, -0.2f, +0.2f, // 4
			-0.2f, +0.2f, +0.2f, // 1
			+0.2f, +0.2f, +0.2f  // 0
		};
	};

	Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::string vertexShader, std::string geometryShader, std::string fragmentShader);

	virtual void Render(int index) override;

	virtual void InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader) override;

	void InitProgramValues(int index) override;
};