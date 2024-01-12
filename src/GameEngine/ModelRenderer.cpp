#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"
#include "Camera.h"

namespace myengine
{
	void ModelRenderer::onDisplay()
	{
		std::shared_ptr<Entity> entity = getEntity();
		std::shared_ptr<Shader> shader;

		//If light in scene, use light shader
		std::shared_ptr<PointLight> light = getCore()->getLight();
		if (light != NULL)
		{
			shader = getCore()->getResources()->load<Shader>(m_lightFragPath, m_lightVertPath);
			shader->m_shader.get()->bindVec3("u_LightPos", light->getPosition());
			shader->m_shader.get()->bindMatrix("u_InverseView", glm::inverse(getCore()->getPrimaryCam()->getView()));
			shader->m_shader.get()->bindFloat("u_Brightness", light->getBrightness());
		}
		else
		{
			shader = getCore()->getResources()->load<Shader>(m_defaultFragPath, m_defaultVertPath);
		}



		std::shared_ptr<Model> model = getCore()->getResources()->load<Model>(m_modelPath);
		std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>(m_texPath);

		shader->m_shader.get()->bindMatrix("u_Projection", getCore()->getPrimaryCam()->getProjection());
		shader->m_shader.get()->bindMatrix("u_Viewing", getCore()->getPrimaryCam()->getView());
		shader->m_shader.get()->bindMatrix("u_Model", entity->getTransform()->getModel());

		


		shader->m_shader.get()->render(model->getModel().get(), tex->getTexture().get(),backface);
	}

	void ModelRenderer::onInitialise()
	{
		//Default paths to start with. Should limit errors.
		m_modelPath = "../resources/Models/Cat/Model.obj";
		m_texPath = "../resources/Models/Cat/Tex.png";
		m_lightFragPath = "../resources/Shaders/Light/FragShader.txt";
		m_lightVertPath = "../resources/Shaders/Light/VertShader.txt";
		m_defaultFragPath = "../resources/Shaders/Default/FragShader.txt";
		m_defaultVertPath = "../resources/Shaders/Default/VertShader.txt";

		std::shared_ptr<Model> mod = getCore()->getResources()->load<Model>(m_modelPath);
		backface = true;
	}

	void ModelRenderer::setFrag(std::string p)
	{
		m_defaultFragPath = p;
	}

	void ModelRenderer::setVert(std::string p)
	{
		m_defaultVertPath = p;
	}

	void ModelRenderer::setModel(std::string p)
	{
		m_modelPath = p;
	}

	void ModelRenderer::setTexture(std::string p)
	{
		m_texPath = p;
	}
	std::vector<bu::Face> ModelRenderer::getFaces()
	{
		std::shared_ptr<Model> model = getCore()->getResources()->load<Model>(m_modelPath);
		model->getModel()->getId();
		return model->getFaces();
	}
	void ModelRenderer::setBackFace(bool b)
	{
		backface = b;
	}
}