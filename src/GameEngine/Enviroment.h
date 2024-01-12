#pragma once
#ifdef _WIN32
    #include <Windows.h>
#endif // #ifdef _WIN32


namespace myengine
{
	struct Core;
	//Handles delta time for various compilers
	//Call DT() on the instance to get time passed since last Frame
	struct Enviroment
	{
		friend Core;
#ifdef _WIN32
		DWORD m_lastTime;
#else
		double m_lastTime;
#endif // #ifdef _WIN32
		double m_deltaTime;
		void onTick();
		void initialise();
	public:
		float DT();

	};
}