#pragma once
#include <string>
#include <Graphics/rend.h>
namespace myengine
{
	struct Texture;
	struct Resource
	{
	public:
		Resource();
		virtual void onLoad(std::string _path);
		std::string getPath() const;
		void load(std::string _path);
		std::string path;
		std::string secondPath;
		bool addTimer(float _dt);
		float maxTime;
		float timer;
	private:
	};
}