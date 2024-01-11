#ifdef _WIN32
    #include <Windows.h>
#endif // #ifdef _WIN32


namespace myengine
{
	struct Core;
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