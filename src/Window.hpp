#pragma once

#include <string>
#include <memory>

#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "imgui.h"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"

class Window
{
public:

    struct WindowSettings
    {
        int Width, Height;
        std::string Title;
        bool Vsync;
    };

    explicit Window(Window::WindowSettings&& settings);

    void Init();

    void Render();

    void HandleEvents();

    bool ShouldClose();

private:
    WindowSettings _settings;

    GLFWwindow* _glfw_window;

    void InitImGUI();

    void InitGLFW();
};