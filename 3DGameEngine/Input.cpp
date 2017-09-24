#include "Input.h"

namespace GameEngine { namespace Input {

	bool InputHandler:: m_Keys[MAX_KEYS];

	InputHandler::InputHandler()
	{
		//set the keyCallbacks
	}

	void InputHandler::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{

	}

	void InputHandler::Update()const
	{
		
	}



}


}
