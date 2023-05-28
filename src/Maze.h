#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define COLOR "\x1b[36;1m"
#define NO_COLOR "\x1b[0;0m"

void read_size(int *mat_sz);
void read_matrix(char *mat, int mat_sz);
void print_matrix(char *mat, bool *vis, int mat_sz);

#endif
