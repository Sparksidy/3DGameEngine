#pragma once
#include <glew.h>
#include "Math.h"
#include "Buffer.h"
#include "IndexBuffer.h"
#include "VertexArrays.h"
#include "Shader.h"

namespace GameEngine { namespace Graphics {

	struct VertexData {
		Maths::vec3 vertex;
		unsigned int color;
		//Maths::vec4 color;
		
	};

	class Renderable2D {

	protected:
		Maths::vec2 m_Size;
		Maths::vec3 m_Position;
		Maths::vec4 m_Color;

	public:

		Renderable2D(Maths::vec3 position, Maths::vec2 size, Maths::vec4 color)
			:m_Position(position), m_Size(size), m_Color(color)
		{}
		virtual ~Renderable2D() {}

		inline const Maths::vec2& getSize()const { return m_Size; }
		inline const Maths::vec3& getPosition() const{ return m_Position; }
		inline const Maths::vec4& getColor() const { return m_Color;}

	};

}}
