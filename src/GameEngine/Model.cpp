#pragma once
#include "Model.h"
#include "Texture.h"
namespace myengine
{
	void Model::onLoad(std::string _path)
	{
		path = _path;
		m_model = std::make_shared<graphics::Model>(getPath().c_str());
	}
	void Model::linkTexture(std::shared_ptr<Texture> tex)
	{
		m_texture = tex;
	}

	std::shared_ptr<graphics::Model> Model::getModel()
	{
		return m_model;
	}

	std::shared_ptr<graphics::Texture> Model::getTexture()
	{
		return m_texture.lock()->getTexture();
	}

	

	
}
