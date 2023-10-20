#include "Enviroment.h"
#include <windows.h>
namespace myengine 
{
	void Enviroment::tick()
	{
#ifdef _WIN32
		lastTime = GetTickCount();
#else
		struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		lastTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
		
#ifdef _WIN32
			DWORD curr = GetTickCount();
#else
			struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		double curr = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
		float diff = curr - lastTime;
		deltaTime = diff / 1000.0f;
		lastTime = curr;
	}
	float Enviroment::DT()
	{
		return deltaTime;
	}
}
