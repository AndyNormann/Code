#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <string.h>

#define STARTX 25
#define STARTY 100

#define MAPW 62
#define MAPH 200

struct Ant{
    int x;
    int y;
    int rot;
};

int *map;
int *color;
struct Ant* ant;


void initAnt(){
    ant = malloc(sizeof(struct Ant));
    ant->x = STARTX;
    ant->y = STARTY;
    ant->rot = 1;
}
void destructAnt(struct Ant *ant){
    free(ant);
    endwin();
}


void moveAnt(){ 
    //increments color and changes rotation appropriately
    switch(color[ant->x+(ant->y*MAPW)]++){
        case 1:
            ant->rot++;            
            break;
        case 2:
            ant->rot--;
            break;
        case 3:
            ant->rot++;
            break;
        case 4:
            ant->rot--;
            break;
        case 5:
            ant->rot++;
            break;
    }

    //resets color once it reaches it's max
    if(color[ant->x+(ant->y*MAPW)] > 5){
        color[ant->x+(ant->y*MAPW)] = 1;
    }

    //resets rotation once it reaches it's max
    if(ant->rot > 4){
        ant->rot = 1;
    }else if(ant->rot < 1){
        ant->rot = 4;
    }

    //Rotates ant
    switch(ant->rot){
    case 1:
        ant->y++;
        break;
    case 2:
        ant->x++;
        break;
    case 3:
        ant->y--;
        break;
    case 4:
        ant->x--;
        break;
    }
    //Makes sure the ant doesen't leave the grid
    if(ant->y >= MAPH-1)
        ant->y = 3;
    else if(ant->y < 0)
        ant->y = MAPH-3;
    else if(ant->x >= MAPW-1)
        ant->x = 3;
    else if(ant->x < 0)
        ant->x = MAPW-3;

}

void drawMap(){
    //Draws the map
    int i, j;
    for (i = 0; i < MAPW-1; i++) {
        for (j = 0; j < MAPH-1; j++) {
            move(i, j);
            attron(COLOR_PAIR(color[i+(j*MAPW)]));
            printw("%c", 32);
            attroff(COLOR_PAIR(color[i+(j*MAPW)]));
        }
    }
    //Draws the ant
    move(ant->x, ant->y);
    attron(COLOR_PAIR(color[ant->x+(ant->y*MAPW)]));
    printw("%c", '@');
    attroff(COLOR_PAIR(color[ant->x+(ant->y*MAPW)]));
    refresh();
}

int main(void){
    initAnt();

    //init curses
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);

    //setup colors
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_WHITE, COLOR_BLACK);
    init_pair(3, COLOR_BLACK, COLOR_GREEN);
    init_pair(4, COLOR_BLACK, COLOR_BLUE);
    init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
 
    color = malloc(sizeof(int)*MAPW*MAPH);

    //Set each color position to white
    int i;
    for(i = 0; i<MAPH*MAPW; i++){
        color[i] = 1;
    }

    //main loop
    int c;
    while((c = getch()) != 27){
        moveAnt();
        drawMap();
    }

    //free memory, turn off curses mode and return
    destructAnt(ant);
    free(map);
    free(color);
    return 0;
}
