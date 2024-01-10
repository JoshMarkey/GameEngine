#include "Resources.h"
#include "Enviroment.h"

#include "Core.h"
void myengine::Resources::deleteResource(std::string _path)
{
	deleteFlags.push_back(_path);
}

void myengine::Resources::checkDelete()
{
	for (int it = 0; it < m_resources.size(); ++it)
	{
		bool check = m_resources[it]->addTimer(core->getEnviroment()->DT());
		if (check)
		{
			deleteFlags.push_back(m_resources[it]->getPath());
		}
	}



	while (deleteFlags.size() > 0)
	{
		std::string path = deleteFlags.at(0);

		for (int ri = 0; ri < m_resources.size(); ri++)
		{
			if (m_resources.at(ri)->getPath() == path)
			{
				m_resources.erase(find(m_resources.begin(), m_resources.end(), m_resources.at(ri)));
				deleteFlags.erase(deleteFlags.begin());
				ri = 10000;
			}

		}

	}
}

void myengine::Resources::init(std::shared_ptr<Core> _core)
{
	core = _core;
}


