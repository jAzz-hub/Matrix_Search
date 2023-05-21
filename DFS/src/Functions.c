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
Tile **allocateMatrix(int size) {
  Tile **matrix = malloc(sizeof(Tile *) * (size));

  for (int i = 0; i <= size; i++) {
    matrix[i] = malloc(sizeof(Tile) * size);
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
void MatrixScanner(Tile **MatrixScoped, int size)
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
void LineRecorder(Tile **matrix, int size, char *line, int row)
{
  LineCleaner(size, line);
  for(int column = 0; column<size; column++)
  {
    matrix[row][column].value = line[column];
  }

}

/// @brief Armazena conteúdo lido de input.data em uma matriz
/// @param matrix Matriz que recebe o conteúdo lido
/// @param size Tamanho da matriz
/// @param input ponteiro do arquivo input
void MatrixRecorder(Tile **matrix, int size, FILE *input)
{
  char *matrixLine;
  for(unsigned short int i=0; i<=size; i++){
    //Lê uma linha e grava ela na Matriz:
    char line[(size*3)];
    fgets(line, sizeof(line), input);  
    LineRecorder(matrix, size, line, i);
  }
}

bool proximoPasso(Tile **matrix, int size, Cord posAtual, Cord passo){
  if(posAtual.y + passo.y >= 0 && posAtual.y + passo.y < size){
    if(posAtual.x + passo.x >= 0 && posAtual.x + passo.x < size){
      // olha se pose dar mais um passo na direção
      if(matrix[posAtual.y + passo.y][posAtual.x + passo.x].value != '#'){
        return true;
      }
    }
  }
  
  return false;
}

Cord selectDirection(Tile **matrix,int size, Cord posAtual){
  // baixo
  if(posAtual.y-1 >= 0 && matrix[posAtual.y-1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y = -1, .x = 0};
      return pos;
    }
  }
  // direita
  else if(posAtual.x+1 < size && matrix[posAtual.y][posAtual.x+1].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y =0, .x = 1};
      return pos;
    }
  }
  // cima
  else if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
        Cord pos = {.y = 1 , .x = 0};
        return pos;
    }
  }
  // esquerda
  else if(posAtual.x-1 >= 0 && matrix[posAtual.y][posAtual.x-1].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y = 0 , .x = -1};
      return pos;
    }
  }

  Cord pos = {.x = 0, .y = 0};
  return pos;
}

void Percurso(Tile **matrix, int size){
  Cord posAtual = {.x = 0, .y = 0};
  Cord passoAnterior = {.x = 0, .y = 0};

  /*
  while(pilha.top() != '!'){
    pilha.pop();

    Cord passo;
    passo = selectDirection(matrix,size,posAtual);

    // verifica se está preso (voltando de onde veio)
    if(passo.x == (passoAnterior.x * -1) && passo.y == (passoAnterior.y * -1){
      matrix[posAtual.y][posAtual.x] = '#';
      pilha.pop(); 
    }

    while(proximoPasso(matrix,size,posAtual,passo) && pilha.top().value != '!'){
      posAtual.x += passo.x;
      posAtual.y += passo.y;
      
      if(matrix[posAtual.y][posAtual.x] == '*'){
        //começa do inicio
        //pilha.clean()?
      }

      if(matrix[posAtual.y][posAtual.x].explored == false){
        matrix[posAtual.y][posAtual.x].explored == true;
        pilha.add(matrix[posAtual.y][posAtual.x]);
      }
    }

    passoAnterior = passo;

  }*/
}

/// @brief Realiza uma Deep First Search na matriz contida em input.data 
/// @param size Tamanho da matriz contida em input.data
void StartDFS(int size, FILE *input)
{
  //Criar matriz de tamanho size:
  Tile **matrix = allocateMatrix(size);

  //Lendo arquivo e gravando na variável matrix:
  MatrixRecorder(matrix, size,input);
  fclose(input);

  //Mostrando a matriz lida:
  MatrixScanner(matrix,size);
  
  Percurso(matrix, size);
}
