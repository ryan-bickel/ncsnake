#include <chrono>
#include <thread>
#include <ncurses.h>
#include "util.h"

using namespace std;

int64_t time_in_ms() {
    return (int64_t) chrono::duration_cast<chrono::milliseconds>(chrono::system_clock().now().time_since_epoch()).count();
}

void wait_ms(int64_t ms) {
    this_thread::sleep_for(chrono::milliseconds(ms));
}

int get_char_at(WINDOW* win, int y, int x) {
    return mvwinch(win, y, x) & A_CHARTEXT;
}
