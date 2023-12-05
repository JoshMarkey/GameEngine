#pragma once
namespace myengine
{
	//Simple rect to keep track of gui component positions and size
	struct Rect
	{
		Rect(int _x, int _y, float _w, float _h);
		int x;
		int y;
		float w;
		float h;
	};
}