#include <ncurses.h>
#include "snake.h"
#include "sconsts.h"
#include "util.h"

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

int Snake::move_draw() {
    for (SnakePart* curr = tail; curr != head; curr = curr->prev) {
        curr->move_draw();
    }

    return head->move_draw();
}

void Snake::grow() {
    int x = tail->x;
    int y = tail->y;
    SnakePart* ptail = tail->prev;
    if (tail->x > ptail->x) {
        x = tail->x + 1;
    } else if (tail->x < ptail->x) {
        x = tail->x - 1;
    } else if (tail->y > ptail->y) {
        y = tail->y + 1;
    } else if (tail->y < ptail->y) {
        y = tail->y - 1;
    }

    SnakePart* new_part = new SnakePart(win, y, x, FOLLOW);
    new_part->prev = tail;
    tail->next = new_part;
    tail = new_part;
}


int SnakePart::move_draw() {
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

    int collide_char = -1;
    if (!prev) {
        collide_char = get_char_at(win, y, x);
        mvwaddch(win, y, x, SNAKE_CHAR);
    }

    return collide_char;
}
