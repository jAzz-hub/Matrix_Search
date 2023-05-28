#include "bfs.h"

static const int dirH[4] = {1, 0, -1,  0};
static const int dirV[4] = {0, 1,  0, -1};

void BFS(char *mat, bool *vis, int mat_sz) {
  Queue q;
  QueueData data;

  QueueCreate(&q);
  QueuePush(&q, (QueueData){.x = 0, .y = 0});
  vis[0] = true;

  if(mat[0] == '*') {
    mat[0] = '1';
  }

  while(!isQueueEmpty(&q)) {
    data = (QueueData){.x = q.first->data.x,
                       .y = q.first->data.y};

    QueuePop(&q);

    for (int i = 0; i < 4; i++) {
      int adjx = data.x + dirH[i];
      int adjy = data.y + dirV[i];
      int index = mat_sz * adjy + adjx;

      if(adjx < 0 || adjx >= mat_sz
      || adjy < 0 || adjy >= mat_sz
      || vis[index]
      || mat[index] == '#')
        continue;

      if(mat[index] == '*') {
        mat[index] = '1';

        memset(vis + 1, false, mat_sz * mat_sz - 1);

        QueueClear(&q);
        QueuePush(&q, (QueueData){.x = 0, .y = 0});

        break;
      } else if(mat[index] == '?') {
        vis[index] = true;

        return;
      } else {
        QueuePush(&q, (QueueData){.x = adjx, .y = adjy});
        vis[mat_sz * adjy + adjx] = true;
      }
    }
  }
}
