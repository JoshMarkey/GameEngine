#pragma once
#include "Component.h"
#include <Graphics/rend.h>

namespace myengine
{
	struct Entity;
	struct TriangleRenderer : Component
	{
		TriangleRenderer();
		~TriangleRenderer();
	public:
		void onDisplay() override;
		void initialize();
		void onTick() override;
		float m_angle;
	private:
		graphics::Vao m_Quad;
		graphics::Model m_mesh;
		graphics::Shader m_shader;
		graphics::Camera m_cam;
		graphics::Texture m_tex;
	};
}