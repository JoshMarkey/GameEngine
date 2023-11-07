#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <iostream>
namespace myengine
{
	struct Core;
	struct Input
	{
		std::vector<int> keys;
		std::vector<int> pressedKeys;
		std::vector<int> releasedKeys;
	public:
		bool tick();
		bool getKey(int keyCode);
		bool getKeyDown(int keyCode);
		bool getKeyUp(int keyCode);
		void printKeys();
		int getCode(KeyCodes code);
	};

	enum KeyCodes {
		n1,
		n2,
		n3,
		n4,
		n5,
		n6,
		n7,
		n8,
		n9,
		n0,
		q,
		w,
		e,
		r,
		t,
		y,
		u,
		i,
		o,
		p,
		a,
		s,
		d,
		f,
		g,
		h,
		j,
		k,
		l,
		z,
		x,
		c,
		v,
		b,
		n,
		m,
		shift,
		control,
	};
}