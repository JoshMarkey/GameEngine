#include "Enviroment.h"
#include <iostream>
namespace myengine
{
	void Enviroment::init()
	{
#ifdef _WIN32
		lastTime = GetTickCount();
#else
		struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		lastTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
	}
		void Enviroment::tick() {
#ifdef _WIN32
			DWORD curr = GetTickCount();
			//std::cout << "**********" << curr << std::endl;
#else
			struct timeval tv = { 0 };
			gettimeofday(&tv, NULL);
			double curr = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
			//std::cout << tv.tv_sec << "			" << tv.tv_usec << std:::endl;
#endif
			float diff = curr - lastTime;

			std::cout << curr << "     " << lastTime << std::endl;

			deltaTime = diff / 1000.0f;
			lastTime = curr;
		}
		float Enviroment::DT()
		{
			//std::cout << deltaTime << std::endl;
			if (deltaTime == 0.0f)
			{
				return 0.01f;
			}
			return deltaTime;
		}
}
