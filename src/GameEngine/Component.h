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
	/*
	Components are to be added to entity's via the addComponent func in Entity.
	This is where the user creates behaviour and logic for the entitys - done by inheriting this class
	Contains a few virtual functions which can be overridden inside child
	
	*/
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
		virtual void onTick();//Calls at the start of each Frame. Should contain majority of logic
		virtual void onDisplay();//Calls to display. This will most likely only be used in the provided ModelRenderer component
		virtual void onInitialise();//Each time a component is created, this is instantly called
		virtual void onPhysicsTick();//Called in order to update various physics components when the physics world ticks
		void tick();
		virtual void onGui();//Called after display, designed for drawing UI on top of all 3D objects
		virtual void onFrameEnd();//Called right at the end of a frame
	};
}