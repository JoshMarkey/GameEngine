#include "Resource.h"

myengine::Resource::Resource()
{
}


void myengine::Resource::onLoad(std::string _path)
{
}

std::string myengine::Resource::getPath() const
{
	return path;
}

void myengine::Resource::load(std::string _path)
{
	onLoad(_path);
}

