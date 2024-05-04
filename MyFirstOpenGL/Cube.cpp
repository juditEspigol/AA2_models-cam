#include "Cube.h"
#include "GLManager.h"

Cube::Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale)
	: GameObject(_position, _rotation, _scale) {
	
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
	glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[index]);
	InitProgramValues(index);
	glBindVertexArray(VAO);

	glDrawArrays(GL_TRIANGLE_STRIP, 0, numVertexs);

	glBindVertexArray(0);
	glUseProgram(0);
}

void Cube::InitProgramValues(int index)
{
	glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[index]);

	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[index], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));

	glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[index], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
