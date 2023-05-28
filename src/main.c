#include "Maze.h"
#include "Queue.h"
#include "Stack.h"
#include "random_walk.h"
#include "bfs.h"
#include "dfs.h"
 
int main()
{
  clock_t start, end;
  char *mat;
  bool *vis;
  int mat_sz;

  read_size(&mat_sz);
  mat = (char *)malloc(mat_sz * mat_sz * sizeof(char));
  vis = (bool *)malloc(mat_sz * mat_sz * sizeof(bool));

  start = clock();

  printf("Caminhamento aleatório\n\n");
  read_matrix(mat, mat_sz);
  memset(vis, false, mat_sz * mat_sz);
  RAND(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  end = clock();
  printf("Tempo de execução : %.3f ms\n",
      ((double)(end - start))/CLOCKS_PER_SEC*1000);


  start = clock();

  printf("\nCaminhamento DFS\n\n");
  read_matrix(mat, mat_sz);
  memset(vis, false, mat_sz * mat_sz);
  DFS(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  end = clock();
  printf("Tempo de execução : %.3f ms\n",
      ((double)(end - start))/CLOCKS_PER_SEC*1000);


  start = clock();

  printf("\nCaminhamento BFS\n\n");
  read_matrix(mat, mat_sz);
  memset(vis, false, mat_sz * mat_sz);
  BFS(mat, vis, mat_sz);
  print_matrix(mat, vis, mat_sz);

  end = clock();
  printf("Tempo de execução : %.3f ms\n",
      ((double)(end - start))/CLOCKS_PER_SEC*1000);

  free(mat);
  free(vis);
 
  return 0;
}
