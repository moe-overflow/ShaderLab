#include <stdexcept>
#include "Window.hpp"

Window::Window(Window::WindowSettings&& settings) :
        _settings(std::move(settings))
{}

void Window::Init()
{
    InitGLFW();
    InitImGUI();
}

void Window::InitGLFW()
{
    glfwInit(); // todo: exception handling

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    _glfw_window = glfwCreateWindow(_settings.Width, _settings.Height, _settings.Title.c_str(), nullptr, nullptr);

    if (!_glfw_window)
        glfwTerminate();

    glfwMakeContextCurrent(_glfw_window);
    glfwSwapInterval(_settings.Vsync);

    gladLoadGLLoader(reinterpret_cast<GLADloadproc> (glfwGetProcAddress)); // todo: exception handling

}

void Window::InitImGUI()
{
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    auto glsl_version = "#version 330";
    ImGui_ImplGlfw_InitForOpenGL(_glfw_window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    ImGui::StyleColorsDark();
}


void Window::Render()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    ImGui::Begin("123");
    ImGui::Text("QWERTY");
    ImGui::End();

    ImGui::Render();
    int width, height;
    glfwGetFramebufferSize(_glfw_window, &width, &height);
    glViewport(0, 0, width, height);
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(_glfw_window);
}

void Window::HandleEvents()
{
    glfwPollEvents();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(_glfw_window);
}


