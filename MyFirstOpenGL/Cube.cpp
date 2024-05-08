#include "Cube.h"
#include "GLManager.h"

Cube::Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::string vertexShader, std::string geometryShader, std::string fragmentShader)
	: GameObject(_position, _rotation, _scale) {
	
	InitShader(vertexShader, geometryShader, fragmentShader);

	//Size (0.4 x 0.4 x 0.4)
	vertexs = {
		-0.65f, +0.f, -0.5f, // 3
		+0.65f, +0.f, -0.5f, // 2
		-1.2f, -1.f, -0.5f, // 6
		+1.2f, -1.f, -0.5f, // 7
		+1.2f, -1.f, +0.5f, // 4
		+0.65f, +0.f, -0.5f, // 2
		+0.65f, +0.f, +0.5f, // 0
		-0.65f, +0.f, -0.5f, // 3
		-0.65f, +0.f, +0.5f, // 1
		-1.2f, -1.f, -0.5f, // 6
		-1.2f, -1.f, +0.5f, // 5
		+1.2f, -1.f, +0.5f, // 4
		-0.65f, +0.f, +0.5f, // 1
		+0.65f, +0.f, +0.5f  // 0
	};

	numVertexs = vertexs.size() / 3;

	// Generate VAO/VBO
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);

	// Define active VAO
	glBindVertexArray(VAO);

	// Define positions VBO as active
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// Active the attribute 0
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void Cube::Render(int index)
{
	glUseProgram(shaderProgram);
	InitProgramValues(index);
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, numVertexs);

	glBindVertexArray(0);
	glUseProgram(0);
}

void Cube::InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader)
{
	ShaderProgram shaderProgramCube;

	shaderProgramCube.LoadVertexShader(vertexShader);
	shaderProgramCube.LoadFragmentShader(fragmentShader);

	shaderProgram = shaderProgramCube.CreateProgram(shaderProgramCube);
}

void Cube::InitProgramValues(int index)
{
	glUseProgram(shaderProgram);

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));

	glUniform2f(glGetUniformLocation(shaderProgram, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
