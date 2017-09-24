#pragma once
#include "Layer.h"
#include "BatchRenderer.h"
#include "Math.h"

namespace GameEngine {namespace Graphics {

	class TileLayer: public Layer
	{
	public:
		TileLayer(Shader* shader);
		~TileLayer();
		
	};

}}
