#include <stdio.h>
#include <curses.h>
#include <stdlib.h>
#include <unistd.h>

#define MAPX 58
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
    keypad(stdscr, TRUE);
    start_color();
    init_pair(1, COLOR_BLACK, COLOR_WHITE);    
}

int kbhit(){
    int ch = getch();
    if(ch != ERR)
        return ch;
    else
        return 0;
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

void draw(square **map, int mode){
    erase();
    int i, j;
    for(i = 0; i<MAPX; i++){
        for(j = 0; j<MAPY; j++){
            move(i, j);
            attron(COLOR_PAIR(map[i][j].cur));
            printw("%c", 32);
            attroff(COLOR_PAIR(map[i][j].cur));
        }
    }
    move(MAPX, 0);
    printw("FPS: %d     ESC to quit     SPACE to pause      D to enter drawing mode    P to print to file      R to read from file      C to clear screen", FPS);
    move(MAPX+1, 0);
    if(mode == 0){
        printw("Simulation mode");
    }else if(mode == 1){
        printw("Draw mode");
    }else{
        printw("Filename: ");
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
    draw(map, 0);
}

void setNextToDead(square **map){
    int i, j;
    for (i = 0; i < MAPX; i++) {
        for (j = 0; j < MAPY; j++) {
           map[i][j].next = DEAD; 
        }
    }
}
void clearScr(square **map){
    int i, j;
    for (i = 0; i < MAPX; i++) {
        for (j = 0; j < MAPY; j++) {
            map[i][j].cur = DEAD;
            map[i][j].next = DEAD;
        }
    }
}

void drawMode(square **map){
    int c;
    int x = MAPX/2 ,y = MAPY/2;

    setNextToDead(map);

    for(;;){
        if((c = kbhit()) != 0){
            switch(c){
                case 258:
                    if(x < MAPX-1)
                        x++;
                    break;
                case 259:
                    if(x > 0)
                        x--;
                    break;
                case 260:
                    if(y > 0)
                        y--;
                    break;
                case 261:
                    if(y < MAPY-1)
                        y++;
                    break;
                case 27:
                    return;
                case 100:
                    return;
                case 10:
                    map[x][y].cur = LIVE;
                    break;
                case 127:
                    map[x][y].cur = DEAD;
                    break;
            } 
            draw(map, 1);
            move(x, y);
            attron(COLOR_PAIR(map[x][y].cur));
            printw("@");
            attroff(COLOR_PAIR(map[x][y].cur));

        }
    }
}


void writeFile(square **map){
    curs_set(1);
    nodelay(stdscr, 0);
    echo();
    
    char buffer[50];
    FILE *out;
    int i, j;

    draw(map, 2);
    move(MAPX+1, 10);
    scanw("%s", &buffer);

    out = fopen(buffer, "w");

    for (i = 0; i < MAPX; i++) {
        for (j = 0; j < MAPY; j++) {
            fprintf(out, "%d", map[i][j].cur);
        }
        fprintf(out, "\n");
    }

    curs_set(0);
    noecho();
    nodelay(stdscr, 1); 
}

void readFile(square **map){
    curs_set(1);
    echo();
    nodelay(stdscr, 0);

    char buffer[MAPY*2];
    FILE *in;
    int i = 0, j;

    setNextToDead(map);

    draw(map, 2);
    move(MAPX+1, 10);
    scanw("%s", &buffer);
    
    in = fopen(buffer, "r");

    if(in == NULL){
        draw(map, 2);
        move(MAPX+1, 0);
        printw("Could not open file %s", buffer);

        getch();
        curs_set(0);
        noecho();
        nodelay(stdscr, 1);

        return;
    }
    
    while(fgets(buffer, sizeof(buffer), in) != NULL){
       for (j = 0; j < MAPY; j++) {
           map[i][j].cur = buffer[j]-48;
       } 
       i++;
    }
    curs_set(0);
    noecho();
    nodelay(stdscr, 1);
    draw(map, 0);
}


int main(void){
    square **map;
    int pause = 0;
    int c;
    //initialize
    init_curses();
    map = allocate_map();

    //Glider 
    /*
    map[5][5].cur = LIVE;
    map[5][6].cur = LIVE;
    map[5][7].cur = LIVE;
    map[4][7].cur = LIVE;
    map[3][6].cur = LIVE;
    */

    //Ocilator
    /*
    map[5][5].cur = LIVE;
    map[6][5].cur = LIVE;
    map[7][5].cur = LIVE;
    */

    for(;;){
        if((c = kbhit()) != 0){
            switch(c){
                case 32:
                    if(pause == 0) pause = 1;
                    else if(pause == 1) pause = 0;
                    break;
                case 27:
                    destruct(map);
                    return 0;
                case 100:
                    pause = 1;
                    drawMode(map);
                    break;
                case 112:
                    writeFile(map);
                    break;
                case 114:
                    readFile(map);
                    pause = 1;
                    break;
                case 99:
                    clearScr(map);
                    draw(map, 0);
                    pause = 1;
                    break;
            }
        }
        if(pause == 0)
            gameoflife(map);
        usleep(SECOND/FPS);
    }

    destruct(map);
    return 0;
}

