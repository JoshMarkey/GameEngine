#pragma once
#include <GameEngine/GameEngine.h>
#include "Block.h"

using namespace myengine;

struct FloorPrefab : Component
{
	void onInitialise() override;
	std::vector<std::shared_ptr<Block> > blocks;
};