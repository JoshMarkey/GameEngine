namespace myengine
{
	struct Component
	{
	private:
		friend struct Entity;
		virtual void onTick();
		virtual void onDisplay();
		void tick();
		void display();
	};
}