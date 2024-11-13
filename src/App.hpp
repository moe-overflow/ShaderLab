#pragma once

#include <memory>

#include "Window.hpp"


class App
{
public:
    App();
    ~App() = default;
    void Run();


private:
    std::unique_ptr<Window> _window;

    bool _is_running;
};

