#include "TriangleRenderer.h"

myengine::TriangleRenderer::TriangleRenderer()
{

}

void myengine::TriangleRenderer::onDisplay()
{
	m_shader.renderOrtho(&m_Quad, &m_tex);
}

void myengine::TriangleRenderer::initialize()
{
	std::shared_ptr<Vbo> pos = std::make_shared<Vbo>();
	pos->add(glm::vec3(-0.5f, 0.70f, 0.0f));
	pos->add(glm::vec3(-0.5f, -0.70f, 0.0f));
	pos->add(glm::vec3(0.5f, -0.70f, 0.0f));
	pos->add(glm::vec3(0.5f, -0.70f, 0.0f));
	pos->add(glm::vec3(0.5f, 0.70f, 0.0f));
	pos->add(glm::vec3(-0.5f, 0.70f, 0.0f));


	std::shared_ptr<Vbo> coords = std::make_shared<Vbo>();
	coords->add(glm::vec2(0.0f, 0.0f));
	coords->add(glm::vec2(0.0f, 1.0f));
	coords->add(glm::vec2(1.0f, 1.0f));
	coords->add(glm::vec2(1.0f, 1.0f));
	coords->add(glm::vec2(1.0f, 0.0f));
	coords->add(glm::vec2(0.0f, 0.0f));

	m_Quad = Vao();
	m_Quad.addVbo(pos);
	m_Quad.addVbo(coords);

	m_tex = Texture("Models/Cat/tex.png");


	m_shader = Shader("Shaders/GUI/FragShader.txt", "Shaders/GUI/VertShader.txt");

}
