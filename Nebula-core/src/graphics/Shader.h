//
// Created by ostap on 6/23/2020.
//
#pragma once

#include "../utils/Fileutils.h"
#include "../math/Math.h"
#include <vector>
#include <iostream>
#include <GL/glew.h>

namespace nebula::graphics
{

	class Shader
	{
	private:
		GLuint m_ShaderID;
		const char* m_VertPath, * m_FragPath;

	public:
		Shader(const char* vertPath, const char* fragPath);

		~Shader();

		GLint getUniformLocation(const GLchar* name) const;

		void setUniform1f(const GLchar* name, float value) const;
		void setUniform1i(const GLchar* name, int value) const;
		void setUniform2f(const GLchar* name, const math::Vec2& vector) const;
		void setUniform3f(const GLchar* name, const math::Vec3& vector) const;
		void setUniform4f(const GLchar* name, const math::Vec4& vector) const;
		void setUniformMat4(const GLchar* name, const math::Mat4& matrix) const;

		void enable() const;

		void disable() const;

	private:
		GLuint load();

	};

}