#pragma once
#include <SDL2/SDL.h>
#include <vector>
namespace myengine
{
	struct Core;
	struct Input
	{
		std::vector<int> keyCodes;
		bool getKey(int keyCode);
		bool getKeyDown(int keyCode);
		bool getKeyUp(int keyCode);
	};
}