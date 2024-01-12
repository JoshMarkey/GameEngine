#pragma once
#include <string>
#include <Graphics/rend.h>
namespace myengine
{
	struct Texture;

	/*
	Resource is parent to all loaded resources
	When one is loaded via Resources class, onLoad is called
	Contains 2 paths. Usually only 1 is required
	Onload is to be called on the resource each time it is used, incase it has been deleted to free memory
	Stored "globally" so multiple components can reference only 1 instance. Saves memory and loading times
	*/
	struct Resource
	{
	public:
		Resource();
		virtual void onLoad(std::string _path);//Each resource overrides this in order to load their respective files and create their objects
		std::string getPath() const;
		void load(std::string _path);
		bool addTimer(float _dt);//to keep track of last time the resource was used.Can free some memory by deleting a resource which hasnt been used in a while
		float timer;
		float maxTime;
		std::string path;
		std::string secondPath;
	};
}