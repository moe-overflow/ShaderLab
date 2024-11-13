include(${CMAKE_SOURCE_DIR}/cmake/CPM.cmake)

function(fetch_glfw)
    CPMAddPackage(
            NAME GLFW
            GITHUB_REPOSITORY glfw/glfw
            GIT_TAG 3.3.9
            OPTIONS
                "GLFW_BUILD_TESTS OFF"
                "GLFW_BUILD_EXAMPLES OFF"
                "GLFW_BULID_DOCS OFF"
    )
endfunction()

function(create_imgui_library)

    # todo: assert glfw is available

    set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/vendor/imgui CACHE PATH "Path to the ImGui source directory")

    add_library(
            imgui
            ${IMGUI_DIR}/imgui.cpp
            ${IMGUI_DIR}/imgui_demo.cpp
            ${IMGUI_DIR}/imgui_draw.cpp
            ${IMGUI_DIR}/imgui_tables.cpp
            ${IMGUI_DIR}/imgui_widgets.cpp
            ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
            ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    )

    target_link_libraries(imgui PRIVATE glfw)

    target_include_directories(imgui
            PUBLIC
            ${IMGUI_DIR}
            ${IMGUI_DIR}/backends
    )


endfunction()

function(fetch_sfml)
    CPMAddPackage("gh:SFML/SFML#2.6.2")
endfunction()

function(fetch_imgui_sfml)
    CPMAddPackage(
            NAME imgui-sfml
            GITHUB_REPOSITORY SFML/imgui-sfml
            GIT_TAG v2.6
    )
endfunction()

function(create_glad_library)

    set(GLAD_ROOT ${CMAKE_SOURCE_DIR}/vendor/glad)

    add_library(
            glad
            STATIC
            ${GLAD_ROOT}/include/glad/glad.h
            ${GLAD_ROOT}/include/KHR/khrplatform.h
            ${GLAD_ROOT}/src/glad.c

    )

    target_include_directories(glad PUBLIC ${GLAD_ROOT}/include)


endfunction()