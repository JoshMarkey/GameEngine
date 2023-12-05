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

glm::vec2 myengine::NativeWindow::getWindowSize()
{
	int w;
	int h;
	SDL_GetWindowSize(m_window, &w, &h);
	return glm::vec2(w, h);
}
