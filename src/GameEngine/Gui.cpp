#include "Gui.h"
#include "Core.h"
#pragma once
namespace myengine
{
	void Gui::initialise(std::shared_ptr<Core> _core)
	{
		m_core = _core;

		std::shared_ptr<graphics::Vbo> pos = std::make_shared<graphics::Vbo>();
		pos->add(glm::vec3(0.0f, 1.20f, 0.0f));
		pos->add(glm::vec3(0.0f, -0.20f, 0.0f));
		pos->add(glm::vec3(1.0f, -0.20f, 0.0f));
		pos->add(glm::vec3(1.0f, -0.20f, 0.0f));
		pos->add(glm::vec3(1.0f, 1.20f, 0.0f));
		pos->add(glm::vec3(0.0f, 1.20f, 0.0f));


		std::shared_ptr<graphics::Vbo> coords = std::make_shared<graphics::Vbo>();
		coords->add(glm::vec2(0.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 1.0f));
		coords->add(glm::vec2(1.0f, 0.0f));
		coords->add(glm::vec2(0.0f, 0.0f));

		m_Quad.addVbo(pos);
		m_Quad.addVbo(coords);

		fragPath = "../Shaders/GUI/FragShader.txt";
		vertPath = "../Shaders/GUI/VertShader.txt";
	}

	std::shared_ptr<Shader> Gui::getShader()
	{
		return m_core->getResources()->load<Shader>(fragPath, vertPath);
	}

	glm::mat4 Gui::getProjection()
	{
		return glm::ortho(0.0f,1000.0f,0.0f,800.0f, -1.0f, 1.0f);
	}
}