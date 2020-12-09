#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <stdlib.h>
#include <list>
#include "snakepart.h"

using namespace std;

class Snake {
private:
    list<SnakePart> parts;

    // is this SnakePart the tail? 
    bool is_tail(list<SnakePart>::iterator part);
public:
    Snake(size_t len, int y, int x, int dir);

    // length of the snake
    size_t length();

    // draw the snake
    void draw();

    // move the snake in its current direction then draw it
    void move_draw();
};

#endif