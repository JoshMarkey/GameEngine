
#include <windows.h>

namespace myengine
{
	struct Core;
	struct Enviroment
	{
	private:
		friend Core;
		DWORD lastTime;
		float deltaTime;
		void tick();
		void init();
	public:
		float DT();

	};
}