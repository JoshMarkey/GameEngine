#pragma once
#include <exception>
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
namespace myengine {
	struct Core;
	struct Resources
	{
	public:
		template <typename T>
		std::shared_ptr<T> load(std::string _path, std::string _path2 = "")
		{
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				if (m_resources.at(i)->getPath() == _path)
				{
					m_resources.at(i)->timer = 0;
					return std::dynamic_pointer_cast<T>  (m_resources.at(i));
				}
			}

			try
			{
				std::shared_ptr<T> rtn = std::make_shared<T>();
				rtn->secondPath = _path2;

				rtn->load(_path);
				m_resources.push_back(rtn);
				return rtn;
			}
			catch (std::exception& e)
			{
				std::cout << "Error loading resource: " << e.what() << std::endl;
			}
			return NULL;
		}


		Resources();
		void deleteResource(std::string _path);
		void checkDelete();
		void initialise(std::shared_ptr<Core> _core);

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::vector<std::string> m_dirtyFlags;
		std::shared_ptr<Core> m_core;
	};
}