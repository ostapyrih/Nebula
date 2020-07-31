//
// Created by ostap on 6/25/2020.
//
#pragma once

#include <deque>
#include "Renderer2D.h"
#include "StaticSprite.h"

namespace nebula::graphics
{
	class SimpleRenderer2D : public Renderer2D
	{
	private:
		std::deque<const StaticSprite*> m_RenderQueue;

	public:
		void submit(const Renderable2D* renderable) override;
		void flush() override;
	};
}