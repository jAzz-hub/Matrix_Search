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
    } else {
      p = (Player){.x = mX, .y = mY};
    }
      vis[index] = true;
  }
}
