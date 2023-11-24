#pragma once
#include "Shader.h"
#include "bugl.h"
namespace graphics {
	struct Model
	{
	public:
		Model(std::string _name);
		Model();
		~Model();
		GLuint getId();
		size_t getVerts();
		std::vector<bu::Face> getFaces();
		glm::mat4 getModelMat() { return m_modelMatrix; }
		void updateMatrix(glm::vec3 _position, glm::vec3 _scale, glm::vec3 _rotation, glm::mat4 _view, glm::mat4 _projection);

	private:
		std::string m_name;
		GLuint m_model;
		size_t m_verts;
		std::vector<bu::Face> m_faces;
		glm::mat4 m_modelMatrix;
		glm::mat4 m_viewingMatrix;
		glm::mat4 m_projectionMatrix;
		glm::vec3 m_scale;
	};
}

