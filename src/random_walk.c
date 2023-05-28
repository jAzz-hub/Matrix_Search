#include "Maze.h"
#include <time.h>

static const int dirH[4] = {1, 0, -1,  0};
static const int dirV[4] = {0, 1,  0, -1};

typedef struct player {
  int x, y;
} Player;
 
void RAND(char *mat, bool *vis, int mat_sz) {
  srand(time(NULL));
  Player p = (Player){.x = 0, .y = 0};
  int adjx, adjy, index = 0;

  while(mat[mat_sz * p.y + p.x] != '?') {
    do {
      int direction = rand() % 4;

      adjx = p.x + dirH[direction];
      adjy = p.y + dirV[direction];
      index = mat_sz * adjy + adjx;
    } while(adjx < 0 || adjx >= mat_sz
         || adjy < 0 || adjy >= mat_sz
         || mat[index] == '#');

    if(mat[index] == '*') {
      mat[index] = '1';
      memset(vis + 1, false, mat_sz * mat_sz - 1);
      p = (Player){.x = 0, .y = 0};
    } else {
      p = (Player){.x = adjx, .y = adjy};
      vis[index] = true;
    }
  }
}
