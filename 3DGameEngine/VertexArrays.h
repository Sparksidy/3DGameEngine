#pragma once

#include <vector>
#include <glew.h>
#include "Buffer.h"

namespace GameEngine { namespace Graphics {

	class VertexArray {
	private:
		GLuint m_ArrayID;
		std::vector<Buffer*> m_Buffer;
	public:
		VertexArray();
		~VertexArray();

		void addBuffer(Buffer* buffer, GLuint index);

		void bind()const;
		void unbind()const;

	};

}}


