#ifndef STRUCTS_HPP
#define STRUCTS_HPP

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXCOLS 30
#define MAXROWS 30
#define NUMAT   1

// typedef struct Item{
// 	char val;
// }Item;

// typedef struct Matrix{
// 	Item m[MAXCOLS][MAXROWS];
// }Matrix;


typedef struct Tile
{
	char value;
	bool explored;
} Tile;

typedef struct Cord {
  short int x;
  short int y;
  unsigned char value;
} Cord;

// void GenerateMatrix(Matrix *mat);
// void SetMatrixSignature();
// void SaveMatrix(Matrix *mat);

#endif
