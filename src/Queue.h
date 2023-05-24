#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct QueueData {
  int x, y;
} QueueData;

typedef struct queue_block {
  QueueData data;
  struct queue_block *next;
} QueueBlock;

typedef struct queue {
  QueueBlock *first;
  QueueBlock *last;
} Queue;

void QueueCreate(Queue *q);
void QueuePush(Queue *q, QueueData data);
void QueuePop(Queue *q);
bool isQueueEmpty(Queue *q);
void QueueClear(Queue *q);
void QueuePrint(Queue *q);

#endif
