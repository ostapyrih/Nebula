//
// Created by ostap on 6/23/2020.
//

#include "VertexArray.h"

namespace nebula::graphics::buffers
{

	VertexArray::VertexArray()
	{
		glGenVertexArrays(1, &m_ArrayID);
	}

	VertexArray::~VertexArray()
	{
		for (int i = 0; i < m_VertexBuffers.size(); i++)
		{
			delete m_VertexBuffers[i];
		}
		glDeleteVertexArrays(1, &m_ArrayID);
	}

	void VertexArray::addBuffer(VertexBuffer* buffer, GLuint index)
	{
		bind();
		buffer->bind();

		glEnableVertexAttribArray(index);
		glVertexAttribPointer(index, buffer->getComponentCount(), GL_FLOAT, GL_FALSE, 0, nullptr);

		buffer->unbind();
		unbind();
	}

	void VertexArray::bind() const
	{
		glBindVertexArray(m_ArrayID);
	}

	void VertexArray::unbind() const
	{
		glBindVertexArray(0);
	}
}