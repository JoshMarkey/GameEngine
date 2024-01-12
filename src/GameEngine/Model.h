#pragma once
#include <memory>
#include "Resource.h"

namespace myengine
{
	struct Texture;
	/*
	Model loading from .obj file
	Interfaces with graphics libary to wrap
	Includes render function, although this currently doesnt do anything.

	*/
	struct Model : Resource
	{
		void onLoad(std::string _path) override;//Pass file path to load
		void linkTexture(std::shared_ptr<Texture> _tex);//Attatch texture with model
		void render();
		std::shared_ptr<graphics::Model> getModel();//This is to interface with graphics libary
		std::shared_ptr<graphics::Texture> getTexture();
		std::vector<bu::Face> getFaces();//Get faces for use in physics MeshCollider
	private:
		std::shared_ptr<graphics::Model> m_model;
		std::weak_ptr<Texture> m_texture;//Hold linking texture for rendering
	};
}