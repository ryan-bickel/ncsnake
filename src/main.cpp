#include <ncurses.h>
#include "ncsnake.h"

int main(int argc, char** argv) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();
    curs_set(0);

    init_game();

    getchar();

    endwin();
    return 0;
}