#pragma once
#include "../GameEngine/GameEngine.h"
using namespace myengine;

struct Map : Component
{
	std::string modelPath;
	std::string texturePath;
	Map();
	void onInitialise() override;
};