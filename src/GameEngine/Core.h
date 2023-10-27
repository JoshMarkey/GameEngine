#include <memory>
#include <vector>
#include <SDL2/SDL.h>
namespace myengine
{
	struct Entity;
	struct NativeWindow;
	struct Enviroment;

	struct Core
	{
	public:
		std::shared_ptr< NativeWindow> m_window;
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();
		std::shared_ptr<Enviroment> enviroment;
		void run();
		~Core();

		void start();
		void stop();
	private:
		std::vector<std::shared_ptr<Entity>> m_entities;
		bool m_running;
		std::weak_ptr<Core>m_self;

	};

}