#ifndef VEC2_H
#define VEC2_H

#include "stdbool.h"

struct Vector2 {
    int x, y;
};

bool vec2cmp(struct Vector2 a, struct Vector2 b);
struct Vector2 vec2add(struct Vector2 a, struct Vector2 b);

#endif // VEC2_H
