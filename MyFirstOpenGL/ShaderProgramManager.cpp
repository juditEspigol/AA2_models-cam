#include "ShaderProgramManager.h"

ShaderProgramManager::ShaderProgramManager()
{
		// CUBE PROGRAM
		ShaderProgram shaderProgramCube;

		shaderProgramCube.LoadVertexShader("VS_Cubes.glsl");
		shaderProgramCube.LoadFragmentShader("FS_YellowOrange.glsl");
		compiledPrograms.push_back(shaderProgramCube.CreateProgram(shaderProgramCube));

		// TROLL PROGRAM
		ShaderProgram shaderProgramTroll;

		shaderProgramTroll.LoadVertexShader("TrollVertexShader.glsl");
		shaderProgramTroll.LoadFragmentShader("TrollFragmentShader.glsl");
		shaderProgramTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		compiledPrograms.push_back(shaderProgramTroll.CreateProgram(shaderProgramTroll));
}

void ShaderProgramManager::DeletePrograms()
{
	for (int i = 0; i < compiledPrograms.size(); i++) {
		
		glDeleteProgram(compiledPrograms[i]);
	}
}
