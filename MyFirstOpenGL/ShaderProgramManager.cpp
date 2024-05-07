#include "ShaderProgramManager.h"

ShaderProgramManager::ShaderProgramManager()
{
	// CAMERA PROGRAM >> 0
	ShaderProgram shaderProgramCamera;

	shaderProgramCamera.LoadVertexShader("VS_Camera.glsl");
	shaderProgramCamera.LoadGeometryShader("GS_Camera.glsl");
	shaderProgramCamera.LoadFragmentShader("FS_Camera.glsl");
	compiledPrograms.push_back(shaderProgramCamera.CreateProgram(shaderProgramCamera));

		//// CUBE PROGRAM >> 1
		//ShaderProgram shaderProgramCube;

		//shaderProgramCube.LoadVertexShader("VS_Cubes.glsl");
		//shaderProgramCube.LoadFragmentShader("FS_YellowOrange.glsl");
		//compiledPrograms.push_back(shaderProgramCube.CreateProgram(shaderProgramCube));

		// GREY TROLL PROGRAM >> 2
		ShaderProgram shaderProgramGreyTroll;

		shaderProgramGreyTroll.LoadVertexShader("TrollVertexShader.glsl");
		shaderProgramGreyTroll.LoadFragmentShader("TrollFragmentShaderGrey.glsl");
		shaderProgramGreyTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		compiledPrograms.push_back(shaderProgramGreyTroll.CreateProgram(shaderProgramGreyTroll));

		//// GREEN TROLL PROGRAM >> 3
		//ShaderProgram shaderProgramGreenTroll;

		//shaderProgramGreenTroll.LoadVertexShader("TrollVertexShader.glsl");
		//shaderProgramGreenTroll.LoadFragmentShader("TrollFragmentShaderGreen.glsl");
		//shaderProgramGreenTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		//compiledPrograms.push_back(shaderProgramGreenTroll.CreateProgram(shaderProgramGreenTroll));

		//// BLUE TROLL PROGRAM >> 4
		//ShaderProgram shaderProgramBlueTroll;

		//shaderProgramBlueTroll.LoadVertexShader("TrollVertexShader.glsl");
		//shaderProgramBlueTroll.LoadFragmentShader("TrollFragmentShaderBlue.glsl");
		//shaderProgramBlueTroll.LoadGeometryShader("TrollGeometryShader.glsl");
		//compiledPrograms.push_back(shaderProgramBlueTroll.CreateProgram(shaderProgramBlueTroll));

		//// ROCK PROGRAM >> 5
		//ShaderProgram shaderProgramRock;

		//shaderProgramRock.LoadVertexShader("TrollVertexShader.glsl");
		//shaderProgramRock.LoadFragmentShader("RockFragmentShader.glsl");
		//shaderProgramRock.LoadGeometryShader("TrollGeometryShader.glsl");
		//compiledPrograms.push_back(shaderProgramRock.CreateProgram(shaderProgramRock));
}

void ShaderProgramManager::DeleteAllPrograms()
{
	for (int i = 0; i < compiledPrograms.size(); i++)
		glDeleteProgram(compiledPrograms[i]);
}
