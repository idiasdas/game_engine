#pragma once

#include "RenderCommand.h"

namespace dds{

    class Renderer
    {
    public:
        static void BeginScene();
        static void EndScene();

        static void Submit(const std::shared_ptr<VertexArray>& VertexArray);

        inline static RendererAPI::API GetAPI(){return RendererAPI::GetAPI();}
    };
}
