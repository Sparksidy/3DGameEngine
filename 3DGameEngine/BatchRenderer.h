#pragma once
#include <glew.h>
#include <cstddef>
#include "VertexArrays.h"
#include "IndexBuffer.h"
#include "Renderer.h"
#include "Renderable2D.h"

namespace GameEngine { namespace Graphics {
#define RENDERER_MAX_SPRITES		60000
#define RENDERER_VERTEX_SIZE		sizeof(VertexData)
#define RENDERER_SPRITE_SIZE		RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE		RENDERER_MAX_SPRITES * RENDERER_SPRITE_SIZE
#define RENDERER_INDICES_SIZE		RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX			0
#define SHADER_COLOR_INDEX			1

	class BatchRenderer : public Renderer2D {
	private:
		GLuint m_VAO;
		GLuint m_VBO;//Everything buffer object
		IndexBuffer* m_IBO;
		GLsizei m_IndexCount;
		VertexData* m_Buffer;
	public:
		BatchRenderer();
		~BatchRenderer();
		void begin()override;
		void submit(const Renderable2D* renderable2D)override;
		void end()override;
		void flush()override;

	private:
		void Init();

	};

}}
