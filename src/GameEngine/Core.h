#pragma once
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "Resources.h"
#include "Input.h"
#include "Entity.h"
#include "Camera.h"
namespace myengine
{
	struct PointLight;
	struct NativeWindow;
	struct Enviroment;
	struct Audio;
	struct Gui;
	struct Physics;
	/*********************************************************************************************//**
	*Core contains the entire game and game loop
	*
	*Holds reference to every entity, component or data structure inside the game
	*Contains main loop which calls upon each virtual function inside the components via their entity
	*Contains a few virtual functions which can be overridden inside child
	*************************************************************************************************/
	struct Core
	{
	public:
		static std::shared_ptr<Core> initialise();//! Sets up and returns a core instance for use
		std::shared_ptr<Entity> addEntity();//! Creates a new entity with a transform and returns it
		void run();//! Main loop
		~Core();//! Clears all data
		std::shared_ptr<Enviroment> getEnviroment();//! Calculates DeltaTime
		std::shared_ptr<Resources> getResources();//! Stores all resources inside the game
		std::shared_ptr<Input> getInput();//! Polls all user interactions and stores them for use
		std::shared_ptr<Audio> getAudio();//! Initialises openAL
		std::shared_ptr<Gui> getGui();//! Contains functions to draw UI elements to screen
		std::shared_ptr<Physics> getPhysics();//! Holds physics world and interfaces entities to collide TODO: MAKE THIS WORK
		std::vector<std::shared_ptr<Entity> > m_cams;// Stores each camera in an array to let the user draw from multiple cameras
		std::shared_ptr<Camera> getPrimaryCam();//! First camera created is the primary
		glm::vec2 getWindowSize();//! Returns dimentions of window
		std::shared_ptr<PointLight> getLight();//! Returns the point light which is in the scene
		SDL_Window* getWindow(); //! return SDL window

		void stop();//! Stop main loop. Finish game

		/*******************************************************************************//**
	*Find all components of type T
	*
	*Search through each entity for specific component type
	*Returns vector of the result
	*@param _out reference to pointer of components found
	********************************************************************************/
		template <typename T>
		void find(std::vector<std::shared_ptr<T> >& _out)
		{
			for (size_t ei = 0; ei < m_entities.size(); ++ei)
			{
				std::shared_ptr<Entity> e = m_entities.at(ei);

				for (size_t ci = 0; ci < e->m_components.size(); ++ci)
				{
					std::shared_ptr<Component> c = e->m_components.at(ci);
					std::shared_ptr<T> t = std::dynamic_pointer_cast<T>(c);

					if (t)
					{
						_out.push_back(t);
					}
				}
			}
		}


		std::vector<std::shared_ptr<PointLight> > m_lights;//! Stores all lights in scene
		std::shared_ptr< Camera> m_lockedCam;//! Stores current camera to be looped through
		std::shared_ptr< NativeWindow> m_window;//! Contains reference to SDL window
		std::shared_ptr< Audio> m_audio;//! Contains reference to audio
		std::vector<std::shared_ptr<Entity>> m_entities;//! Holds all entities
		std::weak_ptr<Core>m_self; //! Pointer to self
		std::shared_ptr<Enviroment> m_enviroment;
		std::shared_ptr<Resources> m_resources;//! For interfacing all resources
		std::shared_ptr<Input> m_input;//! Hold all user inputs
		std::shared_ptr<Gui> m_gui;//! Allows for drawing GUI elements
		std::shared_ptr<Physics> m_physics;//! TODO
		bool m_running;//! Controls game looop
	};

}