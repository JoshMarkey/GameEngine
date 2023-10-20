#pragma once
#include <memory>
namespace myengine
{
	struct Entity;

	struct Component
	{
	public:
		std::weak_ptr<Entity> m_entity;
	private:
		friend Entity;
		virtual void onTick();
		virtual void onDisplay();
		virtual void initialize();
		void tick();
		void display();
	};
}