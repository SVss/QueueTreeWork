#include "queue_work.h"
#include "p_error.h"

TQueueNode *new_q_node(int value) {
    TQueueNode *result = (TQueueNode*)malloc(sizeof(TQueueNode) );
    result ->next = NULL;
    result ->value = value;

    return result;
}   /* new_node */


void enqueue(TQueue *q, int value) {
    if ((*q).last != NULL) {
        (*q).last->next = new_q_node(value);
        (*q).last = (*q).last->next;
    } else {
        (*q).first = new_q_node(value);
        (*q).last = (*q).first;
    }
}   /* queue_push */


int dequeue(TQueue *q) {
    if ( (q == NULL) || (*q).first == NULL) {
        print_error_exit("Queue has no elements to pop");
    }

    int result = (*q).first->value;

    TQueueNode *tmp = (*q).first;
    (*q).first = (*q).first->next;

    free(tmp);

    return result;
}   /* queue_pop */


void print_queue(TQueue q) {
    TQueueNode *tmp = q.first;
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->next;
    }
}   /* print_queue */
