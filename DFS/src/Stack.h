#include "Structures.h"

typedef struct nodeStack
{
  Cord Coordinate;
  struct nodeStack *after, *before, *base, *top;
  size_t size;
} nodeStack;


void stackGenerator(nodeStack *firstNode);

nodeStack *nodeGenerator(Cord Coordinate);

void pushNode(nodeStack *previousNode, Cord newNodeCoordinates);

bool emptyStack(nodeStack *Node);

void popNode(nodeStack *Node);

void showNodes(nodeStack *Node);
