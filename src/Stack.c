#include "Stack.h"

void StackCreate(Stack *s) {
  s->top = NULL;
}

void StackPush(Stack *s, StackData data) {
  StackBlock *new_node =
    (StackBlock *)malloc(sizeof(StackBlock));

  new_node->data = data;
  new_node->next = s->top;
  s->top = new_node;
}

void StackPop(Stack *s) {
  if(!s->top) return;

  StackBlock *rm = s->top;

  s->top = s->top->next;
  free(rm);
}

bool isStackEmpty(Stack *s) {
  return !s->top;
}

void StackClear(Stack *s) {
  while(s->top) {
    StackBlock *rm = s->top;

    s->top = s->top->next;
    free(rm);
  }
}

// void StackPrint(Stack *s) {
//   if(!s->top) {
//     puts("A pilha está vazia");
//     return;
//   }
// 
//   StackBlock *tmp = s->top;
// 
//   puts("Imprimindo a pilha:\n"
//        "x\ty");
// 
//   while(tmp) {
//     printf("%d\t%d\n",
//         tmp->data.x, tmp->data.y);
//     tmp = tmp->next;
//   }
// }
