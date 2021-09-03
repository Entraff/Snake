#ifndef BOARD_H
#define BOARD_H
#include "snake.h"

// Default values
#define DEF_POS { .x = 5, .y = 5 }
#define DEF_DIR RIGHT

struct Board {
    struct Snake *snake;
    struct Vector2 apple;
    int score;
};

struct Board *board_init();
void tick(struct Board* board, struct Vector2 dir);

#endif // BOARD_H
