#include "snake.h"

Snake::Snake(size_t len, int y, int x, int dir) {
    for (int i = 0; i < len; i++) {
        parts.push_back(SnakePart(y - i, x, dir));
    }
}

size_t Snake::length() {
    return parts.size();
}


int Snake::SnakePart::move(int dir) {
    if (dir == UP) {
        y--;
    } else if (dir == DOWN) {
        y++;
    } else if (dir == LEFT) {
        x--;
    } else if (dir == RIGHT) {
        x++;
    } else {
        return -1;
    }

    return 0;
}