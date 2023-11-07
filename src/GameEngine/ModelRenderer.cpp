
#include "ModelRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"

void myengine::ModelRenderer::onDisplay()
{
	std::shared_ptr<Entity> entity = m_entity.lock();

	std::shared_ptr<Shader> lightShader = getCore()->getResources()->load<Shader>(fragPath, vertPath);
	std::shared_ptr<Model> model = getCore()->getResources()->load<Model>(modelPath);
	std::shared_ptr<Texture> tex = getCore()->getResources()->load<Texture>(texPath);


	lightShader->m_shader.get()->bindMatrix("u_Projection", entity->transform->getProjection());
	lightShader->m_shader.get()->bindMatrix("u_Model", entity->transform->getModel());

	lightShader->m_shader.get()->render(model->getModel().get(), tex->getTexture().get());
}

void myengine::ModelRenderer::onInitialise()
{
	modelPath = "../Models/Cat/Model.obj";
	texPath = "../Models/Cat/Tex.png";
	fragPath = "../Shaders/Light/FragShader.txt";
	vertPath = "../Shaders/Light/VertShader.txt";

	std::shared_ptr<Model> mod = getCore()->getResources()->load<Model>(modelPath);
}

void myengine::ModelRenderer::setFrag(std::string p)
{
	fragPath = p;
}

void myengine::ModelRenderer::setVert(std::string p)
{
	vertPath = p;
}

void myengine::ModelRenderer::setModel(std::string p)
{
	modelPath = p;
}

void myengine::ModelRenderer::setTexture(std::string p)
{
	texPath = p;
}