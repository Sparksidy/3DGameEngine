#pragma once
#include "Renderable2D.h"

namespace GameEngine {namespace Graphics {

	class Sprite :public Renderable2D
	{
	private:

	public:
		Sprite(float x, float y, float width, float height, const Maths::vec4& color);

	};

}}
