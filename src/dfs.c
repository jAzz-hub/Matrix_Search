#include "dfs.h"

static const int dirH[4] = {0, 1,  0, -1};
static const int dirV[4] = {1, 0, -1,  0};

void DFS(char *mat, bool *vis, int mat_sz) {
  Stack s;

  StackCreate(&s);
  StackPush(&s, (StackData){.x = 0, .y = 0});
 
  if(mat[0] == '*') {
    mat[0] = '1';
  }

  while (!isStackEmpty(&s)) {
    StackData data = s.top->data;
    int index = mat_sz * data.y + data.x;
    int i;
 
    vis[index] = true;
 
    for (i = 0; i < 4; i++) {
      int adjx = data.x + dirH[i];
      int adjy = data.y + dirV[i];

      index = mat_sz * adjy + adjx;

      if(adjx < 0 || adjx >= mat_sz
      || adjy < 0 || adjy >= mat_sz
      || vis[index]
      || mat[index] == '#') continue;

      if(mat[index] == '?') {
        vis[index] = true;
        return;
      } else if(mat[index] == '*') {
        mat[index] = '1';

        memset(vis + 1, false, mat_sz * mat_sz - 1);

        StackClear(&s);
        StackPush(&s, (StackData){.x = 0, .y = 0});

        break;
      }

      StackPush(&s, (StackData){.x = adjx, .y = adjy});
      break;
    }

    if(i == 4) {
      index = mat_sz * data.y + data.x;
      mat[index] = '#';
      StackPop(&s);
    }
  }
}
