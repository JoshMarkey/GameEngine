#pragma once
#include "KCollider.h"
#include <vector>
#include "Component.h"

namespace myengine
{
	/*
	Rigid body enables the collision response on colliders
	*/
	struct KRigidBody : Component
	{
		void onTick() override;//Check for collision. Set isColliding to true if one is found
		std::vector<std::shared_ptr<KCollider> > getColliders();
		bool isColliding;

	private:
		std::vector<std::shared_ptr<KCollider> > m_colliders;
	};
}