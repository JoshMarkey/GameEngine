#pragma once
#include <GameEngine/GameEngine.h>

using namespace myengine;

struct Player : Component
{
	void onInitialise() override;
	void onTick() override;
	void jump();
	float accel;
	std::shared_ptr<KRigidBody> rb;
	std::shared_ptr<SoundSource> sound;
};