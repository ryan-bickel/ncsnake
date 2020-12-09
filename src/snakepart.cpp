#include <ncurses.h>
#include "snakepart.h"
#include "sconsts.h"

void SnakePart::move_draw() {
    if (!next) mvaddch(y, x, BACKGROUND_CHAR);

    if (dir == UP) {
        y--;
    } else if (dir == DOWN) {
        y++;
    } else if (dir == LEFT) {
        x--;
    } else if (dir == RIGHT) {
        x++;
    } else if (dir == FOLLOW) {
        x = prev->x;
        y = prev->y;
    }

    if (!prev) mvaddch(y, x, SNAKE_CHAR);
}