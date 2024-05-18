#pragma once

#include <memory>
#include "Buffer.h"

namespace dds{

    class VertexArray
    {
    public:
        virtual ~VertexArray() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer>& vertexBuffer) const = 0;
        virtual void AddIndexBuffer(const std::shared_ptr<IndexBuffer>& indexBuffer) const = 0;

        static VertexArray *Create();
    };

}
