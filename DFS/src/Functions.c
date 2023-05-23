#include "Functions.h"
#include "Stack.h"

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


Cord selectDirection(Tile **matrix,int size, Cord posAtual){
  // cima
  //Baixo
 if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
        Cord pos = {.y = 1 , .x = 0, .value = matrix[posAtual.y+1][posAtual.x].value};
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

  else if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
        Cord pos = {.y = 1 , .x = 0, .value = matrix[posAtual.y+1][posAtual.x].value};
        return pos;
    }
  }
  // baixo
  //Cima
  else if(posAtual.y-1 >= 0 && matrix[posAtual.y-1][posAtual.x].value != '#'){
    if(matrix[posAtual.y][posAtual.x].explored == false){
      Cord pos = {.y = -1, .x = 0, .value =  matrix[posAtual.y-1][posAtual.x].value};
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

  Cord pos = {.x = 0, .y = 0, .value = matrix[posAtual.y][posAtual.x].value};
  return pos;
}


void forbiddenWay(Tile **matrix, Cord *nowPosition, nodeStack *Stack, Cord *step, int size)
{
  //Erguendo parede e tornando o caminho conhecido:
  matrix[nowPosition->y][nowPosition->x].value = '#';
  matrix[nowPosition->y][nowPosition->x].explored = true;

  nowPosition->x = nowPosition->x - step->x;
  nowPosition->y = nowPosition->y - step->y;

  *step = selectDirection(matrix, size, *nowPosition);

  //Removendo nó da pilha:
  popNode(Stack);
}

/// @brief Decide o próximo passo 
/// @param matrix 
/// @param size 
/// @param posAtual 
/// @param passo 
/// @return 
bool proximoPasso(Tile **matrix, int size, Cord *posAtual, Cord passo, nodeStack *Stack)
{
  if(posAtual->y + passo.y >= 0 && posAtual->y + passo.y < size)
  {
    if(posAtual->x + passo.x >= 0 && posAtual->x + passo.x < size)
    {
      // olha se pode dar mais um passo na direção
      if(matrix[posAtual->y + passo.y][posAtual->x + passo.x].value != '#' || matrix[posAtual->y + passo.y][posAtual->x + passo.x].explored == true )
      {
        return true;
      }
      else
      {
        // printf("PASSEI AQUI %d %d",posAtual->y,posAtual->x);
        // //Pavimenta e tira um do laço;
        // forbiddenWay(matrix, posAtual, Stack, passo);
        return false;
      }
    }
  }
  return false;
}


void Reiniciar(Tile **matrix, nodeStack *Stack)
{
  while (!emptyStack(&*Stack))
  {
    matrix[Stack->Coordinate.y][Stack->Coordinate.x].explored = false;
    popNode(Stack);    
  }
}

void StuckInBeginning(Tile **matrix,nodeStack *Stack, Cord step, Cord nowPosition, int size)
{
  if((step.x == 0 && step.y == 0) && (nowPosition.x == 0 && nowPosition.y == 0) && (Stack->size==1))
  {
    matrix[nowPosition.y][nowPosition.x].value = '#';
    matrix[nowPosition.y][nowPosition.x].explored = true;
    popNode(Stack);
    
    printf("\n\nESTOU PRESO!\n");
    printf("\n\tObserve que o ponto de início possui paredes ou está cercado por elas\n ! VERIFIQUE O ARQUIVO DE ENTRADA !\n\n");
    printf("x = ponto inicial\n");
    printf("\t0   x %c %c\n", matrix[nowPosition.y][nowPosition.x+1].value, matrix[nowPosition.y][nowPosition.x+2].value);
    printf("\t1   %c %c %c\n",matrix[nowPosition.y+1][nowPosition.x].value, matrix[nowPosition.y+1][nowPosition.x+1].value, matrix[nowPosition.y+1][nowPosition.x+2].value);
    printf("\t2   %c %c %c\n",matrix[nowPosition.y+2][nowPosition.x].value, matrix[nowPosition.y+2][nowPosition.x+1].value, matrix[nowPosition.y+2][nowPosition.x+2].value);    
    exit(0);
  }
}

// /// @brief 
// /// @param matrix 
// /// @param step 
// /// @param nowPosition 
// /// @param size 
// /// @return 
// bool Wreck(Tile **matrix, Cord step, Cord posAtual, int size)
// {
//   printf("ENTREI AQUIIII");
//   if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
//     if(matrix[posAtual.y][posAtual.x].explored == false){
//         return false;
//     }
//   }
  
//   // direita
//   else if(posAtual.x+1 < size && matrix[posAtual.y][posAtual.x+1].value != '#'){
//     if(matrix[posAtual.y][posAtual.x].explored == false){
//       return false;
//     }
//   }

//   else if(posAtual.y+1 < size && matrix[posAtual.y+1][posAtual.x].value != '#'){
//     if(matrix[posAtual.y][posAtual.x].explored == false){
//         return false;
//     }
//   }
//   // baixo
//   //Cima
//   else if(posAtual.y-1 >= 0 && matrix[posAtual.y-1][posAtual.x].value != '#'){
//     if(matrix[posAtual.y][posAtual.x].explored == false){
//       return false;
//     }
//   }
//   // esquerda
//   else if(posAtual.x-1 >= 0 && matrix[posAtual.y][posAtual.x-1].value != '#'){
//     if(matrix[posAtual.y][posAtual.x].explored == false){
//       return false;
//     }
//   }

//   else
//   {    
//     printf("WWWNTREI AQUIIII");
//     matrix[posAtual.y][posAtual.x].value = '#';
//     matrix[posAtual.y][posAtual.x].explored = true;
//     posAtual.y = posAtual.y - step.x;
//     posAtual.x = posAtual.x - step.y;    
//     return true;
//   }
// }

//Verificando se não há caminhos possíveis ao redor:
bool noWay(Tile **matrix, Cord nowPosition, int size)
{
  bool N,S,W,E = false;
  bool rightBorder = ((nowPosition.x+1) == size);
  bool upBorder = (nowPosition.y-1 ==  size);
  bool downBorder = (nowPosition.y+1 == size);
  bool leftBorder = (nowPosition.x-1 == size);

  if(upBorder)
    S = matrix[nowPosition.y+1][nowPosition.x].value == '#' || matrix[nowPosition.y+1][nowPosition.x].explored == true ;

  if(rightBorder)
    E = matrix[nowPosition.y][nowPosition.x+1].value == '#' || matrix[nowPosition.y][nowPosition.x+1].explored == true ;
    
  if(leftBorder)
    W = matrix[nowPosition.y][nowPosition.x-1].value == '#' || matrix[nowPosition.y][nowPosition.x-1].explored == true ;
  
  if(downBorder)
    N = matrix[nowPosition.y-1][nowPosition.x].value == '#' || matrix[nowPosition.y-1][nowPosition.x].explored == true ;
  

  if( (!S || downBorder) && (!E || rightBorder)  && (!W || leftBorder) )
  {
    return true;
    
  }

  else if ((!S || downBorder) && (!N || upBorder)  && (!E || rightBorder) )
  {
    
    return true;
  }

  
  else if ((!S || downBorder) && (!N || upBorder)  && (!W || leftBorder) )
  {
    return true;
  }

  
  else if ((!E || downBorder) && (!N || upBorder)  && (!W || leftBorder) )
  {
    return true;
  }
  

  else
    return false;
    
}

void Percurso(Tile **matrix, int size, nodeStack *Stack)
{
  //Crio a posição do agora:
  Cord nowPosition = {.x = 0, .y = 0};
  Stack->top->Coordinate.value = matrix[Stack->Coordinate.y][Stack->Coordinate.x].value;

  Cord step;
  Cord prevStep;
  int counter = 0;

  //Enquanto não alcançar a vitória:
  while(Stack->Coordinate.value != '!')
  { 
    
    //O possível passo
    step = selectDirection(matrix,size,nowPosition);
    
    printf("\n \t%d \t %d  \t\t %d-%d \n", step.y, step.x, nowPosition.y, nowPosition.x);
    printf("\t0   x %c %c\n", matrix[nowPosition.y][nowPosition.x+1].value, matrix[nowPosition.y][nowPosition.x+2].value);
    printf("\t1   %c %c %c\n",matrix[nowPosition.y+1][nowPosition.x].value, matrix[nowPosition.y+1][nowPosition.x+1].value, matrix[nowPosition.y+1][nowPosition.x+2].value);
    printf("\t2   %c %c %c\n",matrix[nowPosition.y+2][nowPosition.x].value, matrix[nowPosition.y+2][nowPosition.x+1].value, matrix[nowPosition.y+2][nowPosition.x+2].value);
    
    StuckInBeginning(matrix, Stack, step, nowPosition,size);
    
   // verifica se está preso (voltando de onde veio)
    if(step.x == (prevStep.x * -1) && step.y == (prevStep.y * -1)){
      forbiddenWay(matrix, &nowPosition, Stack, &step, size);
    }
            
      if(counter == 20)
      {
        printf("alooo");
        showNodes(Stack);
        exit(0);
      }

      unsigned char top = matrix[nowPosition.x][nowPosition.y].value;

      //Enquanto houver a possibilidade de se caminhar para uma única direção:
      while(proximoPasso(matrix,size,&nowPosition,step, Stack) && top != '!')
      {

        counter+=1;

        /*ATENÇÃO!! TENTANDO DEBUGAR*/
             
        if(counter==10)
        {
          showNodes(Stack);
          // printf("%d %c %d %d -- %d",(matrix[nowPosition.y][nowPosition.x].explored), matrix[nowPosition.y][nowPosition.x].value, nowPosition.y, nowPosition.x, Stack->size);
          exit(0);
        }

          // usar a função forbiddenWay quando vc estiver cercado de paredes, antes de dar o próximo passo

    /*    if(noWay(matrix, nowPosition,size)){
          forbiddenWay(matrix, &nowPosition, Stack, &step, size);
          printf("RESULTADO: x: %d  y: %d  STEP: x: %d y: %d", nowPosition.y, nowPosition.x, step.y , step.x);
          exit(0);
        }*/

        if (counter>=3)
        {
          printf("explorado? %d valor: %c [x : %d y : %d ]-- %d",(matrix[nowPosition.y][nowPosition.x].explored), matrix[nowPosition.y][nowPosition.x].value, nowPosition.y, nowPosition.x, Stack->size);
          
        }
        // usar a função forbiddenWay quando vc estiver cercado de paredes, antes de dar o próximo passo
        nowPosition.x += step.x;
        nowPosition.y += step.y;

        //Verifica se alguém bateu em uma parede enquanto corria:
        ///matrix - tem a posição de batida emparedada;
        ///Stack - não meche!!
        ///step - vai ser decrescido de nowPosition;
        ///nowPosition -= step;
        

        unsigned char top = matrix[nowPosition.x][nowPosition.y].value;
       
        if(matrix[nowPosition.y][nowPosition.x].explored == false)
        {

          
          if(matrix[nowPosition.y][nowPosition.x].value == '*')
          {
            matrix[nowPosition.y][nowPosition.x].value = '1';
            printf("EXITEI!! %d", counter);

            Reiniciar(matrix, Stack);
            break;
            
            //começa do inicio
            //pilha.clean()?
            //Desempilhar()
              //Desempilhar exclui todos os valores da pilha e torna essas casas inexploradas:
          }
          else if(matrix[nowPosition.y][nowPosition.x].value != '!')
          {
            matrix[nowPosition.y][nowPosition.x].explored = true;
            
            pushNode(Stack, nowPosition);
            printf("\nEXITEI!!2 %d\n", counter);
            
          }          
          else
          {
            printf("EXITEI!!3 %d", counter);
            
            matrix[nowPosition.y][nowPosition.x].explored = true;
            pushNode(Stack, nowPosition);
            //Emitir relatório;
            exit(0);
          }

        }

        else
        {
          printf("111EXITEI!!");
          false;
        }
      
    }
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
