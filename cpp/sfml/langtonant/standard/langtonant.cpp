#include <SFML/Graphics.hpp>
#include <sstream>

#define WINDOW_HEIGHT 1400
#define WINDOW_WIDTH 1400 

#define SQUARE_SIZE 10

#define GRID_H WINDOW_HEIGHT/SQUARE_SIZE
#define GRID_W WINDOW_WIDTH/SQUARE_SIZE

enum {Up, Down, Left, Right};

void moveAnt(sf::Color color);
void setAntColor(sf::Color color);

int ant_x;
int ant_y;
int direction;

sf::RectangleShape grid[GRID_H][GRID_W];

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "langton's ant");
    
    ant_x = GRID_W/2;
    ant_y = GRID_H/2;
    direction = Up;

    //Frame counter
    int frameCount = 0;

    sf::Font font;
    font.loadFromFile("Ubuntu Mono derivative Powerline.ttf");

    //Sizeof squares
    sf::Vector2f squareSize(SQUARE_SIZE, SQUARE_SIZE);
    int i, j;
    for (i = 0; i < GRID_H; i++) {
        for (j = 0; j < GRID_W; j++) {
            grid[i][j] = sf::RectangleShape(squareSize);
            grid[i][j].setPosition(i*SQUARE_SIZE, j*SQUARE_SIZE);
        }
    }

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);

        for (i = 0; i < GRID_H; i++) {
            for (j = 0; j < GRID_W; j++) {
                window.draw(grid[i][j]);
            }
        }

        moveAnt(grid[ant_x][ant_y].getFillColor());
        moveAnt(grid[ant_x][ant_y].getFillColor());
        moveAnt(grid[ant_x][ant_y].getFillColor());
        moveAnt(grid[ant_x][ant_y].getFillColor());

        //Display frame count
        std::stringstream fCount;
        fCount << frameCount;
        sf::Text text(fCount.str(), font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::Black);
        window.draw(text);

        // end the current frame
        window.display();
        frameCount += 4;
    }
    return 0;
}

void moveAnt(sf::Color color)
{
    if(color == sf::Color::White){
        setAntColor(sf::Color::Black);
        switch(direction){
            case Up:
                ant_x++;
                direction = Left;
                break;
            case Down:
                ant_x--;
                direction = Right;
                break;
            case Left:
                ant_y++;
                direction = Down;
                break;
            case Right:
                ant_y--;
                direction = Up;
                break;
        }
    }

    if(color == sf::Color::Black){
        setAntColor(sf::Color::White);
        switch(direction){
            case Up:
                ant_x--;
                direction = Right;
                break;
            case Down:
                ant_x++;
                direction = Left;
                break;
            case Left:
                ant_y--;
                direction = Up;
                break;
            case Right:
                ant_y++;
                direction = Down;
                break;
        }
    }
}

void setAntColor(sf::Color color)
{
    grid[ant_x][ant_y].setFillColor(color);
}
