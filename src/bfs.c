#include "bfs.h"

void BFS(char *mat, bool *vis, int mat_sz) {
  const int dH[4] = {1, 0, -1,  0};
  const int dV[4] = {0, 1,  0, -1};
  Queue q;
  QueueData data;

  QueueCreate(&q);
  QueuePush(&q, (QueueData){.x = 0, .y = 0});
  vis[0] = true;

  while(!isQueueEmpty(&q)) {
    data = (QueueData){.x = q.first->data.x,
                       .y = q.first->data.y};

    QueuePop(&q);

    //printf("%c ", mat[mat_sz * data.y + data.x]);

    // Go to the adjacent cells
    for (int i = 0; i < 4; i++) {
      int mX = data.x + dH[i];
      int mY = data.y + dV[i];
      int index = mat_sz * mY + mX;

      if(mX < 0 || mX >= mat_sz
      || mY < 0 || mY >= mat_sz
      || vis[index]
      || mat[index] == '#')
        continue;

      if(mat[index] == '*') {
        //puts("*");

        mat[index] = '1';

        clear_boolean(vis, mat_sz);
        vis[0] = true;

        QueueClear(&q);
        QueuePush(&q, (QueueData){.x = 0, .y = 0});

        break;
      } else if(mat[index] == '?') {
        //puts("?\n\nO objetivo foi encontrado!\n");
        vis[index] = true;

        return;
      } else {
        QueuePush(&q, (QueueData){.x = mX, .y = mY});
        vis[mat_sz * mY + mX] = true;
      }
    }
  }
  //puts("\nNão foi possível encontrar o objetivo");
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
//   clear_boolean(vis, mat_sz);
//   print_matrix(mat, mat_sz);
//   BFS(mat, mat_sz, vis);
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
