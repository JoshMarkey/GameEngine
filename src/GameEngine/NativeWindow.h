#pragma once
#include "Graphics/rend.h"
namespace myengine
{
	struct Core;

	/*
	Wrapper for SDL window
	Getter for window size
	*/
	struct NativeWindow
	{
		~NativeWindow();
		glm::vec2 getWindowSize();
		SDL_Window* getWindow();
	private:
		friend Core;
		SDL_Window* m_window;
		SDL_GLContext m_context;

	};
}