#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdlib.h>
#include <list>

using namespace std;

class SnakePart {
public:
    int y;
    int x;
    int dir;
    SnakePart* next;
    SnakePart* prev;

    SnakePart(int y, int x, int dir) : y(y), x(x), dir(dir), next(nullptr), prev(nullptr) {};

    // move this part
    void move_draw();
};

class Snake {
private:
    SnakePart* head;
    SnakePart* tail;
    size_t len;
public:
    Snake(size_t len, int y, int x, int dir);

    // length of the snake
    size_t length();

    // draw the snake
    void draw();

    // move the snake in its current direction then draw it
    void move_draw();

    // change the direction the head of the snake is moving
    void set_dir(int dir) {
        head->dir = dir;
    }

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