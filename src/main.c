#include "Maze.h"
#include "Queue.h"
#include "Stack.h"
#include "random_walk.h"
#include "bfs.h"
#include "dfs.h"

#include <time.h>
 
int main()
{
  clock_t start, end;
  char *mat;
  bool *vis;
  int mat_sz;
 
  start = clock();

  read_size(&mat_sz);
  mat = (char *)malloc(mat_sz * mat_sz * sizeof(char));
  vis = (bool *)malloc(mat_sz * mat_sz * sizeof(bool));

  printf("Caminhamento aleatório\n\n");
  read_matrix(mat, mat_sz);
  clear_boolean(vis, mat_sz);
  RAND(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  printf("Caminhamento DFS\n\n");
  read_matrix(mat, mat_sz);
  clear_boolean(vis, mat_sz);
  DFS(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  printf("Caminhamento BFS\n\n");
  read_matrix(mat, mat_sz);
  clear_boolean(vis, mat_sz);
  BFS(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  free(mat);
  free(vis);
 
  end = clock();

  printf("Tempo de execução: %f ms\n",
      ((double)(end - start))/CLOCKS_PER_SEC*1000);

  return 0;
}
