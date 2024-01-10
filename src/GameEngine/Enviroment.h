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
		DWORD lastTime;
#else
		double lastTime;
#endif // #ifdef _WIN32
		double deltaTime;
		void tick();
		void init();
	public:
		float DT();

	};
}