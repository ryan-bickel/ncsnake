#include <list>
#include <ncurses.h>
#include "ncsnake.h"
#include "snake.h"
#include "sconsts.h"

WINDOW* NCSnake::game_win;
WINDOW* NCSnake::score_win;
Snake* NCSnake::snake;
int NCSnake::score;

void NCSnake::init() {
    score_win = newwin(3, 30, 0, 0);
    wborder(score_win, 0, 0, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE);
    mvwprintw(score_win, 1, 1, "SNAKE");

    score = 0;
    mvwprintw(score_win, 1, 20, "SCORE: %2d", score);
    wrefresh(score_win);

    game_win = newwin(15, 30, 2, 0);
    keypad(game_win, true);
    wborder(game_win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, 0, 0);
    
    snake = new Snake(game_win, 10, 3, 3, RIGHT);
}

void NCSnake::start() {
    snake->draw();
    wrefresh(game_win);

    while (true) {
        int c = wgetch(game_win);
        switch (c) {
            case KEY_UP:
                snake->set_dir(UP);
                break;
            case KEY_DOWN:
                snake->set_dir(DOWN);
                break;
            case KEY_LEFT:
                snake->set_dir(LEFT);
                break;
            case KEY_RIGHT:
                snake->set_dir(RIGHT);
                break;
            default:
                break;
        }
        
        snake->move_draw();
        wrefresh(game_win);
    }

    delete snake;
}
