#pragma once

#include <string>
#include <glm/glm.hpp>

namespace dds
{

    class Shader
    {
    public:
        static Shader *Create(const std::string &vertexSrc, const std::string &fragmentSrc);

        virtual ~Shader() {}

        virtual void Bind() const = 0;
        virtual void Unbind() const = 0;

        virtual void UploadUniformMat4(const std::string& name, const glm::mat4& matrix) const = 0;
    };
}
