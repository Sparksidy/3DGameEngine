#pragma once

#include "Renderable2D.h"
#include "Renderer.h"
#include <vector>

namespace GameEngine { namespace Graphics{

	class Layer {
	protected:
		Renderer2D* m_Renderer;
		std::vector<Renderable2D*> m_Renderables;
		Maths::mat4 m_ProjectionMatrix;
		Shader* m_Shader;

		Layer(Renderer2D* renderer, Shader* shader, Maths::mat4 projectionMatrix);

	public:
		virtual ~Layer();
		virtual void add(Renderable2D* renderable);
		virtual void render();

	};

}}
