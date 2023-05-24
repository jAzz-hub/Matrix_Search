#include "Queue.h"

void QueueCreate(Queue *q) {
  q->first = NULL;
}

void QueuePush(Queue *q, QueueData data) {
  QueueBlock *new_node = (QueueBlock *)malloc(sizeof(QueueBlock));

  new_node->data = data;
  new_node->next = NULL;

  if(!q->first) {
    q->first = new_node;
    q->last = new_node;
    return;
  }

  q->last->next = new_node;
  q->last = new_node;
}

void QueuePop(Queue *q) {
  if(!q->first) return;

  QueueBlock *rm = q->first;

  if(!q->last->next) q->last->next = NULL;
  q->first = q->first->next;
  free(rm);
}

bool isQueueEmpty(Queue *q) {
  return !q->first;
}

void QueueClear(Queue *q) {
  while(q->first) {
    QueueBlock *rm = q->first;

    q->first = q->first->next;
    free(rm);
  }

  q->last = NULL;
}
