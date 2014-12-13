#include <ncurses.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAP_SIZE 30
#define MAP_OFFSET MAP_SIZE-1
#define RAND_OFFSET MAP_SIZE-2
#define RAND_ELEMS 50
#define BACKGROUND 32

//Player variables
#define PLAYER_X 3
#define PLAYER_Y 5
#define PLAYER_ENERGY 200

class Hero{
    public:
        int x;
        int y;
        int score;
        int movement;
        Hero(int xPos, int yPos, int moves){
            x = xPos;
            y = yPos;
            score = 0;
            movement = moves;
        }
};


//Detects keyboard input, used in input loop
int kbhit(){
    int ch = getch();
    if(ch != ERR){
        ungetch(ch);
        return 1;
    }else{
        return 0;
    }
}

void update(char map[MAP_SIZE][MAP_SIZE], Hero *h){
    erase();
    //prints the map
    int i, j;
    for (i = 0; i < MAP_SIZE; i++) {
        for (j = 0; j < MAP_SIZE; j++) {
            printw("%c", map[i][j]);
        }
        printw("\n");
    }
    move(h->x, h->y);
    printw("@");

    //prints the score, and ends the game if the player is out of moves
    if(h->movement != 0){
        move(MAP_SIZE+1, 0);
        printw("Score: %d", h->score);
        move(MAP_SIZE+2, 0);
        printw("Movement: %d", h->movement);
        refresh();
    }else{
        move(MAP_SIZE+1, 0);
        printw("Final score: %d", h->score);
        getch();
        sleep(3);
        endwin();
        exit(0);
    }

}

void initMap(char map[MAP_SIZE][MAP_SIZE]){
    memset(map, BACKGROUND, sizeof(char)*MAP_SIZE*MAP_SIZE);   

    //Makes the borders
    int i;
    for(i = 0; i<MAP_SIZE; i++){
        map[0][i] = '#';
        map[i][0] = '#';
        map[MAP_OFFSET][i] = '#';
        map[i][MAP_OFFSET] = '#';
    }

    //Adds the random treasures
    srand(time(NULL));
    int randX;
    int randY;
    i = 0;
    while(i <= RAND_ELEMS) {
        randX = (rand() % RAND_OFFSET)+1;
        randY = (rand() % RAND_OFFSET)+1;
        if(map[randX][randY] == BACKGROUND){
            map[randX][randY] = '$';
            i++;
        }
    } 

}

void moveHero(int c, Hero *h){
    switch(c){
        case 27:
            endwin();
            exit(0);
        case 258:
            if(h->x+1 > MAP_SIZE-2)
                return;
            h->x += 1;
            h->movement -= 1;
            break;
        case 259:
            if(h->x-1 == 0)
                return;
            h->x -= 1;
            h->movement -= 1;
            break;
        case 260:
            if(h->y-1 == 0)
                return;
            h->y -= 1;
            h->movement -= 1;
            break;
        case 261:
            if(h->y+1 > MAP_SIZE-2)
                return;
            h->y += 1;
            h->movement -= 1;
            break;
    }
}

int main(int argc, char** argv){

    //Map setup
    char map[MAP_SIZE][MAP_SIZE];
    initMap(map);  

    //curses setup
    initscr(); 
    noecho();
    keypad(stdscr, TRUE);

    //color setup
    start_color();
    init_pair(0, COLOR_BLACK, COLOR_WHITE);
    init_pair(1, COLOR_RED, COLOR_GREEN);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_MAGENTA);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLUE);
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
    init_pair(7, COLOR_WHITE, COLOR_CYAN);

    //Random number used to decide color
    int curColor = rand() % 8;
    srand(time(NULL)); 
    attron(COLOR_PAIR(curColor));

    //hero setup
    Hero *hero = new Hero(PLAYER_X, PLAYER_Y, PLAYER_ENERGY);

    int c;
    //main game loop
    update(map, hero);
    while(1){
        attroff(COLOR_PAIR(curColor));
        curColor = rand() % 8;
        attron(COLOR_PAIR(curColor));
        if(kbhit){
            c = getch();
            moveHero(c, hero);
            if(map[hero->x][hero->y] == '$'){
                hero->score += 1;
                map[hero->x][hero->y] = BACKGROUND;
            }
        }
        update(map, hero);    
    }
    return 0;
}

