#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define MAPX 61
#define MAPY 195

//FPS controlls
#define FPS 20
#define PPF 30
#define SECOND 1000000

enum{
    DEAD,
    LIVE
};

typedef struct Square{
    int cur;
    int next;
} square;

void init_curses(){
    initscr();
    noecho();
    curs_set(0);
    nodelay(stdscr, 1);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    
}

square **allocate_map(){
    int i;
    square **map;

    map = malloc(sizeof(square*)*MAPX);
    for(i = 0; i<MAPX; i++){
        map[i] = calloc(MAPY, sizeof(square));
    }
    return map;
}
void free_map(square **map){
    int i;
    for (i = 0; i < MAPX; i++) {
        free(map[i]);
    }
    free(map);
}

void destruct(square **map){
    free_map(map); 
    endwin();
}
int neighbours(square **map, int x, int y){
    int retVal = 0;
    
    if(x > 1){
        if(y > 1 && map[x-1][y-1].cur == LIVE) retVal++;
        if(map[x-1][y].cur == LIVE) retVal++;
        if(y < MAPY-2 && map[x-1][y+1].cur == LIVE) retVal++;
    }
    if(x < MAPX-2){
        if(y > 1 && map[x+1][y-1].cur == LIVE) retVal++;
        if(map[x+1][y].cur == LIVE) retVal++;
        if(y < MAPY-2 && map[x+1][y+1].cur == LIVE) retVal++;
    }
    if(y > 1 && map[x][y-1].cur == LIVE) retVal++;
    if(y < MAPY-2 && map[x][y+1].cur == LIVE) retVal++;

    return retVal;
}

void draw(square **map){
    int i, j;
    for(i = 0; i<MAPX; i++){
        for(j = 0; j<MAPY; j++){
            move(i, j);
            attron(COLOR_PAIR(map[i][j].cur));
            printw("%c", 32);
            attroff(COLOR_PAIR(map[i][j].cur));
        }
    }
}

void update(square **map){
    int i, j;

    for (i = 0; i < MAPX; i++) {
        for (j = 0; j < MAPY; j++) {
           map[i][j].cur = map[i][j].next; 
        }
    }
}

void gameoflife(square **map){
    int i, j;
    int curNeigh;

    for(i = 0; i<MAPX; i++){
        for(j = 0; j<MAPY; j++){
            curNeigh = neighbours(map, i, j);
            if(map[i][j].cur == LIVE){
                if(curNeigh < 2 || curNeigh > 3){
                    map[i][j].next = DEAD;
                }else{
                    map[i][j].next = LIVE;
                }
            }
            if(map[i][j].cur == DEAD && curNeigh == 3) map[i][j].next = LIVE;
        }
    }
    update(map);
    draw(map);
}

int main(void){
    square **map;
    int pause = 0;
    int c;
    //initialize
    init_curses();
    map = allocate_map();

    //Glider 
    map[5][5].cur = LIVE;
    map[5][6].cur = LIVE;
    map[5][7].cur = LIVE;
    map[4][7].cur = LIVE;
    map[3][6].cur = LIVE;
    

    //Ocilator
    /*
    map[5][5].cur = LIVE;
    map[6][5].cur = LIVE;
    map[7][5].cur = LIVE;
    */

    while((c = getch()) != 27){
        if(c == 32){
            if(pause == 0) pause = 1;
            else if(pause == 1) pause = 0;
        }
        if(pause == 0)
            gameoflife(map);
        usleep(SECOND/FPS);
    }

    destruct(map);
    return 0;
}

