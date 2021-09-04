#include "util.h"

int rand_range(const int min, const int max) {
    return rand() % (max - min) + min;
}
