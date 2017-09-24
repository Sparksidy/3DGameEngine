#pragma once
#include "Renderer.h"
#include "StaticSprite.h"
#include <glew.h>
#include <deque>
#include "Math.h"


namespace GameEngine {
	namespace Graphics {

		class Simple2DRenderer: public Renderer2D {
		private:
			std::deque<const StaticSprite* > m_RenderQueue;
		
		public:
			 void submit(const Renderable2D* renderable2D)override;
			 void flush()override;
		};

	}
}
#pragma once
