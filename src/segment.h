#ifndef SEGMENT_H
#define SEGMENT_H
#include "util/util.h"

struct Segment {
    struct Vector2 pos;
    struct Segment *next;
};

struct Segment *segment_init(struct Vector2 pos);

#endif // SEGMENT_H
