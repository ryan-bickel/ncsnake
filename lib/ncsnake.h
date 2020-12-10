#ifndef _NCSNAKE_H_
#define _NCSNAKE_H_

#include <ncurses.h>
#include "snake.h"

class NCSnake {
    static WINDOW* game_win;
    static WINDOW* score_win;
    static Snake* snake;
    static int score;
public:
    static void init();
    static void start();
};


#endif