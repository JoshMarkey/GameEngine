#pragma once
#include "Resource.h"
#include <exception>
namespace myengine {
	struct Resources
	{
	public:
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			try
			{
				std::shared_ptr rtn = std::make_shared<T>(_path);
				rtn->load();
				m_resources.push_back(rtn);
				return rtn;
			}
			catch (exception& e)
			{
				std::cout << "Error loading resource: " << e << std::endl;
			}
		}

		void deleteResource(std::string _path);
		void checkDelete();

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::vector<std::string> deleteFlags;
	};
}