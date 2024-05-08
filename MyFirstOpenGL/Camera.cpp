#include "Camera.h"

Camera::Camera(float _fov, float _near, float _far, unsigned int _indexProgram, glm::vec3 _localVectorUp)
	: GameObject(glm::vec3(0.f, 0.f, 1.f), glm::vec3(0.f), glm::vec3(1.f), _indexProgram),
	fov(_fov), near(_near), far(_far), localVectorUp(_localVectorUp)
{ 
	//CreateShaderProgram();
}

void Camera::InitProgramValues()
{
	glUseProgram(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram]);

	glUniform2f(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "windowSize"), WINDOW_WIDTH, WINDOW_HEIGHT);
}
void Camera::Update(float _dt)
{
	viewMatrix = glm::lookAt(transform.position, transform.position + glm::vec3(0.f, 0.f, -1.f), localVectorUp);
	projectionMatrix = glm::perspective(glm::radians(fov), (float)WINDOW_WIDTH / (float)WINDOW_HEIGHT, near, far);

	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "viewMatrix"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
	glUniformMatrix4fv(glGetUniformLocation(SHADERPROGRAM_MANAGER.compiledPrograms[indexProgram], "projectionMatrix"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));
}
void Camera::Render()
{
}

void Camera::CreateShaderProgram()
{
	ShaderProgram shaderProgramCamera;

	shaderProgramCamera.LoadVertexShader("VS_Camera.glsl");
	shaderProgramCamera.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramCamera.LoadFragmentShader("FS_Camera.glsl");
	SHADERPROGRAM_MANAGER.compiledPrograms.push_back(shaderProgramCamera.CreateProgram(shaderProgramCamera));
}

void Camera::Inputs(GLFWwindow* _window)
{
	if (glfwGetKey(_window, GLFW_KEY_W) == GLFW_PRESS) {
		transform.position.y += 0.01f;
	}
	if (glfwGetKey(_window, GLFW_KEY_S) == GLFW_PRESS) {
		transform.position.y -= 0.01f;
	}

	if (glfwGetKey(_window, GLFW_KEY_D) == GLFW_PRESS) {
		transform.position.x += 0.01f;
	}
	if (glfwGetKey(_window, GLFW_KEY_A) == GLFW_PRESS) {
		transform.position.x -= 0.01f;
	}

	if (glfwGetKey(_window, GLFW_KEY_P) == GLFW_PRESS) {
		transform.position.z += 0.01f;
	}
	if (glfwGetKey(_window, GLFW_KEY_O) == GLFW_PRESS) {
		transform.position.z -= 0.01f;
	}

	if (glfwGetKey(_window, GLFW_KEY_PERIOD) == GLFW_PRESS) {
		fov += 1.f;
		if (fov >= 179)
			fov = 179;
	}
	if (glfwGetKey(_window, GLFW_KEY_COMMA) == GLFW_PRESS) {
		fov -= 1.f;
		if (fov < 1.f)
			fov = 1.f;
	}
}