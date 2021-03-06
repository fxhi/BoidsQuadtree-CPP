#include "Background.hpp"

#include <glad/glad.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "../OpenGL-Core/LayerGL.hpp"

// Public
// ------

BackgroundLayer::BackgroundLayer() {
    // Nothing
}

BackgroundLayer::BackgroundLayer(float r, float g, float b, float alpha)
     : m_color(glm::vec4(r,g,b,alpha)) {
    // assert( 0 <= color.r && color.r <= 1 &&
    //         0 <= color.g && color.g <= 1 &&
    //         0 <= color.b && color.b <= 1 &&
    //         0 <= color.a && color.a <= 1 && 
    //         "ERROR::COLOR:: r,g,b,a need to be betwenn 0 and 1." );
}

void BackgroundLayer::render() {
    // Clear the screen
    glClearColor(m_color.r, m_color.g, m_color.b, m_color.a); //Set the screen color
    glClear(GL_COLOR_BUFFER_BIT); //Clear the color buffer
}

void BackgroundLayer::setColor(float r, float g, float b, float alpha) {
    m_color = glm::vec4(r,g,b,alpha);
}

void BackgroundLayer::setColor(glm::vec3 color) {
    m_color = glm::vec4(color, 1.0f);
}

void BackgroundLayer::setColor(glm::vec4 color) {
    m_color = color;
}

void BackgroundLayer::setColorRGB255(int r, int g, int b) {
    m_color = glm::vec4(static_cast<float>(r/255.0f), static_cast<float>(g/255.0f), static_cast<float>(b/255.0f), 1.0f);
}

void BackgroundLayer::setTransparency(float alpha) {
    m_color = glm::vec4(m_color.r, m_color.g, m_color.b, alpha);
}