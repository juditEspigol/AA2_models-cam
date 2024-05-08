//#include "Cube.h"
//#include "GLManager.h"
//
//Cube::Cube(glm::vec3 _position, glm::vec3 _rotation, glm::vec3 _scale, std::string vertexShader, std::string geometryShader, std::string fragmentShader)
//	: GameObject(_position, _rotation, _scale) {
//	
//	InitShader(vertexShader, geometryShader, fragmentShader);
//
//	vertexs = {
//		-0.2f, +0.2f, -0.2f, // 3
//		+0.2f, +0.2f, -0.2f, // 2
//		-0.2f, -0.2f, -0.2f, // 6
//		+0.2f, -0.2f, -0.2f, // 7
//		+0.2f, -0.2f, +0.2f, // 4
//		+0.2f, +0.2f, -0.2f, // 2
//		+0.2f, +0.2f, +0.2f, // 0
//		-0.2f, +0.2f, -0.2f, // 3
//		-0.2f, +0.2f, +0.2f, // 1
//		-0.2f, -0.2f, -0.2f, // 6
//		-0.2f, -0.2f, +0.2f, // 5
//		+0.2f, -0.2f, +0.2f, // 4
//		-0.2f, +0.2f, +0.2f, // 1
//		+0.2f, +0.2f, +0.2f  // 0
//	};
//
//	numVertexs = vertexs.size() / 3;
//
//	// Generate VAO/VBO
//	glGenVertexArrays(1, &VAO);
//	glGenBuffers(1, &VBO);
//
//	// Define active VAO
//	glBindVertexArray(VAO);
//
//	// Define positions VBO as active
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, vertexs.size() * sizeof(float), vertexs.data(), GL_STATIC_DRAW);
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//
//	// Active the attribute 0
//	glEnableVertexAttribArray(0);
//
//	glBindBuffer(GL_ARRAY_BUFFER, 0);
//	glBindVertexArray(0);
//
//	scaleMatrix = MatrixUtilities::GenerateScaleMatrix(transform.scale);
//	translationMatrix = MatrixUtilities::GenerateTranslationMatrix(transform.position);
//	rotationMatrix = MatrixUtilities::GenerateRotationMatrix(transform.rotation, transform.rotation.x);
//}
//
//void Cube::InitShader(std::string vertexShader, std::string geometryShader, std::string fragmentShader)
//{
//	ShaderProgram shaderProgramCube;
//
//	shaderProgramCube.LoadVertexShader(vertexShader);
//	shaderProgramCube.LoadFragmentShader(fragmentShader);
//
//	shaderProgram = shaderProgramCube.CreateProgram(shaderProgramCube);
//}
//
//
//void Cube::Render()
//{
//	glBindVertexArray(VAO);
//
//	InitProgramValues();
//
//	glDrawArrays(GL_TRIANGLE_STRIP, 0, numVertexs);
//
//	glBindVertexArray(0);
//}
//
//
//void Cube::InitProgramValues()
//{
//	glUseProgram(shaderProgram);
//
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "translationMatrix"), 1, GL_FALSE, glm::value_ptr(translationMatrix));
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "rotationMatrix"), 1, GL_FALSE, glm::value_ptr(rotationMatrix));
//	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "scaleMatrix"), 1, GL_FALSE, glm::value_ptr(scaleMatrix));
//
//	glUniform2f(glGetUniformLocation(shaderProgram, "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
//}
