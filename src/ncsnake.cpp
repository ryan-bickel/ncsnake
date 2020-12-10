#include <list>
#include <ncurses.h>
#include <chrono>
#include <thread>
#include "ncsnake.h"
#include "snake.h"
#include "sconsts.h"
#include "util.h"

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
        step();
    }

    delete snake;
}

void NCSnake::step() {
    int64_t start = time_in_ms();

    halfdelay(STEP_MS / 100);
    int c = wgetch(game_win);

    int64_t elapsed = time_in_ms() - start;
    if (elapsed < STEP_MS) wait_ms(STEP_MS - elapsed);

    control_snake(c);
    snake->move_draw();
    wrefresh(game_win);

    cbreak();
}

void NCSnake::control_snake(int c) {
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
}
