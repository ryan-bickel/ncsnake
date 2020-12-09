#ifndef _SNAKE_H_
#define _SNAKE_H_

#include <list>

using namespace std;

#define UP    0
#define DOWN  1
#define LEFT  2
#define RIGHT 3

class Snake {
private:
    class SnakePart {
    public:
        int y;
        int x;
        int dir;
        SnakePart(int y, int x, int dir) : y(y), x(x), dir(dir) {};
        int move(int dir);
    };

    list<SnakePart> parts;
public:
    Snake(size_t len, int y, int x, int dir);
    size_t length();
};

#endif