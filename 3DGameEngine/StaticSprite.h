#pragma once
#include "VertexArrays.h"
#include "IndexBuffer.h"
#include "Shader.h"
#include "Math.h"
#include "Renderable2D.h"

namespace GameEngine { namespace Graphics {

	class StaticSprite : public Renderable2D {
	private:
		VertexArray* m_vertexArray;
		IndexBuffer* m_IndexBuffer;
		Shader& m_Shader;

	public:
		StaticSprite(float x, float y, float width, float height, const Maths::vec4& color, Shader& shader);
		~StaticSprite();

		inline const VertexArray* getVAO() const { return m_vertexArray; }
		inline const IndexBuffer* getIBO() const { return m_IndexBuffer; }

		inline  Shader& getShader() const { return m_Shader; }

	};

}}

