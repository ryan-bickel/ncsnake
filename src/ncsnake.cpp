#include <list>
#include <ncurses.h>
#include "ncsnake.h"
#include "snake.h"
#include "sconsts.h"

void init_game() {
    Snake* snake = new Snake(5, 3, 3, RIGHT);

    snake->draw();
    refresh();

    while (true) {
        int c = getch();
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
        refresh();
    }

    delete snake;
}
