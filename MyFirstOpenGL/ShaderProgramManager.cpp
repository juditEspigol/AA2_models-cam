#include "ShaderProgramManager.h"

ShaderProgramManager::ShaderProgramManager()
{
		// CUBE PROGRAM
		ShaderProgram shaderProgramCube;

		shaderProgramCube.LoadVertexShader("VS_Cubes.glsl");
		shaderProgramCube.LoadFragmentShader("FS_YellowOrange.glsl");
		compiledPrograms.push_back(shaderProgramCube.CreateProgram(shaderProgramCube));

		// GREY TROLL PROGRAM
		ShaderProgram shaderProgramGreyTroll;

		shaderProgramGreyTroll.LoadVertexShader("TrollVertexShader.glsl");
		shaderProgramGreyTroll.LoadFragmentShader("TrollFragmentShaderGrey.glsl");
		shaderProgramGreyTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		compiledPrograms.push_back(shaderProgramGreyTroll.CreateProgram(shaderProgramGreyTroll));

		// GREEN TROLL PROGRAM
		ShaderProgram shaderProgramGreenTroll;

		shaderProgramGreenTroll.LoadVertexShader("TrollVertexShader.glsl");
		shaderProgramGreenTroll.LoadFragmentShader("TrollFragmentShaderGreen.glsl");
		shaderProgramGreenTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		compiledPrograms.push_back(shaderProgramGreenTroll.CreateProgram(shaderProgramGreenTroll));


		// BLUE TROLL PROGRAM
		ShaderProgram shaderProgramBlueTroll;

		shaderProgramBlueTroll.LoadVertexShader("TrollVertexShader.glsl");
		shaderProgramBlueTroll.LoadFragmentShader("TrollFragmentShaderBlue.glsl");
		shaderProgramBlueTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		compiledPrograms.push_back(shaderProgramBlueTroll.CreateProgram(shaderProgramBlueTroll));
}

void ShaderProgramManager::DeletePrograms()
{
	for (int i = 0; i < compiledPrograms.size(); i++) {
		
		glDeleteProgram(compiledPrograms[i]);
	}
}
