#ifndef _DIRECTION_H_
#define _DIRECTION_H_

#include <stdint.h>

constexpr int UP = 0;
constexpr int DOWN = 1;
constexpr int LEFT = 2;
constexpr int RIGHT = 3;
constexpr int FOLLOW = 4;

constexpr char SNAKE_CHAR = '#';
constexpr char BACKGROUND_CHAR = ' ';
constexpr char COLLECT_CHAR = 'O';

// must be >= 100 for halfdelay to work
constexpr int64_t STEP_MS = 100;

#endif