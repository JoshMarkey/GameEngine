#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
namespace myengine
{
	struct Core;
	struct Input
	{
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	public:
		bool tick();
		bool getKey(int keyCode);
		bool getKeyDown(int keyCode);
		bool getKeyUp(int keyCode);
		void printKeys();
	};
}