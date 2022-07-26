#include "function/render/window_system.h"
#include "core/macro.h"
namespace LittleEngine
{
    WindowSystem::~WindowSystem()
    {
        glfwDestroyWindow(m_window);
        glfwTerminate();
    }
    
    void WindowSystem::initialize(WindowCreateInfo create_info)
    {
        if (!glfwInit())
        {
            //initialization failure
            LOG_FATAL(__FUNCTION__, "failed to initialize GLFW");
            return;
        }
        
        m_width  = create_info.width;
        m_height = create_info.height;

        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        m_window = glfwCreateWindow(create_info.width, create_info.height, create_info.title, nullptr, nullptr);
        if (!m_window)
        {
            LOG_FATAL(__FUNCTION__, "failed to create window");
            glfwTerminate();
            return;
        }

        // Setup input callbacks
        glfwSetWindowUserPointer(m_window, this);
        glfwSetKeyCallback(m_window, keyCallback);
        glfwSetCharCallback(m_window, charCallback);
        glfwSetCharModsCallback(m_window, charModsCallback);
        glfwSetMouseButtonCallback(m_window, mouseButtonCallback);
        glfwSetCursorPosCallback(m_window, cursorPosCallback);
        glfwSetCursorEnterCallback(m_window, cursorEnterCallback);
        glfwSetScrollCallback(m_window, scrollCallback);
        glfwSetDropCallback(m_window, dropCallback);
        glfwSetWindowSizeCallback(m_window, windowSizeCallback);
        glfwSetWindowCloseCallback(m_window, windowCloseCallback);

        glfwSetInputMode(m_window, GLFW_RAW_MOUSE_MOTION, GLFW_FALSE);
    }


    void WindowSystem::setFocusMode(bool mode)
    {
        m_is_focus_mode = mode;
        glfwSetInputMode(m_window, GLFW_CURSOR, m_is_focus_mode ? GLFW_CURSOR_DISABLED : GLFW_CURSOR_NORMAL);
    }

    bool WindowSystem::isMouseButtonDown(int button) const
    {
        if (button < GLFW_MOUSE_BUTTON_1 || button > GLFW_MOUSE_BUTTON_LAST)
        {
            return false;
        }
        return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
    }

    void WindowSystem::onReset()
    {
        for (auto& func : m_onResetFunc)
            func();
    }
    void WindowSystem::onKey(int key, int scancode, int action, int mods)
    {
        for (auto& func : m_onKeyFunc)
            func(key, scancode, action, mods);
    }
    void WindowSystem::onChar(unsigned int codepoint)
    {
        for (auto& func : m_onCharFunc)
            func(codepoint);
    }
    void WindowSystem::onCharMods(int codepoint, unsigned int mods)
    {
        for (auto& func : m_onCharModsFunc)
            func(codepoint, mods);
    }
    void WindowSystem::onMouseButton(int button, int action, int mods)
    {
        for (auto& func : m_onMouseButtonFunc)
            func(button, action, mods);
    }
    void WindowSystem::onCursorPos(double xpos, double ypos)
    {
        for (auto& func : m_onCursorPosFunc)
            func(xpos, ypos);
    }
    void WindowSystem::onCursorEnter(int entered)
    {
        for (auto& func : m_onCursorEnterFunc)
            func(entered);
    }
    void WindowSystem::onScroll(double xoffset, double yoffset)
    {
        for (auto& func : m_onScrollFunc)
            func(xoffset, yoffset);
    }
    void WindowSystem::onDrop(int count, const char** paths)
    {
        for (auto& func : m_onDropFunc)
            func(count, paths);
    }
    void WindowSystem::onWindowSize(int width, int height)
    {
        for (auto& func : m_onWindowSizeFunc)
            func(width, height);
    }

    void WindowSystem::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onKey(key, scancode, action, mods);
    }
    void WindowSystem::charCallback(GLFWwindow* window, unsigned int codepoint)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onChar(codepoint);
    }
    void WindowSystem::charModsCallback(GLFWwindow* window, unsigned int codepoint, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onCharMods(codepoint, mods);
    }
    void WindowSystem::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onMouseButton(button, action, mods);
    }
    void WindowSystem::cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onCursorPos(xpos, ypos);
    }
    void WindowSystem::cursorEnterCallback(GLFWwindow* window, int entered)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onCursorEnter(entered);
    }
    void WindowSystem::scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onScroll(xoffset, yoffset);
    }
    void WindowSystem::dropCallback(GLFWwindow* window, int count, const char** paths)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app) app->onDrop(count, paths);
    }
    void WindowSystem::windowSizeCallback(GLFWwindow* window, int width, int height)
    {
        WindowSystem* app = (WindowSystem*)glfwGetWindowUserPointer(window);
        if (app)
        {
            app->m_width  = width;
            app->m_height = height;
        }
    }

}