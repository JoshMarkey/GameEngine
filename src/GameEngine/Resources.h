#pragma once
#include "Resource.h"
namespace myengine {
	struct Resources
	{
		template <typename T>
		std::shared_ptr<T> load(const std::string& _path)
		{
			// TODO
		}
	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
	};
}