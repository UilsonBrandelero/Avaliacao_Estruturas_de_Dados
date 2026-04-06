#ifndef FILA_H

#define FILA_H

#include "lista_encadeada.h"

typedef struct
{
    LinkedList list;
} Queue;

void initQueue(Queue *q);
void enqueue(Queue *q, int value);
int dequeue(Queue *q);
int isEmpty(Queue *q);
void printQueue(Queue *q);

#endif