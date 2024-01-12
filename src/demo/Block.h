#pragma once
#include <GameEngine/GameEngine.h>

using namespace myengine;

struct Block : Component
{
	void onInitialise() override;
	std::shared_ptr<ModelRenderer> model;
};