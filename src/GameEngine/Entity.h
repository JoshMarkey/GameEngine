#include<memory>
#include<vector>
namespace myengine
{
	struct Core;
	struct Component;
	struct Entity
	{
		Entity();

	public:

		std::weak_ptr<Entity> m_self;
		std::shared_ptr<Core> m_core;
		std::vector<std::shared_ptr<Component>> m_components;
		void kill();

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_entity = m_self;
			rtn->initialize();
			m_components.push_back(rtn);
			return rtn;
		}

		void tick();
		bool alive();
	private:
		bool m_alive;
		void display();
	};
}