#include "Input.h"
#include <algorithm>
namespace myengine
{
	
	void Input::initialise()
	{
		
		JOYSTICK_DEAD_ZONE = 8000;
		int MaxJoysticks = SDL_NumJoysticks();
		int ControllerIndex = 0;
		for (int JoystickIndex = 0; JoystickIndex < MaxJoysticks; ++JoystickIndex)
		{
			if (!SDL_IsGameController(JoystickIndex))
			{
				continue;
			}
			if (ControllerIndex >= MAX_CONTROLLERS)
			{
				break;
			}
			m_ControllerHandles[ControllerIndex] = SDL_GameControllerOpen(JoystickIndex);
			ControllerIndex++;
		}

		//printf("%i joysticks were found.\n\n", SDL_NumJoysticks());
		std::cout<<"The names of the joysticks are:\n";

		for (int i = 0; i < SDL_NumJoysticks(); i++)
		{
			//std::cout << SDL_JoystickName(SDL_JoystickOpen(i)) << std::endl;
		}
	}

	bool Input::tick()
	{
		SDL_Event event;

		m_pressedKeys.clear();
		m_releasedKeys.clear();
		//Find all mouse and keyboard input and add to appropriate collection
		while (SDL_PollEvent(&event))
		{
			//QUIT
			if (event.type == SDL_QUIT)
			{
				return false;
			}
			//BUTTONS
			if (event.type == SDL_KEYDOWN)
			{
				if (std::find(m_keys.begin(), m_keys.end(), event.key.keysym.sym) != m_keys.end())
				{
					continue;
				}
				else
				{
					m_keys.push_back(event.key.keysym.sym);
					m_pressedKeys.push_back(event.key.keysym.sym);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				for (int i = 0; i < m_keys.size(); i++)
				{
					if (m_keys[i] == event.key.keysym.sym)
					{
						m_keys.erase(m_keys.begin() + i);
						m_releasedKeys.push_back(event.key.keysym.sym);
					}
				}
			}
			//MOUSE
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (std::find(m_keys.begin(), m_keys.end(), event.button.button) != m_keys.end())
				{
					continue;
				}
				else
				{
					m_keys.push_back(event.button.button);
					m_pressedKeys.push_back(event.button.button);
				}
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				for (int i = 0; i < m_keys.size(); i++)
				{
					if (m_keys[i] == event.button.button)
					{
						m_keys.erase(m_keys.begin() + i);
						m_releasedKeys.push_back(event.button.button);
					}
				}
			}
			//Joystick
			else if (event.type == SDL_JOYAXISMOTION)
			{
				if (event.jaxis.which == 0)
				{
					//X axis motion
					if (event.jaxis.axis == 0)
					{
						//Left of dead zone
						if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
						{
							m_leftStick.x = -1;
						}
						//Right of dead zone
						else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
						{
							m_leftStick.x = 1;
						}
						else
						{
							m_leftStick.x = 0;
						}
					}
					//Y axis
					else if (event.jaxis.axis == 1)
					{
						//Below of dead zone
						if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
						{
							m_leftStick.y = -1;
						}
						//Above of dead zone
						else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
						{
							m_leftStick.y = 1;
						}
						else
						{
							m_leftStick.y = 0;
						}
					}
				}
			}
			//Controller Buttons
			else if (event.type == SDL_CONTROLLERBUTTONDOWN)
			{
				if (std::find(m_keys.begin(), m_keys.end(), event.cbutton.button) != m_keys.end())
				{
					continue;
				}
				else
				{
					m_keys.push_back(event.cbutton.button);
					m_pressedKeys.push_back(event.cbutton.button);
				}
			}
			else if (event.type == SDL_CONTROLLERBUTTONUP)
			{
				for (int i = 0; i < m_keys.size(); i++)
				{
					if (m_keys[i] == event.cbutton.button)
					{
						m_keys.erase(m_keys.begin() + i);
						m_releasedKeys.push_back(event.cbutton.button);
					}
				}
			}
		}

		//std::cout << "X: " << leftStick.x << "    Y: " << leftStick.y << std::endl;
		for (int i = 0; i < m_pressedKeys.size(); i++)
		{
			//std::cout << m_pressedKeys[i] << std::endl;
		}
		//MOUSE POS
		int x;
		int y;
		SDL_GetMouseState(&x,&y);
		m_mousePos.x = x;
		m_mousePos.y = y;
		return true;
	}


	bool Input::getKey(int keyCode)
	{
		for (int i = 0; i < m_keys.size(); i++)
		{
			if (m_keys[i] == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getKeyDown(int keyCode)
	{
		for (int i = 0; i < m_pressedKeys.size(); ++i)
		{
			if (m_pressedKeys.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getKeyUp(int keyCode)
	{
		for (int i = 0; i < m_releasedKeys.size(); ++i)
		{
			if (m_releasedKeys.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	glm::vec2 Input::getJoystickAxis()
	{
		return m_leftStick;
	}

	glm::vec2 Input::getMousePos()
	{
		return m_mousePos;
	}

	Input::~Input()
	{
		/*
		int MaxJoysticks = SDL_NumJoysticks();
		int ControllerIndex = 0;
		for (int JoystickIndex = 0; JoystickIndex < MaxJoysticks; ++JoystickIndex)
		{
			if (!SDL_IsGameController(JoystickIndex))
			{
				continue;
			}
			if (ControllerIndex >= MAX_CONTROLLERS)
			{
				break;
			}

			SDL_GameControllerClose(ControllerHandles[i]);
		}*/
	}

}
