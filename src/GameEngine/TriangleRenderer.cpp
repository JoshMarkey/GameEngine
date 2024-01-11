#include "TriangleRenderer.h"
#include "Entity.h"
#include "Transform.h"
#include "Core.h"
#include "Enviroment.h"

namespace myengine
{
	TriangleRenderer::~TriangleRenderer()
	{

	}
	TriangleRenderer::TriangleRenderer()
	{
		m_angle = 0.0f;
	}

	void TriangleRenderer::onDisplay()
	{
		std::shared_ptr<Entity> entity = m_entity.lock();
		m_shader.bindOrthoMatrix(entity->m_transform->getProjection(), entity->m_transform->getModel());
		m_shader.renderOrtho(&m_Quad, &m_tex);
	}

	void TriangleRenderer::initialize()
	{
		std::shared_ptr<graphics::Vbo> pos = std::make_shared<graphics::Vbo>();
		pos->add(glm::vec3(-0.5f, 0.70f, 0.0f));
		pos->add(glm::vec3(-0.5f, -0.70f, 0.0f));
		pos->add(glm::vec3(0.5f, -0.70f, 0.0f));
		pos->add(glm::vec3(0.5f, -0.70f, 0.0f));
		pos->add(glm::vec3(0.5f, 0.70f, 0.0f));
		pos->add(glm::vec3(-0.5f, 0.70f, 0.0f));


		std::shared_ptr<graphics::Vbo> coords = std::make_shared<graphics::Vbo>();
		coords->add(glm::vec2(0.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 0.0f));

		m_Quad = graphics::Vao();
		m_Quad.addVbo(pos);
		m_Quad.addVbo(coords);

		//m_tex = Texture("../Models/Cat/tex.png");


		m_shader = graphics::Shader("../resources/Shaders/GUI/FragShader.txt", "../Shaders/GUI/VertShader.txt");

	}

	void TriangleRenderer::onTick()
	{
		std::shared_ptr<Entity> entity = m_entity.lock();
		m_angle = 360 * DT();
		//std::cout << angle << std::endl;
		entity->m_transform->rotate(glm::vec3(0, m_angle, 0));
		if (m_angle > 360)
		{
			m_angle -= 360;
		}
	}
}