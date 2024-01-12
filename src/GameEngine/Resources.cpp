#include "Resources.h"
#include "Enviroment.h"

#include "Core.h"
myengine::Resources::Resources()
{
}
void myengine::Resources::deleteResource(std::string _path)
{
	m_dirtyFlags.push_back(_path);
}

void myengine::Resources::checkDelete()
{
	//Check if any resources are queued to be deleted
	for (int it = 0; it < m_resources.size(); ++it)
	{
		bool check = m_resources[it]->addTimer(m_core->getEnviroment()->DT());
		if (check)
		{
			m_dirtyFlags.push_back(m_resources[it]->getPath());
		}
	}


	//If they are flagged, delete
	while (m_dirtyFlags.size() > 0)
	{
		std::string path = m_dirtyFlags.at(0);

		for (int ri = 0; ri < m_resources.size(); ri++)
		{
			if (m_resources.at(ri)->getPath() == path)
			{
				m_resources.erase(find(m_resources.begin(), m_resources.end(), m_resources.at(ri)));
				m_dirtyFlags.erase(m_dirtyFlags.begin());
				ri = 10000;
			}

		}

	}
}

void myengine::Resources::initialise(std::shared_ptr<Core> _core)
{
	m_core = _core;
}


