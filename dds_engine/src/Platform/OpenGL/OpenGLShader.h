#pragma once

#include "dds_engine/Renderer/Shader.h"
namespace dds
{

    class OpenGLShader : public Shader
    {
    public:
        OpenGLShader(const std::string &vertexSrc, const std::string &fragmentSrc);
        ~OpenGLShader();

        void Bind() const override;
        void Unbind() const override;

        void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const override;
    private:
        uint32_t m_RendererID;
    };
}
