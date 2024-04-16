#include "dds_enginepch.h"
#include "LinuxInput.h"
#include "dds_engine/Application.h"
#include <GLFW/glfw3.h>


namespace dds {
    Input* Input::s_Instance = new LinuxInput();

    bool LinuxInput::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool LinuxInput::IsMouseButtonPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        auto state = glfwGetMouseButton(window, keycode);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> LinuxInput::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);
        return {(float)xpos, (float)ypos};
    }

    float LinuxInput::GetMouseXImpl()
    {
        auto[xpos, ypos] = LinuxInput::GetMousePositionImpl();
        return xpos;
    }

    float LinuxInput::GetMouseYImpl()
    {
        auto[xpos, ypos] = LinuxInput::GetMousePositionImpl();
        return ypos;
    }
}
