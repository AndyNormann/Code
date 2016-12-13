extern crate ncurses;

use ncurses::*;

pub fn main() {
    initscr();

    printw("Halla");

    refresh();

    getch();

    endwin();
}
