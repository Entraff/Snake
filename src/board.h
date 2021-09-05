#ifndef BOARD_H
#define BOARD_H
#include "snake.h"

// Default values
#define DEF_POS (struct Vector2){ .x = 5, .y = 5 }
#define DEF_DIR RIGHT

struct Board {
    struct Vector2 dimensions;
    struct Snake *snake;
    struct Vector2 apple;
    int score;
};

void generate_apple(struct Board *board);
struct Board *board_init(struct Vector2 dimensions);
bool exceeds_bounds(struct Board *board);
bool has_died(struct Board *board);
bool eating_apple(struct Board *board);
void tick(struct Board *board, struct Vector2 dir);
void render(struct Board *board);

#endif // BOARD_H
