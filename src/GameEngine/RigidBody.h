#pragma once
#include "Component.h"
#include "Collider.h"
#include "Physics.h"
namespace myengine 
{
	struct RigidBody : Component
	{
		void onTick() override;
		void setMass(float _mass);
		void setSimulate(bool _sim);
		void onInitialise() override;
		void onPhysicsTick() override;
		~RigidBody();
	private:
		float m_mass;
		bool simulate;

		btTransform m_trans;
		btRigidBody* m_body;

	};}