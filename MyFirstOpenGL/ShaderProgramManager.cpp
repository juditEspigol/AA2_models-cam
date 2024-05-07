#include "ShaderProgramManager.h"

ShaderProgramManager::ShaderProgramManager()
{
	// CAMERA PROGRAM >> 0
	ShaderProgram shaderProgramCamera;

	shaderProgramCamera.LoadVertexShader("VS_Camera.glsl");
	shaderProgramCamera.LoadGeometryShader("GS_Camera.glsl");
	//shaderProgramCamera.LoadFragmentShader("FS_Camera.glsl");
	compiledPrograms.push_back(shaderProgramCamera.CreateProgram(shaderProgramCamera));

	// CUBE PROGRAM >> 1
	ShaderProgram shaderProgramCube;

	shaderProgramCube.LoadVertexShader("VS_Camera.glsl");
	shaderProgramCube.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramCube.LoadFragmentShader("FS_YellowOrange.glsl");
	compiledPrograms.push_back(shaderProgramCube.CreateProgram(shaderProgramCube));

	// GREY TROLL PROGRAM >> 2
	ShaderProgram shaderProgramGreyTroll;

	shaderProgramGreyTroll.LoadVertexShader("VS_Camera.glsl");
	shaderProgramGreyTroll.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramGreyTroll.LoadFragmentShader("TrollFragmentShaderGrey.glsl");
	compiledPrograms.push_back(shaderProgramGreyTroll.CreateProgram(shaderProgramGreyTroll));

	// GREEN TROLL PROGRAM >> 3
	ShaderProgram shaderProgramGreenTroll;

	shaderProgramGreenTroll.LoadVertexShader("VS_Camera.glsl");
	shaderProgramGreenTroll.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramGreenTroll.LoadFragmentShader("TrollFragmentShaderGreen.glsl");
	compiledPrograms.push_back(shaderProgramGreenTroll.CreateProgram(shaderProgramGreenTroll));

	// BLUE TROLL PROGRAM >> 4
	ShaderProgram shaderProgramBlueTroll;

	shaderProgramBlueTroll.LoadVertexShader("VS_Camera.glsl");
	shaderProgramBlueTroll.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramBlueTroll.LoadFragmentShader("TrollFragmentShaderBlue.glsl");
	compiledPrograms.push_back(shaderProgramBlueTroll.CreateProgram(shaderProgramBlueTroll));

	// ROCK PROGRAM >> 5
	ShaderProgram shaderProgramRock;

	shaderProgramRock.LoadVertexShader("VS_Camera.glsl");
	shaderProgramRock.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramRock.LoadFragmentShader("RockFragmentShader.glsl");
	compiledPrograms.push_back(shaderProgramRock.CreateProgram(shaderProgramRock));
}

void ShaderProgramManager::DeleteAllPrograms()
{
	for (int i = 0; i < compiledPrograms.size(); i++)
		glDeleteProgram(compiledPrograms[i]);
}
