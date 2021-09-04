#ifndef SNAKE_H
#define SNAKE_H
#include "segment.h"

#define UP (struct Vector2){ .x = 0, .y = 1 }
#define DOWN (struct Vector2){ .x = 0, .y = -1 }
#define LEFT (struct Vector2){ .x = -1, .y = 0 }
#define RIGHT (struct Vector2){ .x = 1, .y = 0 }
#define EMPTY (struct Vector2){ .x = 0, .y = 0 }

// The head will be represented as if it's the head
// of a snake and not a linked list
// in that case the head of the snake linked list
// would be the "tail" variable
struct Snake {
    struct Segment *tail;
    struct Segment *head;
    struct Vector2 dir;
};

struct Snake *snake_init(struct Vector2 start_pos, struct Vector2 start_dir);
size_t snake_len(struct Snake *snake);
bool snake_contains(struct Snake *snake, struct Vector2 target);
bool hitting_self(struct Snake *snake);
bool can_change_dir(struct Snake *snake, struct Vector2 dir);
void change_dir(struct Snake *snake, struct Vector2 new_dir);
void append_snake(struct Snake *snake, struct Vector2 pos);
void move_snake(struct Snake *snake);

#endif // SNAKE_H
