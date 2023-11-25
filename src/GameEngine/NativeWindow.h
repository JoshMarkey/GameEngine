#include "Graphics/rend.h"
namespace myengine
{
	struct Core;
	struct NativeWindow
	{
		~NativeWindow();
	private:
		friend Core;
		SDL_Window* m_window;
		SDL_GLContext m_context;

	};
}