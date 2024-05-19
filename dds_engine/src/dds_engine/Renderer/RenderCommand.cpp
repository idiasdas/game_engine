#include "dds_enginepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace dds {

    RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI();

}
