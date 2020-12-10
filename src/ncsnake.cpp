#include <list>
#include <ncurses.h>
#include <chrono>
#include <thread>
#include <stdlib.h>
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
    update_score(false);
    wrefresh(score_win);

    game_win = newwin(15, 30, 2, 0);
    keypad(game_win, true);
    wborder(game_win, 0, 0, 0, 0, ACS_LTEE, ACS_RTEE, 0, 0);
    
    snake = new Snake(game_win, 3, 10, 15, UP);

    gen_collect();
}

void NCSnake::start() {
    snake->draw();
    wrefresh(game_win);

    int status = 0;
    while (status >= 0) {
        status = step();
    }

    delete snake;
}

int NCSnake::step() {
    int ret = 0;
    int64_t start = time_in_ms();

    halfdelay(STEP_MS / 100);
    int c = wgetch(game_win);

    int64_t elapsed = time_in_ms() - start;
    if (elapsed < STEP_MS) wait_ms(STEP_MS - elapsed);

    control_snake(c);
    int collide_char = snake->move_draw();
    ret = handle_collision(collide_char);
    wrefresh(game_win);

    cbreak();

    return ret;
}

void NCSnake::control_snake(int c) {
    switch (c) {
        case KEY_UP:
            if (snake->get_dir() != DOWN)
                snake->set_dir(UP);
            break;
        case KEY_DOWN:
            if (snake->get_dir() != UP)
                snake->set_dir(DOWN);
            break;
        case KEY_LEFT:
            if (snake->get_dir() != RIGHT)
                snake->set_dir(LEFT);
            break;
        case KEY_RIGHT:
            if (snake->get_dir() != LEFT)
                snake->set_dir(RIGHT);
            break;
        default:
            break;
    }
}

void NCSnake::update_score(bool inc /* = true */) {
    if (inc) score++;
    mvwprintw(score_win, 1, 20, "SCORE: %2d", score);
    wrefresh(score_win);
}

int NCSnake::handle_collision(int c) {
    switch (c) {
        case COLLECT_CHAR:
            update_score();
            snake->grow();
            gen_collect();
            break;
        case BACKGROUND_CHAR:
            break;
        default: // wall or snake character, player loses
            return -1;
    }

    return 0;
}

void NCSnake::gen_collect() {
    int y_max = 0;
    int x_max = 0;
    getmaxyx(game_win, y_max, x_max);

    int y;
    int x;
    do {
        y = (rand() % (y_max - 2)) + 1;
        x = (rand() % (x_max - 2)) + 1;
    } while (get_char_at(game_win, y, x) == SNAKE_CHAR);

    mvwaddch(game_win, y, x, COLLECT_CHAR);
    wrefresh(game_win);
}
