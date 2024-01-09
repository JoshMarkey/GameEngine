#pragma once
#include <memory>
#include "glm/vec2.hpp"
namespace myengine
{
	struct Entity;
	struct Core;
	struct Gui;
	struct Physics;

	struct Component
	{
	public:
		int getKey(int k);
		int getKeyUp(int k);
		int getKeyDown(int k);
		glm::vec2 getJoystickAxis();
		std::weak_ptr<Entity> m_entity;
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Gui> getGui();
		std::shared_ptr<Physics> getPhysics();
		float DT();
		std::shared_ptr<Entity> getEntity();
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialise();
		virtual void onPhysicsTick();
		void tick();
		void display();
		virtual void onGui();
		virtual void onFrameEnd();
	};
}