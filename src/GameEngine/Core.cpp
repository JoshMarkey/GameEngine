#pragma once
#include "Core.h"
#include "Entity.h"
#include <Graphics/rend.h>
#include "NativeWindow.h"
#include "Enviroment.h"
#include "Transform.h"
#include "Audio.h"
#include "Gui.h"
#include "Physics.h"

namespace myengine
{
		std::shared_ptr<Core> Core::initialize()
		{
			std::shared_ptr<Core> rtn = std::make_shared<Core>();
			rtn->m_self = rtn;
			rtn->m_running = false;
			rtn->m_window = std::make_shared<NativeWindow>();
			rtn->m_resources = std::make_shared<Resources>();
			rtn->m_input = std::make_shared<Input>();
			rtn->m_audio = std::make_shared<Audio>();
			rtn->m_physics = std::make_shared<Physics>();
			rtn->m_gui = std::make_shared<Gui>();
			//sdl
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				throw std::runtime_error("Failed to initialize SDL");
			}
			rtn->m_window->m_window = SDL_CreateWindow("GameEngine",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				1000, 800, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

			if (!rtn->m_window->m_window)
			{
				SDL_Quit();
				throw std::runtime_error("Failed to create Window");
			}
			rtn->m_window->m_context = SDL_GL_CreateContext(rtn->m_window->m_window);
			if(!rtn->m_window->m_context)
			{
				SDL_DestroyWindow(rtn->m_window->m_window);
				SDL_Quit();
				throw std::runtime_error("Failed to create OpenGL context");
			}

			glewInit();
			//audio
			rtn->m_audio->m_device = alcOpenDevice(NULL);

			if (!rtn->m_audio->m_device)
			{
				throw std::runtime_error("Failed to open audio device");
			}

			rtn->m_audio->m_context = alcCreateContext(rtn->m_audio->m_device, NULL);

			if (!rtn->m_audio->m_context)
			{
				alcCloseDevice(rtn->m_audio->m_device);
				throw std::runtime_error("Failed to create audio context");
			}

			if (!alcMakeContextCurrent(rtn->m_audio->m_context))
			{
				alcDestroyContext(rtn->m_audio->m_context);
				alcCloseDevice(rtn->m_audio->m_device);
				throw std::runtime_error("Failed to make context current");
			}


			rtn->m_enviroment = std::make_shared<Enviroment>();
			rtn->m_enviroment->init();
			rtn->m_gui->initialise(rtn);
			rtn->m_physics->Init(rtn);
			rtn->cameras.push_back(rtn->addEntity());
			rtn->cameras[0]->addComponent<Camera>();
			rtn->lockedCam = rtn->cameras[0]->getComponent<Camera>();
			return rtn;
		}

		std::shared_ptr<Entity> Core::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

			m_entities.push_back(rtn);

			rtn->m_core = m_self.lock();
			rtn->m_self = rtn;
			rtn->transform = rtn->addComponent<Transform>();

			return rtn;
		}

		void Core::run()
		{
			m_running = true;
			while (m_running)
			{
				if (!m_input->tick())
				{
					return;
				}

				if (m_input->getKeyDown(SDLK_ESCAPE))
				{
					m_running = false;
				}

				glClearColor(0, 1, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

				m_enviroment->tick();
				m_physics->tick();
				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->onPhysicsTick();
				}

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->tick();
				}

				m_resources->checkDelete();

				for (int x = 0; x >= cameras.size(); x++)
				{
					lockedCam = cameras[x]->getComponent<Camera>();
					for (int i = 0; i < m_entities.size(); i++)
					{
						m_entities[i]->display();
					}
				}

				lockedCam = cameras[0]->getComponent<Camera>();

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->onGui();
				}

				SDL_GL_SwapWindow(m_window->m_window);

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->onFrameEnd();
				}
			}
		}


		void Core::stop()
		{
			m_running = false;
		}

		Core::~Core()
		{
		}
		std::shared_ptr<Enviroment> Core::getEnviroment()
		{
			return m_enviroment;
		}
		std::shared_ptr<Resources> Core::getResources()
		{
			return m_resources;
		}
		std::shared_ptr<Input> Core::getInput()
		{
			return m_input;
		}
		std::shared_ptr<Audio> Core::getAudio()
		{
			return m_audio;
		}
		std::shared_ptr<Gui> Core::getGui()
		{
			return m_gui;
		}
		std::shared_ptr<Physics> Core::getPhysics()
		{
			return m_physics;
		}
		std::shared_ptr<Camera> Core::getPrimaryCam()
		{
			return lockedCam;
		}
		glm::vec2 Core::getWindowSize()
		{
			return m_window->getWindowSize();
		}
}