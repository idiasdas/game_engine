#include "dds_enginepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

dds::OpenGLContext::OpenGLContext(GLFWwindow *windowHandle)
    : m_WindowHandle(windowHandle)
{
    DDS_CORE_ASSERT(windowHandle, "Window handle is null!");
}

void dds::OpenGLContext::Init()
{
    glfwMakeContextCurrent(m_WindowHandle);
    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    DDS_CORE_ASSERT(status, "Failed to initialize Glad!");

    DDS_CORE_INFO("OpenGL Info:");
    DDS_CORE_INFO(" - Vendor:    {0}", (const char *) glGetString(GL_VENDOR));
    DDS_CORE_INFO(" - Renderer:  {0}", (const char *) glGetString(GL_RENDERER));
    DDS_CORE_INFO(" - Version:   {0}", (const char *) glGetString(GL_VERSION));
}

void dds::OpenGLContext::SwapBuffers()
{
    glfwSwapBuffers(m_WindowHandle);
}
