//
// Created by ostap on 6/25/2020.
//
#pragma once

#include <gl/glew.h>
#include "Renderable2D.h"

namespace nebula::graphics
{
    class Renderer2D
    {
    public:
        virtual void submit(const Renderable2D* renderable) = 0;
        virtual void flush() = 0;
    };
}