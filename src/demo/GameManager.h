#pragma once
#include <GameEngine/GameEngine.h>
#include "FloorPrefab.h"
#include "Player.h"
#include "Menu.h"
#include "Laser.h"

using namespace myengine;


struct GameManager : Component
{
	void onInitialise() override;
	void onTick() override;
	void play();
	bool inGame;
	bool isLaserAlive;
	std::shared_ptr<SoundSource> music;
private:
	std::shared_ptr<Menu> menu;
	std::shared_ptr<Player> player;
	std::shared_ptr<FloorPrefab> floorPrefab;
	std::shared_ptr<Laser> laser;
	float laserSpeed;

};
