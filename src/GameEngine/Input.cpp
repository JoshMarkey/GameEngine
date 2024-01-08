#include "Input.h"
#include <algorithm>
namespace myengine
{
	void Input::init()
	{
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
			//KEYBOARD
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
			//else if (event.)
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
}
