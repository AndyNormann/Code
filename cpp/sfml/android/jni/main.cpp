#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cstdlib>
#include <cstdio>


int SQUARE_SIZE = 20;
int SCREEN_H;
int SCREEN_W;
int GRID_H;
int GRID_W;
sf::Color BLACK = sf::Color::Black;
sf::Color WHITE = sf::Color::White;

#define GRID(x, y) grid[(x) * GRID_W + (y)]

int amount_of_neighbours(int grid[], int x, int y)
{
    int ret_val = 0;

    if (x > 0) {
        //ret_val += grid[(x-1)*GRID_W+y];
        ret_val += GRID(x-1, y);
    }
    if (x < GRID_W) {
        //ret_val += grid[(x+1)*GRID_W+y];
        ret_val += GRID(x+1, y);
    }
    if (y > 0) {
        //ret_val += grid[x*GRID_W+(y-1)];
        ret_val += GRID(x, y-1);
    }
    if (y < GRID_H) {
        //ret_val += grid[x*GRID_W+(y+1)];
        ret_val += GRID(x, y+1);
    }

    if (x > 0 && y > 0) {
        //ret_val += grid[(x-1)*GRID_W+(y-1)];
        ret_val += GRID(x-1, y-1);
    }
    if (x > 0 && y < GRID_H) {
        //ret_val += grid[(x-1)*GRID_W+(y+1)];
        ret_val += GRID(x-1, y+1);
    }

    if (x < GRID_W && y > 0) {
        //ret_val += grid[(x+1)*GRID_W+(y-1)];
        ret_val += GRID(x+1, y-1);
    }
    if (x < GRID_W && y < GRID_H) {
        //ret_val += grid[(x+1)*GRID_W+(y+1)];
        ret_val += GRID(x+1, y+1);
    }

    return ret_val;
}


int main(int argc, char *argv[])
{
    //-------- Init
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "");
    window.setFramerateLimit(5);

    sf::View view = window.getDefaultView();

    // Common constants
    SCREEN_H = view.getSize().x;
    SCREEN_W = view.getSize().y;

    {
        int w = SCREEN_W%SQUARE_SIZE;
        while (w != 0) {
            SQUARE_SIZE++;
            w = SCREEN_W%SQUARE_SIZE;
        }
    }

    GRID_H = SCREEN_H/SQUARE_SIZE;
    GRID_W = (SCREEN_W)/SQUARE_SIZE;
    sf::Vector2f squareSize = sf::Vector2f(SQUARE_SIZE, SQUARE_SIZE);

    sf::Font font;
    font.loadFromFile("sansation.ttf");

    sf::Text text("", font);
    text.setCharacterSize(50);
    text.setFillColor(BLACK);
    text.setOutlineColor(BLACK);
    text.setPosition(0, SCREEN_W-100);
    
    char buf[128];

    //sprintf(buf, "horizontal boxes: %d vertical boxes: %d", GRID_H, GRID_W);

    // Representation of the grid's current state and the state in the next frame
    int cur_state[GRID_H*GRID_W] = {};
    int next_state[GRID_H*GRID_W] = {};
    bool run = false;


    // Draws a glider for debugging
    cur_state[0*GRID_W+2] = 1;
    cur_state[1*GRID_W+2] = 1;
    cur_state[2*GRID_W+2] = 1;
    cur_state[2*GRID_W+1] = 1;
    cur_state[1*GRID_W+0] = 1;

    // Main loop
    while (window.isOpen())
    {
        //----------- Poll for events
        sf::Event event;
        while (window.pollEvent(event))
            {
                switch (event.type)
                    {
                    case sf::Event::Closed:
                        window.close();
                        break;
                    case sf::Event::Resized:
                        view.setSize(event.size.width, event.size.height);
                        view.setCenter(event.size.width/2, event.size.height/2);
                        window.setView(view);
                        break;
                    case sf::Event::TouchBegan:
                        if (event.touch.finger == 0){}

                        if (event.touch.x < 28 && event.touch.x > 0 && event.touch.y > 1700) {
                            run = !run;
                        }


                        if(event.touch.y < GRID_W){
                            int z, w;
                            z = event.touch.x/SQUARE_SIZE;
                            w = event.touch.y/SQUARE_SIZE;

                            //sprintf(buf, "x: %d  y: %d\nz: %d w: %d", event.touch.x, event.touch.y, z, w);

                            cur_state[z*GRID_W+w] = 1;
                            //sprintf(buf, "n: %d x: %d y: %d", amount_of_neighbours(cur_state, z, w), z, w);
                            // cur_state[z*GRID_W+(w+1)] = 1;
                            // cur_state[z*GRID_W+(w-1)] = 1;

                        }
                        break;
                    case sf::Event::TouchMoved:
                        if(event.touch.y < GRID_W){
                            int z, w;
                            z = event.touch.x/SQUARE_SIZE;
                            w = event.touch.y/SQUARE_SIZE;

                            cur_state[z*GRID_W+w] = 1;
                        }

                        break;
                    }
            }

        //------------ Update

        if (run) {
            for (int i = 0; i < GRID_H; i++) {
                for (int j = 0; j < GRID_W; j++) {
                    int n = amount_of_neighbours(cur_state, i, j);
                    int in = i*GRID_W+j;
                    if (cur_state[in] == 0) {
                        if (n == 3) {
                            next_state[in] = 1;
                        }
                        continue;
                    }
                    if (n == 2 || n == 3) {
                        next_state[in] = 1;
                    }else{
                        next_state[in] = 0;
                    }
                }
            }

            memcpy(cur_state, next_state, sizeof(int)*GRID_H*GRID_W);
            memset(next_state, 0, sizeof(int)*GRID_H*GRID_W);
        }


        //------------ Draw

        window.clear(sf::Color::White);

        sf::RectangleShape square;
        square.setFillColor(BLACK);
        square.setSize(squareSize);

        for (int i = 0; i < GRID_H; i++) {
            for (int j = 0; j < GRID_W; j++) {
                if (cur_state[i*GRID_W+j]) {
                    square.setPosition(i*SQUARE_SIZE, j*SQUARE_SIZE);
                    window.draw(square);
                }              
            }
        }

        text.setString(buf);
        window.draw(text);

        window.display();
    }
}
