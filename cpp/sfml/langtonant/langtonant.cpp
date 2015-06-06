#include <SFML/Graphics.hpp>
#include <sstream>

#define WINDOW_HEIGHT 1400
#define WINDOW_WIDTH 1400 

#define SQUARE_SIZE 5

#define GRID_H WINDOW_HEIGHT/SQUARE_SIZE
#define GRID_W WINDOW_WIDTH/SQUARE_SIZE

#define ITERATIONS 10000

enum {Up, Down, Left, Right};

void moveAnt(sf::Color color);
void changeRColor(sf::Color color);
void changeLColor(sf::Color color);

int ant_x;
int ant_y;
int direction;

sf::RectangleShape grid[GRID_H][GRID_W];

#define GRAY sf::Color(24, 24, 24)

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
            grid[i][j].setFillColor(GRAY);

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

        window.clear(sf::Color::White);

        for (i = 0; i < GRID_H; i++) {
            for (j = 0; j < GRID_W; j++) {
                window.draw(grid[i][j]);
            }
        }

        for (i = 0; i < ITERATIONS; i++) {
            moveAnt(grid[ant_x][ant_y].getFillColor());
        }

        //Display frame count
        std::stringstream fCount;
        fCount << frameCount;
        sf::Text text(fCount.str(), font);
        text.setCharacterSize(30);
        text.setColor(sf::Color::White);
        window.draw(text);

        // end the current frame
        window.display();
        frameCount += ITERATIONS;
    }
    return 0;
}

void moveAnt(sf::Color color)
{
    if(color == sf::Color::White || color == sf::Color::Green){
        changeRColor(color);
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

    if(color == GRAY || color == sf::Color::Red){
        changeLColor(color);
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

// Color pattern RL R == White L == White 
// New pattern LLRR L == White L == Red R == White R == Green

void setAntColor(sf::Color color)
{
    grid[ant_x][ant_y].setFillColor(color);
}

void changeLColor(sf::Color color)
{
    using namespace sf;
    if(color == GRAY){
        setAntColor(Color::Red);
    }else if(color == Color::Red){
        setAntColor(Color::White);
    }
}

void changeRColor(sf::Color color)
{
    using namespace sf;
    if(color ==  Color::White){
        setAntColor(Color::Green);
    }else if(color == Color::Green){
        setAntColor(GRAY);
    }
}
