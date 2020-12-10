#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdlib.h>
#include <list>
#include <ncurses.h>

using namespace std;

class SnakePart {
public:
    WINDOW* win;
    int y;
    int x;
    int dir;
    SnakePart* next;
    SnakePart* prev;

    SnakePart(WINDOW* win, int y, int x, int dir) : win(win), y(y), x(x), dir(dir), next(nullptr), prev(nullptr) {};

    // move this part
    int move_draw();
};

class Snake {
private:
    WINDOW* win;
    SnakePart* head;
    SnakePart* tail;
    size_t len;
public:
    Snake(WINDOW* win, size_t len, int y, int x, int dir);

    // length of the snake
    size_t length();

    // draw the snake
    void draw();

    // move the snake in its current direction then draw it
    int move_draw();

    // change the direction the head of the snake is moving
    void set_dir(int dir) {
        head->dir = dir;
    }

    int get_dir() {
        return head->dir;
    }

    // add a part to the snake and increase its length by 1
    void grow();

    static void operator delete(void* p) {
        Snake* s = (Snake*) p;
        SnakePart* curr = s->head;
        while (curr != nullptr) {
            SnakePart* next = curr->next;
            delete curr;
            curr = next;
        }
    }
};

#endif