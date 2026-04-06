#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

typedef struct 
{
    Node* head;
}LinkedList;

void initList(LinkedList* list);
void insertAtBeinning(LinkedList* list, int value);
void insertAtEnd(LinkedList* list, int value);
void printList(LinkedList* list);
Node* search(LinkedList* list, int value);
void removeValue(LinkedList* list, int value);
void freeList(LinkedList* list);
void insertionSort(LinkedList *list);





#endif
