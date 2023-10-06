namespace myengine
{
	struct Component
	{
	public:
		virtual void onTick();
		virtual void onDisplay();
		void tick();
		void display();
	};
}