#pragma once

#include "dds_engine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace dds{
    class OpenGLContext : public GraphicsContext
    {
    public:
        OpenGLContext(GLFWwindow* windowHandle);

        virtual void Init() override;
        virtual void SwapBuffers() override;
    private:
        GLFWwindow* m_WindowHandle;
    };
}
