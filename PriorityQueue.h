//
// Created by Arlyn Linette Medina García on 09/11/22.
//

#ifndef PRIORITYQUEUE_PRIORITYQUEUE_H
#define PRIORITYQUEUE_PRIORITYQUEUE_H
#include <stdlib.h>

typedef struct priorityQueue PriorityQueue;

PriorityQueue* p_queue_new();
void p_queue_enqueue(PriorityQueue *pq, void *data, int priority);
char *p_queue_dequeue(PriorityQueue *pq);
int p_queue_empty(PriorityQueue *pq);

#endif //PRIORITYQUEUE_PRIORITYQUEUE_H
