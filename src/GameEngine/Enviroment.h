
namespace myengine
{
	struct Core;
	struct Enviroment
	{
	private:
		friend Core;
		float lastTime;
		float deltaTime;
		void tick();
		void init();
	public:
		float DT();

	};
}