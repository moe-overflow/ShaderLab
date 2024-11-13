cmake_minimum_required(VERSION 3.12)

project(ShaderDebugger)

include(${CMAKE_SOURCE_DIR}/deps.cmake)

fetch_glfw()
create_imgui_library()
create_glad_library()

add_executable(
        ShaderDebugger

        src/main.cpp
        src/Window.cpp
        src/Window.hpp
        src/App.cpp
        src/App.hpp

)

target_link_libraries(
        ShaderDebugger
        PUBLIC imgui
        PUBLIC glfw
        PUBLIC glad
)


