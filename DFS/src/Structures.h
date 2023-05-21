#include<stdbool.h>

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
  unsigned char x;
  unsigned char y;
} Cord;

// void GenerateMatrix(Matrix *mat);
// void SetMatrixSignature();
// void SaveMatrix(Matrix *mat);
