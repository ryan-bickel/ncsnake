#include <ncurses.h>
#include "ncsnake.h"

int main(int argc, char** argv) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    NCSnake::init();

    getchar();

    endwin();
    return 0;
}