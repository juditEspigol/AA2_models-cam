#include "ShaderProgramManager.h"

ShaderProgramManager::ShaderProgramManager()
{
	// CAMERA PROGRAM
	ShaderProgram shaderProgramCamera;

	shaderProgramCamera.LoadVertexShader("VS_Camera.glsl");
	shaderProgramCamera.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramCamera.LoadFragmentShader("FS_Camera.glsl");

	compiledPrograms.push_back(shaderProgramCamera.CreateProgram(shaderProgramCamera));
}

void ShaderProgramManager::DeleteAllPrograms()
{
	for (int i = 0; i < compiledPrograms.size(); i++)
		glDeleteProgram(compiledPrograms[i]);
}
