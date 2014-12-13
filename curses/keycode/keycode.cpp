#include <ncurses.h>

int main(int argc, char** argv){
    initscr();
    noecho();
    raw();
    keypad(stdscr, TRUE);
    int c;
    printw("Write something(ESC to quit)");
    while((c = getch()) != 27){
        erase();
        move(5, 0);
        printw("Keycode: %d | Character: %c", c, c);
        move(0,0);
        printw("Write something(ESC to quit)");
        refresh();
    } 
    endwin();
    

    return 0;
}

