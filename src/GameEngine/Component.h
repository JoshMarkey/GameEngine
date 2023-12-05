#pragma once
#include <memory>
namespace myengine
{
	struct Entity;
	struct Core;
	struct Gui;

	struct Component
	{
	public:
		std::weak_ptr<Entity> m_entity;
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Gui> getGui();
		float DT();
		std::shared_ptr<Entity> getEntity();
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay(std::shared_ptr<Entity> camera);
		virtual void onInitialise();
		void tick();
		void display(std::shared_ptr<Entity> camera);
		virtual void onGui();
	};
}