//
// Created by ostap on 6/26/2020.
//
#pragma once

#include "Renderer2D.h"
#include "Renderable2D.h"

namespace nebula::graphics
{
#define RENDERER_MAX_SPRITES    10000
#define RENDERER_VERTEX_SIZE    sizeof(VertexData)
#define RENDERER_SPRITE_SIZE    RENDERER_VERTEX_SIZE * 4
#define RENDERER_BUFFER_SIZE    RENDERER_SPRITE_SIZE * RENDERER_MAX_SPRITES
#define RENDERER_INDICIES_SIZE  RENDERER_MAX_SPRITES * 6

#define SHADER_VERTEX_INDEX 0
#define SHADER_COLOR_INDEX  1

	class BatchRenderer2D : public Renderer2D
	{
	private:
		GLuint m_VAO;
		GLuint m_VBO;
		IndexBuffer* m_IBO;
		GLsizei m_IndexCounter;
		VertexData* m_Buffer;

	public:
		BatchRenderer2D();
		~BatchRenderer2D();
		void begin() override;
		void submit(const Renderable2D* renderable) override;
		void end() override;
		void flush() override;
	private:
		void init();
	};

}