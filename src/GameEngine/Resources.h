#pragma once
#include <exception>
#include "Model.h"
#include "Texture.h"
#include "Shader.h"
namespace myengine {
	struct Core;
	/*
	Container for all resource instances
	Each resource is to be created via the load template function

	*/
	struct Resources
	{
	public:
		template <typename T>//Load resource of any type
		//Pass path + file ext. Each resource currently only supports 1 ext, but i found this as the easiest solution
		//Second path is only currently used for the shader, as you require a vert and frag
		//This lets me set the second path to empty.
		std::shared_ptr<T> load(std::string _path, std::string _path2 = "")
		{
			//Check whether resoure is already loaded before loading new one
			//Uses path as primary key to find the resource
			for (size_t i = 0; i < m_resources.size(); ++i)
			{
				if (m_resources.at(i)->getPath() == _path)
				{
					m_resources.at(i)->timer = 0;
					return std::dynamic_pointer_cast<T>  (m_resources.at(i));
				}
			}
			//If didnt find the resource, crete a new one
			std::shared_ptr<T> rtn = std::make_shared<T>();
			rtn->secondPath = _path2;

			rtn->load(_path);
			m_resources.push_back(rtn);
			return rtn;
		}


		Resources();
		void deleteResource(std::string _path);//Flag paths for deletion
		void checkDelete();//Safely delete all resources which are flagged for delete
		void initialise(std::shared_ptr<Core> _core);

	private:
		std::vector<std::shared_ptr<Resource> > m_resources;
		std::vector<std::string> m_dirtyFlags;
		std::shared_ptr<Core> m_core;
	};
}