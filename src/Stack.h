#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_data {
  int x, y;
} StackData;
 
typedef struct stack_block {
  StackData data;
  struct stack_block *next;
} StackBlock;

typedef struct stack {
  StackBlock *top;
} Stack;

void StackCreate(Stack *s);
void StackPush(Stack *s, StackData data);
void StackPop(Stack *s);
bool isStackEmpty(Stack *s);
void StackClear(Stack *s);
void StackPrint(Stack *s);

#endif
