#include "Maze.h"

void read_size(int *mat_sz) {
  FILE *fp = fopen("./dataset/input.data", "r");

  if(fp == NULL) {
    puts("Erro ao tentar abrir o arquivo");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%d %*S\n", mat_sz);

  fclose(fp);
}

void read_matrix(char *mat, int mat_sz) {
  FILE *fp = fopen("./dataset/input.data", "r");
  mat_sz = mat_sz * mat_sz;

  if(fp == NULL) {
    puts("Erro ao tentar abrir o arquivo");
    exit(EXIT_FAILURE);
  }

  fscanf(fp, "%*[^\n]\n");

  for(int i = 0; i < mat_sz; i++) {
    fscanf(fp, "%c ", mat + i);
  }

  fclose(fp);
}

void print_matrix(char *mat,
    bool *vis, int mat_sz) {
  for(int i = 0; i < mat_sz; i++) {
    for(int j = 0; j < mat_sz; j++) {
      int index = mat_sz * i + j;

      if(vis[index])
        printf(COLOR "%c " NO_COLOR, mat[index]);
      else
        printf("%c ", mat[index]);
    }
      putchar('\n');
  }
  putchar('\n');
}
