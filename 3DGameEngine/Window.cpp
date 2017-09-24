#include "Window.h"


 namespace GameEngine{ namespace Graphics {
	 
	//Function Prototypes
	void WindowResize(GLFWwindow* window, int width, int height);

#pragma region "Public Methods"

//Static variables
	bool Window::m_Keys[MAX_KEYS];
	bool Window::m_MouseButtonKeys[MAX_BUTTONS];
	double Window::mx;
	double Window::my;


	Window::Window(const char* name, int width, int height)
	{
		m_Name = name;
		m_Height = height;
		m_Width = width;

		if (!Init())
			glfwTerminate();

		for (int i = 0; i < MAX_KEYS; i++)
		{
			m_Keys[i] = false;
		}
		for (int i = 0; i < MAX_BUTTONS; i++)
		{
			m_MouseButtonKeys[i] = false;
		}
	}

	Window::~Window()
	{	
		glfwTerminate();
	}

	void Window::Clear()const
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void Window::Update() {

		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
			std::cout << "OpenGL Error" << error << std::endl;


		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	bool Window::Closed()const
	{

		return glfwWindowShouldClose(m_Window);
	}

#pragma endregion


	void WindowResize(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	bool Window::Init()
	{
		if (!glfwInit())
		{
			std::cout << "Failed to Initialize" << std::endl;
			return false;
		}


		m_Window = glfwCreateWindow(m_Width, m_Height, m_Name, NULL, NULL);

		if (!m_Window)
		{
			glfwTerminate();
			std::cout << "Failed to Create GLFW Window" << std::endl;
			return false;
		}

		glfwMakeContextCurrent(m_Window);
		glfwSetWindowUserPointer(m_Window, this);
		glfwSetWindowSizeCallback(m_Window, WindowResize);
		glfwSetKeyCallback(m_Window, key_callback);
		glfwSetMouseButtonCallback(m_Window, mouse_button_callback);
		glfwSetCursorPosCallback(m_Window, cursor_position_callback);
		glfwSwapInterval(0.0f); // To cap the frames, set it to 1.

		//Glew Initialization
		if (glewInit() != GLEW_OK)
		{
			std::cout << "Unable to initialize GLEW" << std::endl;
			return false;
		}
		std::cout << "OpenGL " << glGetString(GL_VERSION) << std::endl;

		return true;

	}

#pragma region "Static Methods"
	void Window:: key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Window* win = (Window*) glfwGetWindowUserPointer(window);
		win->m_Keys[key] = action != GLFW_RELEASE;
		
	}
	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		
		win->m_MouseButtonKeys[button] = action != GLFW_RELEASE;
		
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		Window* win = (Window*)glfwGetWindowUserPointer(window);
		
		win->mx = xpos;
		win->my = ypos;

	}

	bool Window:: isKeyPressed(unsigned int keycode)
	{
		if (keycode >= MAX_KEYS)
			return false;

		return m_Keys[keycode];
	}

	bool Window::isButtonClicked(unsigned int mousebutton)
	{
		if (mousebutton >= MAX_BUTTONS)
			return false;

		return m_MouseButtonKeys[mousebutton];
	}

	void Window::getMousePostion(double& x, double& y)
	{
		x = mx;
		y = my;
	}


#pragma endregion

} }


