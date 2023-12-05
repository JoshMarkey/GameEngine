#include "Graphics/rend.h"
namespace myengine
{
	struct Core;
	struct NativeWindow
	{
		~NativeWindow();
		glm::vec2 getWindowSize();
	private:
		friend Core;
		SDL_Window* m_window;
		SDL_GLContext m_context;

	};
}