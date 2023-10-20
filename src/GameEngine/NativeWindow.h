#include "Graphics/rend.h"
namespace myengine
{
	struct NativeWindow
	{
		SDL_Window* m_window;
		SDL_GLContext m_context;

		~NativeWindow();
	};
}