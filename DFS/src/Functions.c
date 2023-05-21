#include "Functions.h"

/// @brief Lê a primeira linha do arquivo input.data
/// @return  O número de matrizes que serão lidas e o tamanho destas matrizes
FILE *openInput(FILE *f, int *size, int *n) {
  char fileName[] = "dataset/input.data";


  f = fopen(fileName, "r");
  if (f == NULL) {
    fprintf(stderr,"Error ao abrir arquivo\n");
    exit(1);
  }

  char buffer[80];
  fgets(buffer, 80, f);
  sscanf(buffer, "%d %*d %d", size, n);
  return f;
}

/// @brief Cria uma matriz NxN de acordo com o parâmetro size
/// @param size tamanho da matriz
/// @return retorna uma matriz de tamanho size
tile **allocateMatrix(int size) {
  tile **matrix = malloc(sizeof(tile *) * (size));

  for (int i = 0; i <= size; i++) {
    matrix[i] = malloc(sizeof(tile) * size);
  }

  return matrix;
}

/*
   
  Getúlio e Rafael essas linhas abaixo são pseudocódigo, se forem alterar, comuniquem ao grupo 1º pfvr

    Tasks:
    [X] - Ler o arquivo e armazenar a matriz.
    [ ] - Verificar casas adjascentes para caminhar.
    [ ] - Iniciar percurso.
    [ ] - Iniciar pesquisa em profundidade.
    [ ] - Adicionar paredes quando esbarrar em obstáculo.
    [ ] - Emitir relatório quando encontrar a interrogação no meio da matriz.
*/

// percurso()
// {
//     #Direções Possíveis x+1(direita),x-1(esquerda) ou y-1(subir),y+1(descer):
    
//     verifica as direções:
//         só anda para direções na memória.
//             prioriza na seguinte ordem: baixo, direita, cima, esquerda.
    
//    while(próximo_passo() == true) 
//         Passo_Busca_Profundidade();
    
//     if Verifica_Redondezas(atual);
//         Troca avanço;
//     else
//         while(Verifica_Redondezas == false)
//             pop na pilha
//             matrix[Direção.y + atual.y][Direção.x + atual.x] = '#';
        
    
//     Matrix[Direção.y + atual.y][Direção.x + atual.x] = '#';
//     if perigo{
//         volta no começo
//     }
        
//     dá 1 passo
// }



// ///
// Passo_Busca_Profundidade(Coordenada *Posição_atual,Coordenada Direção)
// {
    
//         posição atual.x+= Direção.x
//         posição atual.y+= Direção.y
//         pega a posição atual armazena na pilha
    
//   }  

// Passo_Busca_Largura()
// {
//     pega a posição atual
// }


// main()
// {
//     lê arquivo e obtem matriz gigante em variável
    
//     iniciar percurso
    
//     percurso();
    
// }

/// @brief Mostra toodos os elementos contidos em uma matriz
/// @param MatrixScoped Matriz alvo
/// @param size Tamanho da matriz
void MatrixScanner(tile **MatrixScoped, int size)
{
  for(short int scannerRow = 0; scannerRow<size; scannerRow++)
  {
    for(short int scannerCol = 0; scannerCol<size;scannerCol++)
    {
      printf("%c ",MatrixScoped[scannerRow][scannerCol].value);
    }
    printf("\n");
  }
}

/// @brief Remove os caracteres ` ` e `\n` de uma string.
/// @param size Ordem da matriz contida no arquivo input.data
/// @param line Linha que sofrerá modificações.
void LineCleaner(int size, char *line)
{
  char *token;
  char *odd = " \n";
  char result[(size*3)-20];
  result[0] = '\0';
  
  token = strtok(line, odd);
  while (token!=NULL)
  {
    
    strcat(result, token);
    token = strtok(NULL, odd);
  }

  
  strcpy(line, result);
}

/// @brief Armazena uma linha lida do arquivo input.data em uma matriz
/// @param matrix Matriz onde as linhas serão armazenadas
/// @param size Tamanho da Matriz
/// @param line Linha lida do arquivo input.data
/// @param row Número da linha lida, será sempre menor ou igual a size
void LineRecorder(tile **matrix, int size, char *line, int row)
{
  LineCleaner(size, line);
  // printf("%s",line);
  for(int column = 0; column<size; column++)
  {
    matrix[row][column].value = line[column];
  }

}

/// @brief Armazena conteúdo lido de input.data em uma matriz
/// @param matrix Matriz que recebe o conteúdo lido
/// @param size Tamanho da matriz
/// @param input referência ao ponteiro do arquivo input
void MatrixRecorder(tile **matrix, int size, FILE *input)
{
  char *matrixLine;
  for(unsigned short int i=0; i<=size; i++){
    //Lê uma linha e grava ela na Matriz:
    char line[(size*3)];
    fgets(line, sizeof(line), input);  
    LineRecorder(matrix, size, line, i);
  }
}

/// @brief Realiza uma Deep First Search na matriz contida em input.data 
/// @param size Tamanho da matriz contida em input.data
void StartDFS(int size, FILE *input)
{
  //Criar matriz de tamanho size:
  tile **matrix = allocateMatrix(size);

  //Lendo arquivo e gravando na variável matrix:
  MatrixRecorder(matrix, size,input);
  fclose(input);

  //Mostrando a matriz lida:
  MatrixScanner(matrix,size);
  
}