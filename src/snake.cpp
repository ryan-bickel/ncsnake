#include <ncurses.h>
#include "snake.h"
#include "sconsts.h"

Snake::Snake(size_t len, int y, int x, int dir) {
    head = new SnakePart(y, x, dir);
    tail = head;
    for (unsigned i = 0; i < len; i++) {
        SnakePart* new_part = new SnakePart(y + i, x, dir);
        tail->next = new_part;
        tail = new_part;
    }
}

size_t Snake::length() {
    return this->len;
}

void Snake::draw() {
    for (SnakePart* curr = head; curr != nullptr; curr = curr->next) {
        mvaddch(curr->y, curr->x, SNAKE_CHAR);
    }
}

void Snake::move_draw() {
    for (SnakePart* curr = head; curr != nullptr; curr = curr->next) {
        curr->move_draw(curr == tail);
    }
}
