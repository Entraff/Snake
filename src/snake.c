#include "snake.h"

const struct Vector2 UP = { .x = 0, .y = 1 };
const struct Vector2 DOWN = { .x = 0, .y = -1 };
const struct Vector2 LEFT = { .x = -1, .y = 0 };
const struct Vector2 RIGHT = { .x = 1, .y = 0 };
const struct Vector2 EMPTY = { .x = 0, .y = 0 };

struct Snake *snake_init(struct Vector2 start_pos, struct Vector2 start_dir) {
    struct Snake *snake = malloc(sizeof(*snake));
    struct Segment *start_seg = segment_init(start_pos);

    snake->head = start_seg;
    snake->tail = start_seg;
    snake->dir = start_dir;

    return snake;
}

bool hitting_self(struct Snake *snake) {
    struct Segment *current = snake->tail;
    bool hitting_body;

    while (current != NULL) {
        hitting_body = vec2cmp(current->pos, snake->head->pos);
        if (hitting_body)
            return true;
        current = current->next;
    }

    return false;
}

// If the new direction moves into the snake
// it is not allowed to move
bool can_change_dir(struct Snake *snake, struct Vector2 new_dir) {
    struct Vector2 sum = vec2add(new_dir, snake->dir); 
    return sum.x == 0 &&
           sum.y == 0;
}

void change_dir(struct Snake *snake, struct Vector2 new_dir) {
    if (!can_change_dir(snake, new_dir))
        return;
    snake->dir = new_dir;
}

void append_snake(struct Snake *snake, struct Vector2 pos) {
    struct Segment *segment = segment_init(pos);
    snake->head->next = segment;
    snake->head = segment;
}

void move_snake(struct Snake *snake) {
    struct Segment *current = snake->tail;

    while (current != NULL) {
        current->pos = current->next->pos;
        current = current->next;
    }

    snake->head->pos = vec2add(snake->head->pos, snake->dir);
}
