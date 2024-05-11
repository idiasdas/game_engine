#include "dds_enginepch.h"
#include "Buffer.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace dds{

    VertexBuffer* VertexBuffer::Create(float* vertices , uint32_t size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::OpenGL:
                return new OpenGLVertexBuffer(vertices, size);
            default:
                DDS_CORE_ASSERT(false, "Renderer API not supported.");
                return nullptr;
        }

        DDS_CORE_ASSERT(false, "Invalid Renderer API.");
        return nullptr;
    }

    IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::OpenGL:
                return new OpenGLIndexBuffer(indices, size);
            default:
                DDS_CORE_ASSERT(false, "Renderer API not supported.");
                return nullptr;
        }

        DDS_CORE_ASSERT(false, "Invalid Renderer API.");
        return nullptr;
    }
}
