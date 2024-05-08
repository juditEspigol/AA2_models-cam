#include "GLManager.h"
#include "ShaderProgramManager.h"
#include "GameObjectManager.h"
#include "TimeManager.h"
#include "InputManager.h"
#include "TextureManager.h"

int main() 
{
	srand(static_cast<unsigned int>(time(NULL)));

	GL_MANAGER.WindowsConfiguration(); 
	// Give GLEW permission to use experimental functionalities
	glewExperimental = GL_TRUE;

	GL_MANAGER.ActivateBackCulling(); 

	// Initialize GLEW and control errors Inicializamos GLEW y controlamos errores
	if (glewInit() == GLEW_OK) 
	{
		// Define wich color we use for cleaning buffer
		glClearColor(0.3f, 0.8f, 1.f, 1.f);
		// Define draw mode to -> Fill
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

		GAMEOBJECT_MANAGER.CreateGameObjects();

		TEXTURE_MANAGER.InitTexture();

		//Assign initial values to programs
		GAMEOBJECT_MANAGER.InitProgramsValues();

		//Generate game loop
		while (!glfwWindowShouldClose(GL_MANAGER.window)) 
		{
			//Pull events (buttons, keys, mouse...)
			glfwPollEvents();
			//Clean buffers
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

			//INPUT_MANAGER.Update();
			TIME_MANAGER.Update();
			
			GAMEOBJECT_MANAGER.camera->Inputs(GL_MANAGER.window); 
			
			//GAMEOBJECT_MANAGER.Update(TIME_MANAGER.GetDeltaTime());
			GAMEOBJECT_MANAGER.Render();

			//Switch buffers
			glFlush();
			glfwSwapBuffers(GL_MANAGER.window);
		}

		//Deactive & delete program
		glUseProgram(0);
		SHADERPROGRAM_MANAGER.DeleteAllPrograms();
	}
	else 
	{
		std::cout << "Program Crashes" << std::endl;
		glfwTerminate();
	}

	//Finish GLFW
	glfwTerminate();
}