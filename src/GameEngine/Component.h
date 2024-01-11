#pragma once
#include <memory>
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"
namespace myengine
{
	struct Transform;
	struct Entity;
	struct Core;
	struct Gui;
	struct Physics;

	struct Component
	{
	public:
		int getKey(int _k);
		int getKeyUp(int _k);
		int getKeyDown(int _k);
		glm::vec2 getJoystickAxis();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Gui> getGui();
		std::shared_ptr<Physics> getPhysics();
		float DT();
		std::shared_ptr<Entity> getEntity();
		glm::vec3 getPosition();
		std::weak_ptr<Entity> m_entity;
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialise();
		virtual void onPhysicsTick();
		void tick();
		virtual void onGui();
		virtual void onFrameEnd();
	};
}