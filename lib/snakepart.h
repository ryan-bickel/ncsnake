#ifndef _SNAKEPART_H_
#define _SNAKEPART_H_

class SnakePart {
public:
    int y;
    int x;
    int dir;
    SnakePart* next;
    SnakePart* prev;

    SnakePart(int y, int x, int dir) : y(y), x(x), dir(dir), next(nullptr), prev(nullptr) {};

    // move this part then draw it and erase where it was if <erase>
    void move_draw();
};

#endif