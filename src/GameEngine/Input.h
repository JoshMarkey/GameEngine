#pragma once

#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
#include <glm/ext.hpp>
namespace myengine
{
#define MAX_CONTROLLERS 4

	struct Core;
	struct Input
	{
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
		glm::vec2 mousePos;
		SDL_GameController* ControllerHandles[MAX_CONTROLLERS];
	public:
		void init();
		bool tick();
		bool getKey(int keyCode);
		bool getKeyDown(int keyCode);
		bool getKeyUp(int keyCode);

	};

	enum KeyCodes {
		n1 = SDLK_1,
		n2 = SDLK_2,
		n3 = SDLK_3,
		n4 = SDLK_4,
		n5 = SDLK_5,
		n6 = SDLK_6,
		n7 = SDLK_7,
		n8 = SDLK_8,
		n9 = SDLK_9,
		n0 = SDLK_0,
		q = SDLK_q,
		w = SDLK_w,
		e = SDLK_e,
		r = SDLK_r,
		t = SDLK_t,
		y = SDLK_y,
		u = SDLK_u,
		i = SDLK_i,
		o = SDLK_o,
		p = SDLK_p,
		a = SDLK_a,
		s = SDLK_s,
		d = SDLK_d,
		f = SDLK_f,
		g = SDLK_g,
		h = SDLK_h,
		j = SDLK_j,
		k = SDLK_k,
		l = SDLK_l,
		z = SDLK_z ,
		x = SDLK_x,
		c = SDLK_c,
		v = SDLK_v,
		b = SDLK_b,
		n = SDLK_n,
		m = SDLK_m,
		shift = SDLK_LSHIFT,
		control = SDLK_LCTRL,
		leftMouse = SDL_BUTTON_LEFT,
		rightMouse = SDL_BUTTON_RIGHT,
		middleMouse = SDL_BUTTON_MIDDLE
	};
}