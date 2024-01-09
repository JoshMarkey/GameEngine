#pragma once
#include <GameEngine/Transform.h>
#include <GameEngine/MeshCollider.h>
#include <GameEngine/RigidBody.h>
#include <GameEngine/Core.h>
#include <GameEngine/Component.h>
#include <GameEngine/Entity.h>
#include <GameEngine/ModelRenderer.h>
#include <GameEngine/SoundSource.h>
using namespace myengine;

struct Map : Component
{
	std::string modelPath;
	std::string texturePath;
	Map();
	void onInitialise() override;
};