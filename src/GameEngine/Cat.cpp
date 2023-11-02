#include "Cat.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"

namespace myengine
{
	Cat::Cat()
	{
	}
	Cat::~Cat()
	{
	}
	void Cat::onDisplay()
	{

		std::shared_ptr<Entity> entity = m_entity.lock();

		std::shared_ptr<Shader> lightShader = entity->m_core->m_resources->load<Shader>(fragPath, vertPath);
		std::shared_ptr<Model> model = entity->m_core->m_resources->load<Model>("../Models/Cat/Model.obj");

		lightShader->m_shader.get()->bindMatrix("u_Projection", entity->transform->getProjection());
		lightShader->m_shader.get()->bindMatrix("u_Model", entity->transform->getModel());

		lightShader->m_shader.get()->render(model->getModel().get(), model->getTexture().get());

	}
	void Cat::initialize()
	{

		std::shared_ptr<Entity> entity = m_entity.lock();
		entity->transform->move(glm::vec3(0, -0.5, -8));

		modelPath = "../Models/Cat/Model.obj";
		texPath = "../Models/Cat/Tex.png";


		fragPath = "../Shaders/Light/FragShader.txt";
		vertPath = "../Shaders/Light/VertShader.txt";

		std::shared_ptr<Model> catModel = entity->m_core->m_resources->load<Model>(modelPath);
		std::shared_ptr<Texture> catTex = entity->m_core->m_resources->load<Texture>(texPath);
		catModel->linkTexture(catTex);
	}

	void Cat::onTick()
	{
		std::shared_ptr<Entity> entity = m_entity.lock();
		angle = 360 * entity->m_core->enviroment->DT();
		//std::cout << angle << std::endl;
		entity->transform->rotate(glm::vec3(0, angle, 0));
		if (angle > 360)
		{
			angle -= 360;
		}
	}
}