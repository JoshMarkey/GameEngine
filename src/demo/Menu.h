#pragma once
#include <GameEngine/GameEngine.h>

using namespace myengine;

struct GameManager;
struct Menu : Component
{
	//void onInitialise() override;
	void init(std::shared_ptr<GameManager> _gm);
	std::shared_ptr<GameManager> gameManager;

	std::string quitPressed;
	std::string quitDefault;

	std::string playDefault;
	std::string playPressed;

	std::string playCurrent;
	std::string quitCurrent;

	//void onTick() override;
	void onGui() override;
};