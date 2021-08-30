#include "vec2.h"

bool vec2cmp(struct Vector2 a, struct Vector2 b) {
    return a.x == b.x &&
           a.y == b.y;
}

struct Vector2 vec2add(struct Vector2 a, struct Vector2 b) {
    const int x = a.x + b.x;
    const int y = a.y + b.y;
    return (struct Vector2){ x, y };
}
