#include "TileLayer.h"

namespace nebula::graphics::layers {

	TileLayer::TileLayer(Shader* shader)
		: Layer(new BatchRenderer2D(), shader, Mat4::orthographic(0, 16.0f, 0, 9.0f, -1.0f, 1.0f))
	{

	}

	TileLayer::~TileLayer() {

	}

}