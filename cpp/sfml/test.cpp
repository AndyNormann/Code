#include <SFML/Graphics.hpp>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800


int main()
{
    float x = 0;
    float y = 0;

    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(sf::Color::Black);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            x--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            x++;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            y--;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            y++;

        if(x < 0){
            x = WINDOW_WIDTH;
        }else if(x > WINDOW_WIDTH){
            x = 0;
        }

        if(y < 0){
            y = WINDOW_HEIGHT;
        }else if(y > WINDOW_HEIGHT){
            y = 0;
        }

        sf::Vector2i localPosition = sf::Mouse::getPosition(window);
        sf::Vector2f floatPos(localPosition.x-25, localPosition.y-25);

        // draw everything here...
        sf::CircleShape shape(50);
        shape.setFillColor(sf::Color(150, 50, 250));
        //shape.setPosition(floatPos);
        shape.setPosition(x, y);

        window.draw(shape);

        // end the current frame
        window.display();
    }
    return 0;
}
