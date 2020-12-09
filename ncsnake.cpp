#include <ncurses.h>

int main(int argc, char** argv) {
    initscr();
    cbreak();
    keypad(stdscr, true);
    noecho();

    int c = getchar();
    addch(c);
    refresh();

    getchar();

    endwin();
    return 0;
}