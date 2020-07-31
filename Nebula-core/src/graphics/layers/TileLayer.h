#pragma once

#include "Layer.h"
#include "../BatchRenderer2D.h"

namespace nebula::graphics::layers {

	class TileLayer : public Layer {
	public:
		TileLayer(Shader* shader);
		~TileLayer();
	};

}