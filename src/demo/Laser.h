#pragma once
#include <GameEngine/GameEngine.h>

using namespace myengine;

struct GameManager;
struct Laser : Component
{
	void onInitialise() override;
	void onTick() override;
	void init(std::shared_ptr<GameManager> _gm, float _speed);
	std::shared_ptr<GameManager> gameManager;
	float speed;
};