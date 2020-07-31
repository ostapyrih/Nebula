//
// Created by ostap on 6/25/2020.
//
#pragma once

#include <gl/glew.h>
#include "Renderable2D.h"
#include "../math/Math.h"
#include <vector>

namespace nebula::graphics
{
	using namespace math;

	class Renderer2D
	{
	protected:
		std::vector<Mat4> m_TransformationStack;
		const Mat4* m_TransformationBack;
	protected:
		Renderer2D() {
			m_TransformationStack.push_back(Mat4::identity());
			m_TransformationBack = &m_TransformationStack.back();
		}
	public:
		void push(const Mat4& matrix, bool override = false) {
			if (override)
				m_TransformationStack.push_back(matrix);
			else
				m_TransformationStack.push_back(m_TransformationStack.back() * matrix);
			m_TransformationBack = &m_TransformationStack.back();

		}

		void pop() {
			if (m_TransformationStack.size() > 1) {
				m_TransformationStack.pop_back();
				m_TransformationBack = &m_TransformationStack.back();
			}

			//TODO: Add to log
		}

		virtual void begin() = 0;
		virtual void submit(const Renderable2D* renderable) = 0;
		virtual void end() = 0;
		virtual void flush() = 0;
	};
}