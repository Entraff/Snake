#include "snake.h"

struct Snake *snake_init(struct Vector2 start_pos, struct Vector2 start_dir) {
    struct Snake *snake = malloc(sizeof(*snake));
    struct Segment *start_seg = segment_init(start_pos);

    snake->head = start_seg;
    snake->tail = start_seg;
    snake->dir = start_dir;

    return snake;
}

size_t snake_len(struct Snake *snake) {
    struct Segment *current = snake->tail;
    size_t len = 0;
    
    while (current != NULL) {
        ++len;
        current = current->next;
    }

    return len;
}

bool snake_contains(struct Snake *snake, struct Vector2 target) {
    struct Segment *current = snake->tail;
    bool found_target;

    while (current != NULL) {
        found_target = vec2cmp(current->pos, target);
        if (found_target)
            return true;
        current = current->next;
    }

    return false;
}

bool hitting_self(struct Snake *snake) {
    struct Segment *current = snake->tail;
    bool hitting_body;

    while (current != snake->head) {
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
