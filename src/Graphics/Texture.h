#pragma once
#include <GL/glew.h>
#include<stdexcept>
#include <glm/glm.hpp>
namespace graphics {
	struct Texture
	{
		Texture();
		Texture(const char* _name);
		Texture(GLuint _id);
		~Texture();
		unsigned char* m_data;

		int m_width;
		int m_height;

		GLuint m_textureId;

		void uploadToGPU();
		void load(const char* _name);
		GLuint getID();
	};
}