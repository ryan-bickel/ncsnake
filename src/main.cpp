#include <ncurses.h>
#include "ncsnake.h"

int main(int argc, char** argv) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    NCSnake::init();
    NCSnake::start();

    getchar();

    endwin();
    return 0;
}