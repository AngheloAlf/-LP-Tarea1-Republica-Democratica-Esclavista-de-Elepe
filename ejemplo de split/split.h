#ifndef SPLIT_H
#define SPLIT_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **split(const char *phrase, const size_t length, const char delimiter, size_t *n_tokens);

#endif
