#include "Enviroment.h"
#include <iostream>
#ifndef _WIN32
#include <sys/time.h>
#endif // !_WIN32

namespace myengine
{
	void Enviroment::initialise()
	{
#ifdef _WIN32
		m_lastTime = GetTickCount();
#else
		struct timeval tv = { 0 };
		gettimeofday(&tv, NULL);
		m_lastTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
	}
		void Enviroment::onTick() {
#ifdef _WIN32
			DWORD curr = GetTickCount();
#else
			struct timeval tv = { 0 };
			gettimeofday(&tv, NULL);
			double curr = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
#endif
			double diff = curr - m_lastTime;


			m_deltaTime = diff / 1000.0f;
			m_lastTime = curr;
		}
		float Enviroment::DT()
		{
			if (m_deltaTime == 0.0f)
			{
				return 0.01f;
			}
			return m_deltaTime;
		}
}
