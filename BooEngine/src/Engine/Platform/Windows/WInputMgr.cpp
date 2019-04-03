#include "booPCH.h"
#include "WInputMgr.h"
#include "Engine/Engine.h"
#include <GLFW/glfw3.h>

namespace boo
{
    InputMgr* InputMgr::s_Instance = new WInputMgr();

    bool WInputMgr::IsKeyPressedImpl(int keycode)
    {
        auto window = static_cast<GLFWwindow*>(Engine::GetInstance().GetWindow().GetNativeWindow());

        auto state = glfwGetKey(window, keycode);

        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool WInputMgr::IsMouseButtonPressedImpl(int button)
    {
        auto window = static_cast<GLFWwindow*>(Engine::GetInstance().GetWindow().GetNativeWindow());

        auto state = glfwGetMouseButton(window, button);

        return state == GLFW_PRESS;
    }

    std::pair<float, float> WInputMgr::GetMousePositionImpl()
    {
        auto window = static_cast<GLFWwindow*>(Engine::GetInstance().GetWindow().GetNativeWindow());

        double xpos, ypos;

        glfwGetCursorPos(window, &xpos, &ypos);

        return { (float)xpos, (float)ypos };

    }

    float WInputMgr::GetMouseXImpl()
    {
        auto[x, y] = GetMousePositionImpl();

        return x;
    }

    float WInputMgr::GetMouseYImpl()
    {
        auto[x, y] = GetMousePositionImpl();

        return y;
    }
}