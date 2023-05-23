#include "Stack.h"

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
