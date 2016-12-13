#ifndef CUBE
#define CUBE 

#define WINDOW_HEIGHT 1200
#define WINDOW_WIDTH 1200

struct Cube {

    sf::RectangleShape rect;

    float x, y;
    sf::Vector2f size;

    Cube(){
        x = 0;
        y = 0;
        size = sf::Vector2f(15, 15);
        rect = sf::RectangleShape(size);
        rect.setFillColor(sf::Color(150, 50, 250));
    }

    void update(){
        rect.setPosition(x, y);
        rect.setSize(size);
    }

    bool collision(sf::Vector2f position){
        if (((position.x >= x && position.x <= x+size.x) || (position.x+20 >= x && position.x+20 <= x+size.x)) && 
            ((position.y >= y && position.y <= y+size.y) || (position.y+20 >= y && position.y+20 <= y+size.y))){
            return true;
        }
        return false;
    }

    void setPos(float x_cor, float y_cor){
        x = x_cor;
        y = y_cor;
        rect.setPosition(x, y);
    }

    void inc(){
        size.x += 5;
        size.y += 5;
    }

    void dec(){
        size.x -= 5;
        size.y -= 5;
    }

    void north(){
        if (y != 0) {
            y-=1;
        }
    }
    void south(){
        if (y != WINDOW_HEIGHT-1) {
            y+=1;
        }
    }
    void west(){
        if (x != 0) {
            x-=1;
        }
    }
    void east(){
        if (x != WINDOW_WIDTH-1) {
            x+=1;
        }
    }
};

#endif
