#pragma once
#include "Component.h"
#include <Graphics/rend.h>
#include "PointLight.h"

namespace myengine
{
	struct Entity;

	/*
	Attatch to an entity to render a model
	Only the first PointLight in the scene will be used. TODO: Push array of light positions to shader and compute each
	*/
	struct ModelRenderer : Component
	{
		void onDisplay() override;//contains logic to display model
		void onInitialise() override;
		void setFrag(std::string _p);//Set frag shader file path
		void setVert(std::string _p);//Set vertex shader file path
		void setModel(std::string _p);//Set model file path
		void setTexture(std::string _p);//Set texture file path
		std::vector<bu::Face> getFaces();//Stores all tris in the model for use in mesh colliders
		void setBackFace(bool b);//Enable/disable backface culling
	private:
		bool backface;
		graphics::Camera m_cam;
		std::string m_modelPath;
		std::string m_texPath;
		std::string m_lightVertPath;
		std::string m_lightFragPath;
		std::string m_defaultVertPath;//Default shaders dont include any lighting - Used when no point light is created
		std::string m_defaultFragPath;
	};
}