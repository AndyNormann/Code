
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>

#include <iostream>

const GLint WINDOW_WIDTH = 800;
const GLint WINDOW_HEIGHT = 600;

int main()
{
    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;
    settings.attributeFlags = sf::ContextSettings::Core;

    sf::Window window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "OpenGl", sf::Style::Titlebar | sf::Style::Close, settings);

    sf::ContextSettings real_settings = window.getSettings();

    std::cout << real_settings.majorVersion << "\n";
    std::cout << real_settings.minorVersion << "\n";


    float vertices[] = {
        0.0, 0.5, 0.0,
        -0.5,-0.5, 0.0,
        0.5, -0.5, 0.0
    };

    bool running = true;
    while(running){

        sf::Event event;
        while(window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                running = false;
            }else if (event.type == sf::Event::Resized) {
                glViewport(0, 0, event.size.width, event.size.height);
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDisableClientState(GL_VERTEX_ARRAY);

        window.display();

    }

    return 0;
}

