#pragma once
#include "Component.h"
#include "Collider.h"
#include "Physics.h"
namespace myengine 
{
	/*
	Physics world RigidBody component
	This brings the colliders together and inserts them into the dynamic world
	*/
	struct RigidBody : Component
	{
		void setMass(float _mass);
		void setSimulate(bool _sim);
		void onPhysicsTick() override;//Add physics world changes to trans
		void onFrameEnd() override;//Add game world changes to dynamic world
		void init();
		~RigidBody();
	private:
		float m_mass; //Mass is used for physics calculations. If 0, the RB will not move in the sim
		bool m_simulate;//Flag used for if the collider provided is static
		std::shared_ptr<Collider> m_collider;
		btTransform m_trans;//Bullet Trans
		btRigidBody* m_body;//Bullet RB

	};
}
