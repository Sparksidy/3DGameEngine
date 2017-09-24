#include "Simple2DRenderer.h"

namespace GameEngine { namespace Graphics {

	void Simple2DRenderer::submit(const Renderable2D* renderable2D)
	{
		m_RenderQueue.push_back((StaticSprite *)renderable2D);
	}

	void Simple2DRenderer::flush()
	{
		while (!m_RenderQueue.empty())
		{
			const StaticSprite* sprite = m_RenderQueue.front();

			sprite->getVAO()->bind();
			sprite->getIBO()->bind();

			sprite->getShader().setUniformMat4("m_matrix", Maths::mat4::translation(sprite->getPosition()));
			glDrawElements(GL_TRIANGLES, sprite->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);

			sprite->getIBO()->unbind();
			sprite->getVAO()->unbind();

			m_RenderQueue.pop_front();
		}

	}


}}