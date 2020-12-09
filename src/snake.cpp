#include <ncurses.h>
#include "snake.h"
#include "sconsts.h"

Snake::Snake(WINDOW* win, size_t len, int y, int x, int dir) : win(win), len(len) {
    head = new SnakePart(win, y, x, dir);
    tail = head;
    for (unsigned i = 0; i < len - 1; i++) {
        SnakePart* new_part = new SnakePart(win, y + i, x, FOLLOW);
        tail->next = new_part;
        new_part->prev = tail;
        tail = new_part;
    }
}

size_t Snake::length() {
    return this->len;
}

void Snake::draw() {
    for (SnakePart* curr = head; curr != nullptr; curr = curr->next) {
        mvwaddch(win, curr->y, curr->x, SNAKE_CHAR);
    }
}

void Snake::move_draw() {
    for (SnakePart* curr = tail; curr != nullptr; curr = curr->prev) {
        curr->move_draw();
    }
}


void SnakePart::move_draw() {
    if (!next) mvwaddch(win, y, x, BACKGROUND_CHAR);

    switch (dir) {
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case FOLLOW:
            x = prev->x;
            y = prev->y;
            break;
        default:
            break;
    }

    if (!prev) mvwaddch(win, y, x, SNAKE_CHAR);
}
