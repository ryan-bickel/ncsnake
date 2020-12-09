#include <ncurses.h>
#include "ncsnake.h"

int main(int argc, char** argv) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();

    init_game();

    getchar();

    endwin();
    return 0;
}