#include "dds_enginepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace dds {

    VertexArray* VertexArray::Create()
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::OpenGL:
                return new OpenGLVertexArray();
            default:
                DDS_CORE_ASSERT(false, "Renderer API not supported.");
                return nullptr;
        }

        DDS_CORE_ASSERT(false, "Invalid Renderer API.");
        return nullptr;
    }

}
