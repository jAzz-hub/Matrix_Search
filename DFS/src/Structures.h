#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include <unistd.h>

#define MAXCOLS 30
#define MAXROWS 30
#define NUMAT   1

typedef struct Item{
	char val;
}Item;

typedef struct Matrix{
	Item m[MAXROWS][MAXCOLS];
}Matrix;

void GenerateMatrix(Matrix *mat);
void SetMatrixSignature();
void SaveMatrix(Matrix *mat);
