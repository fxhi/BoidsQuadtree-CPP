#include "ApplicationGL.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "WindowGL.hpp"
#include "SceneGL.hpp"
#include "Time.hpp"
#include "ImGuiGL/ImGuiGLPath.hpp"

#include <vector>

// Public
// ------
    
ApplicationGL::ApplicationGL() {
    init(); // Can't do this in "run" function, otherwise get a segmentation fault.
}

ApplicationGL::ApplicationGL(int width, int height, std::string name) : m_window(new WindowGL(width, height, name)) {
    assert(width > 0 && height > 0 && "ERROR::WINDOW:: width and height of the window need to be > 0.");
    ApplicationGL();
};

void ApplicationGL::run() {
    update();
    terminate();
}

void ApplicationGL::update() {
    while (!glfwWindowShouldClose(static_cast<GLFWwindow*>(m_window->get())))
    {
        m_window->processInput();

        m_scene->update(time);
        m_Imgui->update();

        m_window->update();

        time.updateTime();
        time.displayFPS();
    }
}

WindowGL* ApplicationGL::getWindow() {
    return m_window;
}

void ApplicationGL::setScene(SceneGL* scene) {
    m_scene = scene;
}

// Private
// -------

void ApplicationGL::init() {
    m_window = new WindowGL();
    m_window->init();

    m_Imgui = new ImGuiGL();
    m_Imgui->setWindow(m_window);
    m_Imgui->init();
}

void ApplicationGL::terminate() {
    glfwTerminate();
}