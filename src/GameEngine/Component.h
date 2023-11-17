#pragma once
#include <memory>
namespace myengine
{
	struct Entity;
	struct Core;

	struct Component
	{
	public:
		std::weak_ptr<Entity> m_entity;
		std::shared_ptr<Core> getCore();
		float DT();
		std::shared_ptr<Entity> getEntity();
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay();
		virtual void onInitialise();
		void tick();
		void display();
	};
}