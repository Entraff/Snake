#include "segment.h"

struct Segment *segment_init(struct Vector2 pos) {
    struct Segment *segment = malloc(sizeof(*segment));

    segment->pos = pos;
    segment->next = NULL;

    return segment;
}
