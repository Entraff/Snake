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
