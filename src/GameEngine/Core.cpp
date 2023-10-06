#include "Core.h"
#include "Entity.h"

namespace myengine
{
		std::shared_ptr<Core> Core::initialize()
		{
			std::shared_ptr<Core> rtn = std::make_shared<Core>();
			return rtn;
		}
		std::shared_ptr<Entity> Core::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

			rtn->m_core = m_self.lock();
			rtn->m_self = rtn;

			return rtn;
		}
		void Core::start()
		{
			m_running = true;
			while (m_running)
			{
				for (size_t ei = 0; ei < m_entities.size(); ++ei)
				{
					m_entities[ei]->tick();
				}

				for (size_t ei = 0; ei < m_entities.size(); ++ei)
				{
					if (!m_entities[ei]->alive())
					{
						m_entities.erase(m_entities.begin() + ei);
						--ei;
					}
				}

			}
		}
		void Core::stop()
		{
			m_running = false;
		}
}