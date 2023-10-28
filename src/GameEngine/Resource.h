#pragma once
#include <string>
#include <Graphics/rend.h>
namespace myengine
{
	struct Resource
	{
	public:
		Resource(std::string _path);
		virtual void onLoad() = 0;
		std::string getPath() const;
	private:
		std::string path;
		void load();
	};
}