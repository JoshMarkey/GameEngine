#include "Input.h"
#include <algorithm>
namespace myengine
{
	bool Input::tick()
	{
		SDL_Event event;

		pressedKeys.clear();
		releasedKeys.clear();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				return false;
			}
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
						releasedKeys.push_back(i);
					}
				}
			}
		}
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
		for (int i = 0; i < pressedKeys.size(); i++)
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
		for (int i = 0; i < keys.size(); i++)
		{
			if (releasedKeys[i] == keyCode)
			{
				return true;
			}
		}
		return false;
	}
}
