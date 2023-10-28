#include "Core.h"
#include "Entity.h"
#include <Graphics/rend.h>
#include "NativeWindow.h"
#include "Enviroment.h"

namespace myengine
{
		std::shared_ptr<Core> Core::initialize()
		{
			std::shared_ptr<Core> rtn = std::make_shared<Core>();
			rtn->m_self = rtn;
			rtn->m_running = false;
			rtn->m_window = std::make_shared<NativeWindow>();
			rtn->m_resources = std::make_shared<Resources>();

			if (SDL_Init(SDL_INIT_VIDEO) < 0)
			{
				throw std::runtime_error("Failed to initialize SDL");
			}
			rtn->m_window->m_window = SDL_CreateWindow("SDL2 Platform",
				SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
				640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

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
			rtn->enviroment = std::make_shared<Enviroment>();
			rtn->enviroment->init();
			return rtn;
		}

		std::shared_ptr<Entity> Core::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

			m_entities.push_back(rtn);

			rtn->m_core = m_self.lock();
			rtn->m_self = rtn;

			return rtn;
		}

		void Core::run()
		{
			bool running = true;
			while (running)
			{
				SDL_Event event;
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT)
					{
						running = false;
					}
				}
				glClearColor(0, 1, 0, 1);
				glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

				enviroment->tick();

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->tick();
				}

				m_resources->checkDelete();

				for (int i = 0; i < m_entities.size(); i++)
				{
					m_entities[i]->display();
				}
				SDL_GL_SwapWindow(m_window->m_window);
			}
		}

		void Core::start()
		{

			m_running = true;
			while (m_running)
			{
				for (size_t ei = 0; ei < m_entities.size(); ++ei)
				{
					m_entities[ei]->tick();
				}

				for (size_t ei = 0; ei < m_entities.size(); ++ei)
				{
					if (!m_entities[ei]->alive())
					{
						m_entities.erase(m_entities.begin() + ei);
						--ei;
					}
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
}