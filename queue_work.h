#ifndef QUEUE_WORK_H
#define QUEUE_WORK_H

#include <stdio.h>
#include <malloc.h>

typedef struct TQueueNode {
    int value;
    struct TQueueNode *next;
} TQueueNode;

typedef struct TQueue {
    TQueueNode *first, *last;
} TQueue;

void enqueue(TQueue *q, int value);
int dequeue(TQueue *q);

void queue_print(TQueue q);

void queue_free(TQueue *q);

#endif // QUEUE_WORK_H
