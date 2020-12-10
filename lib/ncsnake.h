#ifndef _NCSNAKE_H_
#define _NCSNAKE_H_

#include <ncurses.h>
#include "snake.h"

class NCSnake {
    static WINDOW* game_win;
    static WINDOW* score_win;
    static Snake* snake;
    static int score;

    static void step();
    static void control_snake(int c);
public:
    static void init();
    static void start();
};

int64_t time_in_ms();
void wait_ms(int64_t ms);


#endif