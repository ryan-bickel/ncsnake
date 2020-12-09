#include <ncurses.h>
#include "snake.h"

Snake::Snake(size_t len, int y, int x, int dir) {
    for (unsigned i = 0; i < len; i++) {
        parts.push_back(SnakePart(y + i, x, dir));
    }
}

size_t Snake::length() {
    return parts.size();
}

void Snake::draw() {
    list<SnakePart>::iterator it;
    for (it = parts.begin(); it != parts.end(); it++) {
        mvaddch(it->y, it->x, '#');
    }
}

void Snake::move_draw() {
    list<SnakePart>::iterator it;
    for (it = parts.begin(); it != parts.end(); it++) {
        it->move_draw(is_tail(it));
    }
}

bool Snake::is_tail(list<SnakePart>::iterator it) {
    return it != parts.end() && next(it) == parts.end();
}

list<SnakePart>::iterator Snake::next(list<SnakePart>::iterator it) {
    return ++it;
}

