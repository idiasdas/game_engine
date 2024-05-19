#include "dds_enginepch.h"
#include "Shader.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace dds{

    Shader* Shader::Create(const std::string& vertexSrc, const std::string& fragmentSrc)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::API::OpenGL:
                return new OpenGLShader(vertexSrc, fragmentSrc);
            default:
                DDS_CORE_ASSERT(false, "Renderer API not supported.");
                return nullptr;
        }

        DDS_CORE_ASSERT(false, "Invalid Renderer API.");
        return nullptr;
    }
}
