#pragma once
#include "Renderable2D.h"
#include <glew.h>
#include "Math.h"


namespace GameEngine { namespace Graphics {

	class Renderer2D {
	public:
		virtual void begin() {}
		virtual void submit(const Renderable2D* renderable2D) = 0;
		virtual void end() {}
		virtual void flush() = 0;
	};

}}
