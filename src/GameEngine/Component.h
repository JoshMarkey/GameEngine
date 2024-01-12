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
	/*******************************************************************************//**
	*Components are 'scripts' attatched to each entity
	*
	*Components are to be added to entity's via the addComponent func in Entity.
	*This is where the user creates behaviour and logic for the entitys - done by inheriting this class
	*Contains a few virtual functions which can be overridden inside child
	********************************************************************************/
	struct Component
	{
	public:
		int getKey(int _k);//! True if key is currently pressed down
		int getKeyUp(int _k);//! True if key released on that frame
		int getKeyDown(int _k);//! True if key is pressed that frame
		glm::vec2 getJoystickAxis();//! Returns the position of the joystick
		std::shared_ptr<Core> getCore();//! Returns a pointer to core
		std::shared_ptr<Gui> getGui();//! Returns a pointer to GUI
		std::shared_ptr<Physics> getPhysics();//! Returns a pointer to physics
		float DT();//! Returns delta time
		std::shared_ptr<Entity> getEntity();//! Returns parent entity
		glm::vec3 getPosition();//! Returns transform position
	private:
		friend Entity;//! Allow entity to have full access to this class
		std::weak_ptr<Entity> m_entity; //! weak ptr to parent entity
		virtual void onTick();//! Calls at the start of each Frame. Should contain majority of logic
		virtual void onDisplay();//! Calls to display. This will most likely only be used in the provided ModelRenderer component
		virtual void onInitialise();//! Each time a component is created, this is instantly called
		virtual void onPhysicsTick();//! Called in order to update various physics components when the physics world ticks
		void tick();
		virtual void onGui();//! Called after display, designed for drawing UI on top of all 3D objects
		virtual void onFrameEnd();//! Called right at the end of a frame
	};
}