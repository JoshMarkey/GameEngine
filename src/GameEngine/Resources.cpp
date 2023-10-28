#include "Resources.h"

void myengine::Resources::deleteResource(std::string _path)
{
	deleteFlags.push_back(_path);
}

void myengine::Resources::checkDelete()
{
	while (deleteFlags.size() > 0)
	{
		for (auto it = std::begin(m_resources); it != std::end(m_resources); ++it)
		{
			if (it->get()->getPath() == deleteFlags.at(0))
			{
				m_resources.erase(it);
				break;
			}
		}

		std::cout << "Unable to find resource: " << deleteFlags.at(0) << std::endl;
		deleteFlags.erase(deleteFlags.begin());
	}
}
