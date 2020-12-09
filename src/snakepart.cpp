#include <ncurses.h>
#include "snakepart.h"
#include "direction.h"

void SnakePart::move_draw(bool erase = false) {
    if (erase) mvaddch(y, x, ' ');

    if (dir == UP) {
        y--;
    } else if (dir == DOWN) {
        y++;
    } else if (dir == LEFT) {
        x--;
    } else if (dir == RIGHT) {
        x++;
    }

    mvaddch(y, x, '#');
}