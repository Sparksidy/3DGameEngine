#pragma once
/*
	VERTEX BUFFER
*/

#include <glew.h>

namespace GameEngine { namespace Graphics {

	class Buffer {
	private:
		GLuint m_BufferID;
		GLuint m_ComponentCount;

	public:
		Buffer(GLfloat* data, GLsizei count, GLuint componentCount);
		~Buffer();

		void bind()const;
		void unbind()const;

		inline GLuint getComponentCount(){ return m_ComponentCount;};

	};

}}
