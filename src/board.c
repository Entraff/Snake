#include "board.h"

// Find all empty spots and randomly choose from said empty spots
void generate_apple(struct Board *board) {
    const size_t space_count = board->dimensions.x * board->dimensions.y;
    const size_t empty_count = space_count - snake_len(board->snake);
    struct Vector2 empty_spaces[empty_count]; 
    struct Vector2 current;
    // How many positions have currently passed
    size_t i = 0;

    // Iterates through every position on the board as current
    for (; current.y < board->dimensions.y; ++current.y) {
        for (; current.x < board->dimensions.x; ++current.x) {
            if (snake_contains(board->snake, current))
                continue;
            empty_spaces[i++] = current;
        }
    }

    size_t chosen_i = rand_range(0, empty_count);
    board->apple = empty_spaces[chosen_i];
}

struct Board *board_init(struct Vector2 dimensions) {
    struct Board *board = malloc(sizeof(*board));

    board->dimensions = dimensions;
    board->snake = snake_init(DEF_POS, DEF_DIR);
    board->score = 0;
    generate_apple(board);

    return board;
}

bool exceeds_bounds(struct Board *board) {
    struct Vector2 head_pos = board->snake->head->pos;
    return (head_pos.x < 0 || head_pos.x > board->dimensions.x) || 
           (head_pos.y < 0 || head_pos.y > board->dimensions.y);
}

bool has_died(struct Board *board) {
    return exceeds_bounds(board) || hitting_self(board->snake);
}

bool eating_apple(struct Board *board) {
    return vec2cmp(board->snake->head->pos, board->apple);
}

void tick(struct Board *board, struct Vector2 dir) {
    change_dir(board->snake, dir);

    if (eating_apple(board)) {
        // Append snake segment to the position of the apple
        append_snake(board->snake, board->apple);
        generate_apple(board);
    } else {
        move_snake(board->snake);
    }
}
