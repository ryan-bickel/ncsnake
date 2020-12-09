#include "ncsnake.h"
#include "snake.h"
#include <list>
#include <ncurses.h>

void init_game() {
    Snake snake = Snake(3, 3, 3, UP);
    snake.draw();
    refresh();
}
