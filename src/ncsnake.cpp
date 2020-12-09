#include <list>
#include <ncurses.h>
#include "ncsnake.h"
#include "snake.h"
#include "direction.h"

void init_game() {
    Snake snake = Snake(4, 3, 3, UP);

    snake.draw();
    refresh();

    getch();

    snake.move_draw();
    refresh();
}
