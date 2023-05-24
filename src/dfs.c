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
 
    //printf("%c ", mat[index]);
 
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
  //putchar('\n');
}
 
// Driver Code
//int main()
//{
//  clock_t start, end;
//  char *mat;
//  bool *vis;
//  int mat_sz;
// 
//  start = clock();
//
//  read_size(&mat_sz);
//
//  mat = (char *)malloc(mat_sz * mat_sz * sizeof(char));
//  vis = (bool *)malloc(mat_sz * mat_sz * sizeof(bool));
//
//  read_matrix(mat, mat_sz);
//  clear_boolean(vis, mat_sz);
//  print_matrix(mat, mat_sz);
//
//  DFS(mat, mat_sz, vis);
//
//  print_matrix(mat, mat_sz);
//  print_boolean(vis, mat_sz);
//
//  puts("O erro não está aqui"); fflush(stdout); // scribble
//  free(mat);
//  free(vis);
//  puts("O erro não está aqui"); fflush(stdout); // scribble
// 
//  end = clock();
//
//  printf("Tempo de execução: %f ms\n",
//      ((double)(end - start))/CLOCKS_PER_SEC*1000);
//
//  return 0;
//}
