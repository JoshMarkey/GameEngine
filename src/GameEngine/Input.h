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
	public:
		~Input();
		void initialise();
		bool tick();
		bool getKey(int _keyCode);
		bool getKeyDown(int _keyCode);
		bool getKeyUp(int _keyCode);
		glm::vec2 getJoystickAxis();
		glm::vec2 getMousePos();
		glm::vec2 m_mousePos;
	private:
		std::vector<int> m_keys;
		std::vector<int> m_pressedKeys;
		std::vector<int> m_releasedKeys;
		glm::vec2 m_leftStick;
		glm::vec2 m_rightStick;
		SDL_GameController* m_ControllerHandles[MAX_CONTROLLERS];
		int JOYSTICK_DEAD_ZONE;

	};

	enum KeyCodes {
		//Keyboard
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
		//Mouse
		leftMouse = SDL_BUTTON_LEFT,
		rightMouse = SDL_BUTTON_RIGHT,
		middleMouse = SDL_BUTTON_MIDDLE,

		//Controller
		gpadUp = SDL_CONTROLLER_BUTTON_DPAD_UP,
		gpadDown = SDL_CONTROLLER_BUTTON_DPAD_DOWN,
		gpadLeft = SDL_CONTROLLER_BUTTON_DPAD_LEFT,
		gpadRight = SDL_CONTROLLER_BUTTON_DPAD_RIGHT,
		gpadStart = SDL_CONTROLLER_BUTTON_START,
		gpadBack = SDL_CONTROLLER_BUTTON_BACK,
		gpadLShoulder = SDL_CONTROLLER_BUTTON_LEFTSHOULDER,
		gpadRShoulder = SDL_CONTROLLER_BUTTON_RIGHTSHOULDER,
		gpadA = SDL_CONTROLLER_BUTTON_A,
		gpadB = SDL_CONTROLLER_BUTTON_B,
		gpadX = SDL_CONTROLLER_BUTTON_X,
		gpadY = SDL_CONTROLLER_BUTTON_Y,
		gpadStickX = SDL_CONTROLLER_AXIS_LEFTX,
		gpadStickY = SDL_CONTROLLER_AXIS_RIGHTX
	};
}