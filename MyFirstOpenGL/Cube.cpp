#include "Cube.h"

Cube::Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, unsigned int _indexProgram)
	: GameObject(_position, _rotation, _scale, _indexProgram) {
	
	//Size (1 x 1 x 1)
	vertexs = {
		-0.5f, +0.5f, -0.5f, // 3
		+0.5f, +0.5f, -0.5f, // 2
		-0.5f, -0.5f, -0.5f, // 6
		+0.5f, -0.5f, -0.5f, // 7
		+0.5f, -0.5f, +0.5f, // 4
		+0.5f, +0.5f, -0.5f, // 2
		+0.5f, +0.5f, +0.5f, // 0
		-0.5f, +0.5f, -0.5f, // 3
		-0.5f, +0.5f, +0.5f, // 1
		-0.5f, -0.5f, -0.5f, // 6
		-0.5f, -0.5f, +0.5f, // 5
		+0.5f, -0.5f, +0.5f, // 4
		-0.5f, +0.5f, +0.5f, // 1
		+0.5f, +0.5f, +0.5f  // 0
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
void Cube::InitProgramValues()
{
	glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram]);

	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));

	glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
void Cube::Update(float _dt)
{
	translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
	rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.y);
	scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);

	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
}
void Cube::Render()
{
	InitProgramValues();

	glBindVertexArray(VAO);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, numVertexs);

	glBindVertexArray(0);
}
