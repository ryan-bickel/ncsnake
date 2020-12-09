#include <list>
#include <ncurses.h>
#include "ncsnake.h"
#include "snake.h"
#include "sconsts.h"

void init_game() {
    Snake* snake = new Snake(4, 3, 3, UP);

    snake->draw();
    refresh();

    getch();

    snake->move_draw();
    refresh();

    delete snake;
}
