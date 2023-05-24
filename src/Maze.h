#ifndef MAZE_H
#define MAZE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_size(int *mat_sz);
void read_matrix(char *mat, int mat_sz);
void print_matrix(char *mat, bool *vis, int mat_sz);
void clear_boolean(bool*vis, int mat_sz);

#endif
