#include <memory>
#include <vector>
#include <SDL2/SDL.h>
namespace myengine
{
	struct Entity;

	struct Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

		~Core();

		void start();
		void stop();
		SDL_Window* m_window;
		SDL_GLContext m_context;
	private:
		std::vector<std::shared_ptr<Entity>> m_entities;
		bool m_running;
		std::weak_ptr<Core>m_self;

	};

}