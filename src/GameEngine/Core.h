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


		void start();
		void stop();
	private:
		std::shared_ptr< NativeWindow> m_window;
		std::vector<std::shared_ptr<Entity>> m_entities;
		bool m_running;
		std::weak_ptr<Core>m_self;
		std::shared_ptr<Enviroment> m_enviroment;
		std::shared_ptr<Resources> m_resources;
		std::shared_ptr<Input> m_input;

	};

}