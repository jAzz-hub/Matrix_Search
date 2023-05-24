#include "dfs.h"

void DFS(char *mat, bool *vis, int mat_sz) {
  const int dH[4] = {0, 1,  0, -1};
  const int dV[4] = {1, 0, -1,  0};
  Stack s;

  StackCreate(&s);
  StackPush(&s, (StackData){.x = 0, .y = 0});
 
  while (!isStackEmpty(&s)) {
    StackData data = s.top->data;
    int index = mat_sz * data.y + data.x;
    int i;
 
    vis[index] = true;
 
    for (i = 0; i < 4; i++) {
      int mX = data.x + dH[i];
      int mY = data.y + dV[i];

      index = mat_sz * mY + mX;

      if(mX < 0 || mX >= mat_sz
      || mY < 0 || mY >= mat_sz
      || vis[index]
      || mat[index] == '#') continue;

      if(mat[index] == '?') {
        vis[index] = true;
        return;
      } else if(mat[index] == '*') {
        mat[index] = '1';

        clear_boolean(vis, mat_sz);
        vis[0] = true;

        StackClear(&s);
        StackPush(&s, (StackData){.x = 0, .y = 0});

        break;
      }

      StackPush(&s, (StackData){.x = mX, .y = mY});
      break;
    }

    if(i == 4) {
      index = mat_sz * data.y + data.x;
      mat[index] = '#';
      StackPop(&s);
    }
  }
}
