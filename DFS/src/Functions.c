#include "Functions.h"

/// @brief Cria uma pilha vazia
/// @param firstNode Variável do tipo nó de pilha que será configurada inicialmente como uma pilha vazia
void stackGenerator(nodeStack *firstNode)
{
  firstNode->base = (nodeStack*)malloc(sizeof(nodeStack));
  firstNode->base->after = NULL;
  firstNode->top = firstNode->base;
  firstNode->size = 0;
}

/// @brief Cria um nó para a pilha
/// @param Coordinate Coordenada à ser gravada no nó
/// @return Retorna um nó com Coordinate
nodeStack *nodeGenerator(Cord Coordinate)
{
  nodeStack *Node = (nodeStack*)malloc(sizeof(nodeStack));
  Node->before = NULL;
  Node->after = NULL;
  Node->Coordinate = Coordinate;
  return Node;
}

bool emptyStack(nodeStack *Node)
{
  return (Node->base == Node->top) || Node->size==0; 
}

void pushNode(nodeStack *previousNode, Cord newNodeCoordinates)
{
  nodeStack *newNode = nodeGenerator(newNodeCoordinates);

  if(emptyStack(&*previousNode))
  {
    previousNode->base->after = newNode;
    previousNode->top = newNode;
    previousNode->top->after = NULL;
  }

  else
  {
    newNode->before = previousNode->top;
    previousNode->top->after = newNode;
    previousNode->top = newNode;
    previousNode->top->after = NULL;
  }

  previousNode->size++;
  previousNode->top->size++;
  //Verificar se essa linha está certa:
}

void popNode(nodeStack *Node)
{
  
    //O ponto do topo será igual ao penúltimo ponto empilhado:
  if(!emptyStack(Node))
    {
      nodeStack *erasedNode = Node->top;
      Node->top = Node->top->before;
      free(erasedNode);
      
      if(Node->top != NULL)
      {
        Node->top->after = NULL;
      }
      
      Node->size-=1;
    }
  
  
  else
  {
    printf("A pilha está vazia!!");
  }
}

void showNodes(nodeStack *Node)
{
  if(emptyStack(Node))
    return;
  else
  {
    nodeStack *nodeViewer = Node->top;
    printf("\n");
    unsigned short int counter = Node->size;

    
    while (nodeViewer!=NULL)
    {
      counter-=1;
      printf(" Node %d, \t x: %d | y: %d\n",counter ,nodeViewer->Coordinate.x, nodeViewer->Coordinate.y);
      nodeViewer = nodeViewer->before;
    }
  }
}


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

/// @brief Decide o próximo passo 
/// @param matrix 
/// @param size 
/// @param posAtual 
/// @param passo 
/// @return 
bool proximoPasso(Tile **matrix, int size, Cord posAtual, Cord passo)
{
  if(posAtual.y + passo.y >= 0 && posAtual.y + passo.y < size)
  {
    if(posAtual.x + passo.x >= 0 && posAtual.x + passo.x < size)
    {
      // olha se pode dar mais um passo na direção
      if(matrix[posAtual.y + passo.y][posAtual.x + passo.x].value != '#')
      {
        return true;
      }
      else
        return false;
    }
  }
}

Cord selectDirection(Tile **matrix,int size, Cord posAtual){
  // baixo
  if(posAtual.y-1 >= 0 && matrix[posAtual.y-1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y = -1, .x = 0, .value =  matrix[posAtual.y-1][posAtual.x].value};
      return pos;
    }
  }
  // direita
  else if(posAtual.x+1 < size && matrix[posAtual.y][posAtual.x+1].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y =0, .x = 1, .value = matrix[posAtual.y][posAtual.x+1].value};
      return pos;
    }
  }
  // cima
  else if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
        Cord pos = {.y = 1 , .x = 0, .value = matrix[posAtual.y+1][posAtual.x].value};
        return pos;
    }
  }
  // esquerda
  else if(posAtual.x-1 >= 0 && matrix[posAtual.y][posAtual.x-1].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y = 0 , .x = -1, .value = matrix[posAtual.y][posAtual.x-1].value};
      return pos;
    }
  }

  Cord pos = {.x = 0, .y = 0, .value = matrix[0][0].value};
  return pos;
}

void Percurso(Tile **matrix, int size, nodeStack *Stack)
{
  
  //Tem problema transformar step e now position na mesma variável?
  
  Cord nowPosition = {.x = 0, .y = 0};

  
  Stack->top->Coordinate.value = matrix[Stack->Coordinate.y][Stack->Coordinate.x].value;
  
 
  printf("\n\t%d---%d---%c\n",Stack->top->Coordinate.x, Stack->top->Coordinate.y, Stack->top->Coordinate.value);
  
  while(Stack->Coordinate.value != '!')
  {
    int counter = 0;
    popNode(Stack);
    

    Cord step;
    step = selectDirection(matrix,size,nowPosition);

    
    // verifica se está preso:
    if(step.x == 0 && step.y == 0){
      
      matrix[nowPosition.y][nowPosition.x].value = '#';

      popNode(Stack);

      step = selectDirection(matrix,size,nowPosition);
      
    }
    else
    {
      
  
      unsigned char top = matrix[nowPosition.x][nowPosition.y].value;

      //Enquanto houver a possibilidade de se caminhar para uma única direção:
      while(proximoPasso(matrix,size,nowPosition,step) && top != '!')
      {

        counter+=1;


        /*ATENÇÃO!! TENTANDO DEBUGAR*/
        if(counter==9)
        {
          showNodes(Stack);
          printf("%d %c %d %d",(matrix[nowPosition.y][nowPosition.x].explored), matrix[nowPosition.y][nowPosition.x].value, nowPosition.y, nowPosition.x);
          exit(0);
          
        }      
             
        nowPosition.x += step.x;
        nowPosition.y += step.y;
        unsigned char top = matrix[nowPosition.x][nowPosition.y].value;
       
        if(matrix[nowPosition.y][nowPosition.x].explored == false)
        {

          
          if(matrix[nowPosition.y][nowPosition.x].value == '*')
          {
            matrix[nowPosition.y][nowPosition.x].value = '1';
            printf("EXITEI!! %d", counter);
            exit(0);
            //começa do inicio
            //pilha.clean()?
            //Desempilhar()
              //Desempilhar exclui todos os valores da pilha e torna essas casas inexploradas:
          }
          else if(matrix[nowPosition.y][nowPosition.x].value != '!')
          {
            matrix[nowPosition.y][nowPosition.x].explored == true;
            
            pushNode(Stack, nowPosition);
            printf("\nEXITEI!!2 %d\n", counter);
            
          }          
          else
          {
            printf("EXITEI!!3 %d", counter);
            exit(0);
            matrix[nowPosition.y][nowPosition.x].explored == true;
            pushNode(Stack, nowPosition);
            //Emitir relatório;
            exit(0);
          }

        }

        else
        {
          printf("EXITEI!!");
          false;
          exit(0);
        }
      }
    }

    // passoAnterior = passo;

  }
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
  
  //Criando a pilha com a primeira casa da matriz:
  Cord FirstPosition = {.x = 0, .y = 0};

  //Variável da pilha:
  nodeStack Stack;
  stackGenerator(&Stack);

  //Adicionando Nó com primeira posição:
  pushNode(&Stack, FirstPosition);

    
   

  Percurso(matrix, size, &Stack);
}
