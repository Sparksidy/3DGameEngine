#pragma once
#define GLEW_STATIC
#include <glew.h>
#include <glfw3.h>


#include <iostream>
namespace GameEngine { namespace Graphics {

	const int MAX_KEYS	  =		1024;
	const int MAX_BUTTONS =		32;

	class Window {
	private:
		const char* m_Name;
		int m_Width, m_Height;
		bool m_Closed;

		static bool m_Keys[MAX_KEYS];
		static bool m_MouseButtonKeys[MAX_BUTTONS];
		static double mx, my;

		GLFWwindow* m_Window;

	public:
		Window(const char* name, int width, int height);
		~Window();
		bool Closed()const;
		void Update();
		void Clear()const;


		//Getters
		inline int getWidth()const { return m_Width; }
		inline int getHeight()const { return m_Height;}

		static bool isKeyPressed(unsigned int keycode);
		static bool isButtonClicked(unsigned int mousebutton);
		static void getMousePostion(double& x, double& y);
		
	private:
		bool Init();
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);

	};


} }

