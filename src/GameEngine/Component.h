#pragma once
#include <memory>
namespace myengine
{
	struct Entity;
	struct Core;
	struct Gui;
	struct Physics;

	struct Component
	{
	public:
		std::weak_ptr<Entity> m_entity;
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Gui> getGui();
		std::shared_ptr<Physics> getPhysics();
		float DT();
		std::shared_ptr<Entity> getEntity();
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay(std::shared_ptr<Entity> camera);
		virtual void onInitialise();
		virtual void onPhysicsTick();
		void tick();
		void display(std::shared_ptr<Entity> camera);
		virtual void onGui();
		virtual void onFrameEnd();
	};
}