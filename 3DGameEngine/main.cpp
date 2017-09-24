//#define GLEW_STATIC
//#include <glew.h>
//#include <glfw3.h>
//#include <iostream>
//
//#include "Window.h"
//#include "Math.h"
//#include "mat4.h"
//#include "FileUtils.h"
//#include "Shader.h"
//#include "Buffer.h"
//#include "VertexArrays.h"
//#include "IndexBuffer.h"
//#include "Renderable2D.h"
//#include "Renderer.h"
//#include "Simple2DRenderer.h"
//#include "StaticSprite.h"
//#include "BatchRenderer.h"
//#include "Sprite.h"
//#include "TileLayer.h"
//#include <time.h>
//#include "Timer.h"
//
//#define BATCH_RENDERER 1
//
//
//int main()
//{
//	using namespace GameEngine;
//	using namespace Graphics;
//	using namespace Maths;
//
//
//	const unsigned int SCR_WIDTH = 800;
//	const unsigned int SCR_HEIGHT = 600;
//
//	Window window("My Engine", SCR_WIDTH, SCR_HEIGHT);
//
//	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);
//	Shader* s = new Shader("basic.vert", "basic.frag");
//	Shader& shader = *s;
//	shader.enable();
//	shader.setUniform2f("light_pos", vec2(4.0, 1.5));
//
//	TileLayer layer(&shader);
//
//	srand(time(NULL));
//
//
//	for (float x = 0.0f; x < 16.0f; x += 0.1)
//	{
//		for (float y = 0.0f; y < 9.0f; y += 0.1)
//		{
//			layer.add(new Sprite (x, y, 0.08f, 0.08f, Maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
//		}
//	}
//	
//	Timer time;
//	float  timer = 0.0f;
//	unsigned int frames = 0;
//	while (!window.Closed())
//	{
//		window.Clear();
//		double x, y;
//		window.getMousePostion(x, y);
//
//		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f/ 800.0f) ,(float)(9.0f - y * 9 / 600.0f) ));
//
//		layer.render();
//		
//		window.Update();
//		frames++;
//		if (time.elapsed() - timer > 1.0f)
//		{
//			timer += 1.0f;
//			printf("%d fps\n", frames);
//			frames = 0;
//		}
//
//		
//	}
//
//	
//	return 0;
//}
//

#include <glfw3.h>
#include <glfw3.h>

#include <iostream>

using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

														 // glfw window creation
														 // --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);


	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// input
		// -----
		processInput(window);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// glfw: terminate, clearing all previously allocated GLFW resources.
	// ------------------------------------------------------------------
	glfwTerminate();
	return 0;
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_E && action == GLFW_PRESS)
		cout << "Pressed" << endl;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

