#ifndef TOKENARRAY_H
#define TOKENARRAY_H

#include <stddef.h>

typedef struct {
  Token *tokens;
  size_t amount;
  size_t capacity;
} TokenArray;

#endif
