#include <memory>
#include <vector>
namespace myengine
{
	struct Entity;
		struct Core
		{
			static std::shared_ptr<Core> initialize();
			std::shared_ptr<Entity> addEntity();

			void start();
			void stop();
		private:
			SDL_Window* m_window;
			SDL_GLContext* m_context;
			std::vector<std::shared_ptr<Entity>> m_entities;
			bool m_running;
			std::weak_ptr<Core>m_self;

		};

}