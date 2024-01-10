#include "Input.h"
#include <algorithm>
namespace myengine
{
	
	void Input::init()
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
			ControllerHandles[ControllerIndex] = SDL_GameControllerOpen(JoystickIndex);
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

		pressedKeys.clear();
		releasedKeys.clear();
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
				if (std::find(keys.begin(), keys.end(), event.key.keysym.sym) != keys.end())
				{
					continue;
				}
				else
				{
					keys.push_back(event.key.keysym.sym);
					pressedKeys.push_back(event.key.keysym.sym);
				}
			}
			else if (event.type == SDL_KEYUP)
			{
				for (int i = 0; i < keys.size(); i++)
				{
					if (keys[i] == event.key.keysym.sym)
					{
						keys.erase(keys.begin() + i);
						releasedKeys.push_back(event.key.keysym.sym);
					}
				}
			}
			//MOUSE
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (std::find(keys.begin(), keys.end(), event.button.button) != keys.end())
				{
					continue;
				}
				else
				{
					keys.push_back(event.button.button);
					pressedKeys.push_back(event.button.button);
				}
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				for (int i = 0; i < keys.size(); i++)
				{
					if (keys[i] == event.button.button)
					{
						keys.erase(keys.begin() + i);
						releasedKeys.push_back(event.button.button);
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
							leftStick.x = -1;
						}
						//Right of dead zone
						else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
						{
							leftStick.x = 1;
						}
						else
						{
							leftStick.x = 0;
						}
					}
					//Y axis
					else if (event.jaxis.axis == 1)
					{
						//Below of dead zone
						if (event.jaxis.value < -JOYSTICK_DEAD_ZONE)
						{
							leftStick.y = -1;
						}
						//Above of dead zone
						else if (event.jaxis.value > JOYSTICK_DEAD_ZONE)
						{
							leftStick.y = 1;
						}
						else
						{
							leftStick.y = 0;
						}
					}
				}
			}
			//Controller Buttons
			else if (event.type == SDL_CONTROLLERBUTTONDOWN)
			{
				if (std::find(keys.begin(), keys.end(), event.cbutton.button) != keys.end())
				{
					continue;
				}
				else
				{
					keys.push_back(event.cbutton.button);
					pressedKeys.push_back(event.cbutton.button);
				}
			}
			else if (event.type == SDL_CONTROLLERBUTTONUP)
			{
				for (int i = 0; i < keys.size(); i++)
				{
					if (keys[i] == event.cbutton.button)
					{
						keys.erase(keys.begin() + i);
						releasedKeys.push_back(event.cbutton.button);
					}
				}
			}
		}

		//std::cout << "X: " << leftStick.x << "    Y: " << leftStick.y << std::endl;
		for (int i = 0; i < pressedKeys.size(); i++)
		{
			//std::cout << pressedKeys[i] << std::endl;
		}
		//MOUSE POS
		int x;
		int y;
		SDL_GetMouseState(&x,&y);
		mousePos.x = x;
		mousePos.y = y;
		return true;
	}


	bool Input::getKey(int keyCode)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys[i] == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getKeyDown(int keyCode)
	{
		for (int i = 0; i < pressedKeys.size(); ++i)
		{
			if (pressedKeys.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	bool Input::getKeyUp(int keyCode)
	{
		for (int i = 0; i < releasedKeys.size(); ++i)
		{
			if (releasedKeys.at(i) == keyCode)
			{
				return true;
			}
		}
		return false;
	}

	glm::vec2 Input::getJoystickAxis()
	{
		return leftStick;
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
