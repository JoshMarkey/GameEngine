#include<memory>
#include<vector>
namespace myengine
{
	struct Component;
	struct Core;
	struct Transform;
	struct Entity
	{
		Entity();
		~Entity();
	public:
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->m_entity = m_self;
			rtn->onInitialise();
			m_components.push_back(rtn);
			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (int i = 0; i < m_components.size(); i++)
			{
				std::shared_ptr<T> rtn;
				rtn = std::dynamic_pointer_cast<T>(m_components.at(i));
				if (rtn)
				{
					return rtn;
				}
			}
			return NULL;
		}
		std::weak_ptr<Entity> m_self;
		std::vector<std::shared_ptr<Component>> m_components;
		std::shared_ptr<Transform> transform;
		void kill();
		std::shared_ptr<Core> getCore();

		void tick();

	private:
		bool alive();
		friend struct Core;
		bool m_alive;
		void display(std::shared_ptr<Entity> camera);
		std::shared_ptr<Core> m_core;
	};
}