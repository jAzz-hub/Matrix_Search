#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>
#include <string.h>

#define MAXCOLS 30
#define MAXROWS 30
#define NUMAT   1

// typedef struct Item{
// 	char val;
// }Item;

// typedef struct Matrix{
// 	Item m[MAXCOLS][MAXROWS];
// }Matrix;


typedef struct tile
{
	char value;
	bool explored;
}tile;

// void GenerateMatrix(Matrix *mat);
// void SetMatrixSignature();
// void SaveMatrix(Matrix *mat);
