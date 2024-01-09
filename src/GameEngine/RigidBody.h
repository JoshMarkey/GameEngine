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
		void onPhysicsTick() override;
		void onFrameEnd() override;
		void init();
		~RigidBody();
	private:
		float m_mass;
		bool simulate;
		std::shared_ptr<Collider> col;
		btTransform m_trans;
		btRigidBody* m_body;

	};}