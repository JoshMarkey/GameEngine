#pragma once
#include "Core.h"
#include "Entity.h"
#include <Graphics/rend.h>
#include "NativeWindow.h"
#include "Enviroment.h"
#include "Transform.h"
#include "Audio.h"


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
			//sdl
			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				throw std::runtime_error("Failed to initialize SDL");
			}
			rtn->m_window->m_window = SDL_CreateWindow("SDL2 Platform",
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
			rtn->camera = rtn->addEntity();
			rtn->camera->addComponent<Camera>();
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

				glClearColor(0, 0, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

				m_enviroment->tick();

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->tick();
				}

				m_resources->checkDelete();

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->display(camera);
				}
				SDL_GL_SwapWindow(m_window->m_window);
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
}