#include "src/graphics/Window.h"
#include "src/graphics/Shader.h"
#include "src/graphics/Sprite.h"
#include "src/graphics/BatchRenderer2D.h"
#include "src/utils/Timer.h"
#include "src/graphics/layers/TileLayer.h"
#include "src/graphics/layers/Group.h"

int main()
{
	using namespace nebula;
	using namespace graphics;
	using namespace utils;
	using namespace math;
	using namespace layers;

	Window* window = new Window("Nebula", 960, 540);

	BatchRenderer2D batch;

	Shader* shader = new Shader("basic.vert", "basic.frag");

	TileLayer* layer = new TileLayer(shader);

	Group* group = new Group(Mat4::translation(Vec3(1, 1, 0)));
	group->add(new Sprite(0, 0, 4, 4, Vec4(1, 1, 1, 1)));
	layer->add(group);

	Timer timer;
	unsigned int fps = 0;

	while (!window->closed())
	{
		window->clear();
		double x, y;
		layer->render();
		window->getCursorPosition(x, y);
		shader->setUniform2f("light_pos", Vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
		window->update();

		fps++;
		if (timer.elapsed() > 1.0f)
		{
			printf("%d FPS\n", fps);
			fps = 0;
			timer.reset();
		}
	}

	return 0;
}