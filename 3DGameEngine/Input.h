#pragma once
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>

namespace GameEngine { namespace Input {

		const int MAX_KEYS = 1024;

		class InputHandler {
		private:
			static bool m_Keys[MAX_KEYS];
			GLFWwindow* m_InputWindow;
			static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);





		public:
			InputHandler();
			static bool isKeyPressed(unsigned int keycode);
			void Update()const;
			~InputHandler();


		};


} }

