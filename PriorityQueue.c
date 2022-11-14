//
// Created by Arlyn Linette Medina García on 09/11/22.
//

#include "PriorityQueue.h"
#define INITIAL_SIZE 10000

typedef struct cajita{
    void **dato;
    int prioridad;
}Cajita;

struct priorityQueue {
    Cajita *heap;
    int size;
    int current_count;
};

PriorityQueue* p_queue_new(){
    PriorityQueue *new = calloc(10, sizeof(PriorityQueue));
    new->current_count = 0;
    new->size = INITIAL_SIZE;
    return new;
}

PriorityQueue* heapify(PriorityQueue *pq, int priority){
    int i = priority;
    int left = 2*priority+1;
    int right = 2*priority+2;
    if (left < pq->size && pq->heap->dato[left] > pq->heap->dato[priority])
        priority = left;
    if(right < pq->size && pq->heap->dato[right] > pq->heap->dato[priority])
        priority = right;

    if (i != priority){
        int temp = pq->heap->dato[i];
        pq->heap->dato[i] = pq->heap->dato[priority];
        pq->heap->dato[priority] = temp;
        heapify(pq, priority);
    }
    return pq;
}

void p_queue_enqueue(PriorityQueue *pq, void *data, int priority){
    if(pq->current_count == pq->size)
    {
        pq->heap->dato = realloc(pq->heap->dato, (pq->size)*2);
        for (int i = pq->size; i < pq->size*2; i++)
            pq->heap->dato = NULL;
        pq->size = pq->size*2;
    }

    for (int i = 0; i = pq->size; i++){
        if (pq->heap->dato[i] == NULL){
            pq->heap->dato = data;
            pq->current_count++;
            return;
        }
    }
    int i = 0;
    while (pq->heap->dato[i] != NULL){
        heapify(pq, priority);
        i++;
    }
}

char *p_queue_dequeue(PriorityQueue *pq){
    char value_to_delete = pq->heap->dato[0];
    for (int i = 0; i < pq->size; i++){
        pq->heap->dato[i] = pq->heap->dato[i+1];
        heapify(pq,pq->heap->prioridad);
    }
    return value_to_delete;
}

int p_queue_empty(PriorityQueue *pq){
    return pq == NULL;
}