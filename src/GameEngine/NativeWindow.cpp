#include "NativeWindow.h"

myengine::NativeWindow::~NativeWindow()
{
	if (m_context)
	{
		SDL_GL_DeleteContext(m_context);
	}
	if (m_window)
	{
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}
}
