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
		std::shared_ptr<Entity> entity = m_entity.lock();

		std::shared_ptr<Shader> lightShader = getCore()->getResources()->load<Shader>(fragPath, vertPath);
		std::shared_ptr<Model> model = getCore()->getResources()->load<Model>(modelPath);
		std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>(texPath);


		lightShader->m_shader.get()->bindMatrix("u_Projection", getCore()->getPrimaryCam()->getProjection());
		lightShader->m_shader.get()->bindMatrix("u_Viewing", getCore()->getPrimaryCam()->getView());
		lightShader->m_shader.get()->bindMatrix("u_Model", entity->transform->getModel());

		lightShader->m_shader.get()->render(model->getModel().get(), tex->getTexture().get());
	}

	void ModelRenderer::onInitialise()
	{
		modelPath = "../resources/Models/Cat/Model.obj";
		texPath = "../resources/Models/Cat/Tex.png";
		fragPath = "../resources/Shaders/Light/FragShader.txt";
		vertPath = "../resources/Shaders/Light/VertShader.txt";

		std::shared_ptr<Model> mod = getCore()->getResources()->load<Model>(modelPath);
	}

	void ModelRenderer::setFrag(std::string p)
	{
		fragPath = p;
	}

	void ModelRenderer::setVert(std::string p)
	{
		vertPath = p;
	}

	void ModelRenderer::setModel(std::string p)
	{
		modelPath = p;
	}

	void ModelRenderer::setTexture(std::string p)
	{
		texPath = p;
	}
	std::vector<bu::Face> ModelRenderer::getFaces()
	{
		std::shared_ptr<Model> model = getCore()->getResources()->load<Model>(modelPath);
		model->getModel()->getId();
		return model->getFaces();
	}
}