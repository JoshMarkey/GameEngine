#include "Resource.h"

myengine::Resource::Resource(std::string _path) : path(_path)
{
	
}

std::string myengine::Resource::getPath() const
{
	return path;
}

void myengine::Resource::load()
{
	onLoad();
}
