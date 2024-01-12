#pragma once
#include<memory>
#include<vector>
namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;
	/*******************************************************************************//**
	*Entities are game objects
	*
	*Entities store components, these contain all the game logic
	********************************************************************************/
	struct Entity
	{
		Entity();//! Constructor
		~Entity();//! Deconstructor
	public:
		/*******************************************************************************//**
	*Add component of typt T to entity
	*
	*A new component is created and pushed into the list of components inside the entity
	*
	*OnInitialise is called on the Component as it has just been made
	********************************************************************************/
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_entity = m_self;
			m_components.push_back(rtn);
			rtn->onInitialise();
			return rtn;
		}

		template <typename T>//! Template function to return a pointer to component of type T
		std::shared_ptr<T> getComponent()
		{
			for (int i = 0; i < m_components.size(); i++)
			{
				std::shared_ptr<T> rtn;
				rtn = std::dynamic_pointer_cast<T>(m_components.at(i));
				if (rtn)
				{
					return rtn;
				}
			}
			return NULL;
		}
		std::weak_ptr<Entity> m_self;//! pointer to self
		std::vector<std::shared_ptr<Component>> m_components;//! Vector containing all components of this entity
		void kill();//! Marks the entity to be killed
		std::shared_ptr<Core> getCore();//! Shortcut to core
		std::shared_ptr<Transform> getTransform();//! Shortcut to transform as each entity has one
		void tick();//! Tick function passed to components
		void onGui();//! Gui function passed to components
		void onFrameEnd();//! End frame function passed to components
		void onPhysicsTick();//! Physics tick function passed to components
		void display();//! Display function passed to components
		bool alive();//! Getter for alive
		void setAlive(bool _bool);//! Setter for alive
	private:
		std::shared_ptr<Transform> m_transform;//! Transform pointer as each Entity has one
		friend struct Core;//! Friend core to give it full access to class
		bool m_alive;//! Alive flag
		std::shared_ptr<Core> m_core;//! Pointer to core
	};
}