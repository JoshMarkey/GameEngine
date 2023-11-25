#pragma once
#include <memory>
#include <vector>
#include <SDL2/SDL.h>
#include "Resources.h"
#include "Input.h"
namespace myengine
{
	struct Entity;
	struct NativeWindow;
	struct Enviroment;
	struct Audio;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		void run();
		~Core();
		std::shared_ptr<Enviroment> getEnviroment();
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Input> getInput();
		std::shared_ptr<Audio> getAudio();


		void start();
		void stop();

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



	private:
		std::shared_ptr< NativeWindow> m_window;
		std::shared_ptr< Audio> m_audio;
		std::vector<std::shared_ptr<Entity>> m_entities;
		bool m_running;
		std::weak_ptr<Core>m_self;
		std::shared_ptr<Enviroment> m_enviroment;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;

	};

}