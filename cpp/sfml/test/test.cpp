#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "Cube.h"

struct Treasure{
    sf::Vector2f size;
    sf::Vector2f position;
    sf::RectangleShape rect;
    int dir;
    int dir_count;

    Treasure(){
        size = sf::Vector2f(10, 10);
        position = sf::Vector2f(rand() % WINDOW_WIDTH, rand() % WINDOW_HEIGHT);
        rect = sf::RectangleShape(size);
        rect.setPosition(position);
        rect.setFillColor(sf::Color(255, 0, 0));
        dir = 0;
        dir_count = 0;
    }

    void north(){
        if (position.y > 0) {
            position.y--;
        }
    }
    void south(){
        if (position.y < WINDOW_HEIGHT) {
            position.y++;
        }
    }
    void east(){
        if (position.x < WINDOW_WIDTH) {
            position.x++;
        }
    }
    void west(){
        if (position.x > 0) {
            position.x--;
        }
    }

    void move(){
        //int move_amt = rand() % 2;
        if (dir_count == 200) {
            dir++;
            dir_count = 0;
        }
        if (dir%2) {
            north();
        }else{
            south();
        }
        rect.setPosition(position);
        dir_count++;
    }

};

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "My window");

    Cube cube;
    int points = 0;

    sf::RectangleShape rect(sf::Vector2f(10, 10));

    sf::Font font;
    font.loadFromFile("Ubuntu Mono derivative Powerline.ttf");

    time_t t;
    srand(time(&t));

    sf::Vector2f treasure_position(rand() % WINDOW_WIDTH, 
                                   rand() % WINDOW_HEIGHT);

    sf::RectangleShape treasure(sf::Vector2f(20, 20));

    treasure.setFillColor(sf::Color(255, 0, 0));
    treasure.setPosition(treasure_position);

    Treasure tr = Treasure();

    Treasure treasures[10];
    for (int i = 0;i < 10; ++i) {
        treasures[i] = Treasure();
    }

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            cube.west();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            cube.east();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            cube.north();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            cube.south();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            return 1;
        }

        cube.update();

        window.draw(treasure);
        window.draw(cube.rect);
        for (int i = 0;i < 10; ++i) {
            treasures[i].move();
            window.draw(treasures[i].rect);
        }

        if (cube.collision(treasure_position)) {
            treasure_position.x = rand() % WINDOW_WIDTH;
            treasure_position.y = rand() % WINDOW_HEIGHT;
            treasure.setPosition(treasure_position);
            treasure.setFillColor(sf::Color(255, 255, 255));
            cube.inc();

            points++;
        }else{
            treasure.setFillColor(sf::Color(255, 0, 0));
        }

        std::stringstream fPoints;
        fPoints << points;
        sf::Text text(fPoints.str(), font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::White);
        window.draw(text);

        // end the current frame
        window.display();
    }
    return 0;
}
