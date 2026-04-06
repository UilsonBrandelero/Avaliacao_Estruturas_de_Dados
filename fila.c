#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void initQueue(Queue *q)
{
    initList(&q->list);
}

int isEmpty(Queue *q)
{
    return q->list.head == NULL;
}

void enqueue(Queue *q, int value)
{
    insertAtEnd(&q->list, value);
}

int dequeue(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Fila Vazia!\n");
        return -1;
    }
    Node *temp = q->list.head;
    int value = temp->data;

    q->list.head = temp->next;
    free(temp);
    return value;
}
void printQueue(Queue *q){
    if (isEmpty(q))
    {
        printf("Fila Vazia!");
    }
    
    Node* temp = q->list.head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    
}