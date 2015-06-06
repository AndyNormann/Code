#include <SFML/Graphics.hpp>
#include <sstream>

#define WINDOW_HEIGHT 1400
#define WINDOW_WIDTH 1400 

#define SQUARE_SIZE 10

#define GRID_H WINDOW_HEIGHT/SQUARE_SIZE
#define GRID_W WINDOW_WIDTH/SQUARE_SIZE

enum {Up, Down, Left, Right};

void moveAnt(sf::Color color);
void changeRColor(sf::Color color);
void changeLColor(sf::Color color);

int ant_x;
int ant_y;
int direction;

sf::RectangleShape grid[GRID_H][GRID_W];

#define DARK_BLUE sf::Color(0, 128, 0)
#define DARK_RED sf::Color(128, 0, 0)
#define DARK_GREEN sf::Color(0, 0, 128)
#define GRAY sf::Color(84, 84, 84)

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "langton's ant");
    
    ant_x = (GRID_W/2)+30;
    ant_y = (GRID_H/2)+100;
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
        frameCount += 8;
    }
    return 0;
}

void moveAnt(sf::Color color)
{
// R colors: White, Blue, Cyan, DARK_RED, DARK_GREEN, GRAY
    if(color == sf::Color::White || color == sf::Color::Blue || color == sf::Color::Cyan || color == DARK_RED || color == DARK_GREEN || color == GRAY){
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

// L colors: Black, Green, Red, Magenta, Yellow, DARK_BLUE
    if(color == sf::Color::Black || color == sf::Color::Green || color == sf::Color::Red || color == sf::Color::Magenta || color == sf::Color::Yellow || color == DARK_BLUE){
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

// Color pattern RL R == Black L == White 
// New pattern LLRR L == White L == Red R == Black R == Green
// Wanted pattern LRRRRRLLR L == White R == Blue R == Green R == Red R == Cyan R == Magenta L == Black L == Yellow R == DARK_BLUE 
// R colors: Blue, Green, Red, Cyan, Magenta, DARK_BLUE
// L colors: White, Black, Yellow
// RRLLLRLLLRRR R == White R == Blue L == Black L = Green L == Red R == Cyan L == Magenta L == Yellow L == DARK_BLUE R == DARK_RED R == DARK_GREEN R == GRAY 
// R colors: White, Blue, Cyan, DARK_RED, DARK_GREEN, GRAY
// L colors: Black, Green, Red, Magenta, Yellow, DARK_BLUE

void setAntColor(sf::Color color)
{
    grid[ant_x][ant_y].setFillColor(color);
}

void changeLColor(sf::Color color)
{
    using namespace sf;
    if(color ==  Color::Black){
        setAntColor(Color::Magenta);
    }else if(color == Color::Magenta){
        setAntColor(Color::Red);
    }else if(color == Color::Red){
        setAntColor(Color::Cyan);
    }else if(color == Color::Green){
        setAntColor(Color::Yellow);
    }else if(color == Color::Yellow){
        setAntColor(DARK_BLUE);
    }else if(color == DARK_BLUE){
        setAntColor(DARK_RED);
    }
}

// RRLLLRLLLRRR 
// R == White R == Blue 
// L == Black L = Green L == Red 
// R == Cyan 
// L == Magenta L == Yellow L == DARK_BLUE 
// R == DARK_RED R == DARK_GREEN R == GRAY 
void changeRColor(sf::Color color)
{
    using namespace sf;
    if(color ==  Color::White){
        setAntColor(Color::Blue);
    }else if(color == Color::Blue){
        setAntColor(Color::Black);
    }else if(color == Color::Cyan){
        setAntColor(Color::Green);
    }else if(color == DARK_RED){
        setAntColor(DARK_GREEN);
    }else if(color == DARK_GREEN){
        setAntColor(GRAY);
    }else if(color == GRAY){
        setAntColor(Color::White);
    }
}
