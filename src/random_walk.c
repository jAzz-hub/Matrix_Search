#include "Maze.h"
#include <time.h>

typedef struct player {
  int x, y;
} Player;
 
void RAND(char *mat, bool *vis, int mat_sz) {
  srand(time(NULL));
  const int dH[4] = {1, 0, -1,  0};
  const int dV[4] = {0, 1,  0, -1};
  Player p = (Player){.x = 0, .y = 0};
  int mX, mY, index = 0;

  vis[0] = true;

  while(mat[mat_sz * p.y + p.x] != '?') {
    //printf("%c ", mat[index]);

    do {
      int direction = rand() % 4;

      mX = p.x + dH[direction];
      mY = p.y + dV[direction];
      index = mat_sz * mY + mX;
    } while(mX < 0 || mX >= mat_sz
         || mY < 0 || mY >= mat_sz
         || mat[index] == '#');

    if(mat[index] == '*') {
      mat[index] = '1';
      clear_boolean(vis, mat_sz);
      p = (Player){.x = 0, .y = 0};
      //puts("*");
    } else {
      p = (Player){.x = mX, .y = mY};
    }
      vis[index] = true;
  }
}

// int main()
// {
//   clock_t start, end;
//   char *mat;
//   bool *vis;
//   int mat_sz;
//  
//   start = clock();
// 
//   read_size(&mat_sz);
//   mat = (char *)malloc(mat_sz * mat_sz * sizeof(char));
//   vis = (bool *)malloc(mat_sz * mat_sz * sizeof(bool));
//   read_matrix(mat, mat_sz);
//   print_matrix(mat, mat_sz);
// 
//   clear_boolean(vis, mat_sz);
//   RAND(mat, mat_sz, vis);
//   putchar('\n');
//   print_boolean(vis, mat_sz);
// 
//   free(mat);
//   free(vis);
//  
//   end = clock();
// 
//   printf("Tempo de execução: %f ms\n",
//       ((double)(end - start))/CLOCKS_PER_SEC*1000);
// 
//   return 0;
// }
