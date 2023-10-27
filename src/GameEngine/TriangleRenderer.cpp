#pragma once
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
		angle = 0.0f;
	}

	void TriangleRenderer::onDisplay()
	{
		std::shared_ptr<Entity> entity = m_entity.lock();
		m_shader.bindOrthoMatrix(entity->transform->getProjection(), entity->transform->getModel());
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


		m_shader = graphics::Shader("../Shaders/GUI/FragShader.txt", "../Shaders/GUI/VertShader.txt");

	}

	void TriangleRenderer::onTick()
	{
		std::shared_ptr<Entity> entity = m_entity.lock();
		angle = 360 * entity->m_core->enviroment->DT();
		//std::cout << angle << std::endl;
		entity->transform->rotate(angle,glm::vec3(0, 0, 1));
		if (angle > 360)
		{
			angle -= 360;
		}
	}
}