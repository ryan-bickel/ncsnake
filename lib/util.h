#ifndef _UTIL_H_
#define _UTIL_H_

#include <stdint.h>
#include <ncurses.h>

int64_t time_in_ms();
void wait_ms(int64_t ms);
int get_char_at(WINDOW* win, int y, int x);

#endif
