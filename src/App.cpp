#include "App.hpp"

#include "Window.hpp"

App::App()
{
    Window::WindowSettings x = { 800, 600, "XYZ"};
    _window = std::make_unique<Window>(std::move(x));
    _window->Init();
}

void App::Run()
{
    while (! _window->ShouldClose())
    {
        _window->HandleEvents();
        _window->Render();
    }
}
