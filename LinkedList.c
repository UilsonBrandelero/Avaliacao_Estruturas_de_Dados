#include "lista_encadeada.h"

void initList(LinkedList *list)
{
    list->head = NULL;
}

void insertAtBeinning(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = list->head;
    list->head = newNode;
}

void insertAtEnd(LinkedList *list, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (list->head == NULL)
    {
        list->head = newNode;
        return;
    }
    Node *temp = list->head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void printList(LinkedList *list)
{
    if (list->head ==NULL)
    {
        printf("Lista Vazia!\n");
    }
    
    Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
}

Node *search(LinkedList *list, int value)
{
    Node *temp = list->head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void removeValue(LinkedList *list, int value)
{
    Node *temp = list->head;
    Node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    if (prev == NULL)
    {
        list->head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    free(temp);
}

void freeList(LinkedList *list)
{
    Node *temp = list->head;

    while (temp != NULL)
    {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
    list->head = NULL;
}


void sortedInsert(Node **sorted, Node *newNode)
{
    if (*sorted == NULL || (*sorted)->data >= newNode->data)
    {
        newNode->next = *sorted;
        *sorted = newNode;
    }
    else
    {
        Node *current = *sorted;
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}
void insertionSort(LinkedList *list)
{
    Node *sorted = NULL;
    Node *current = list->head;

    while (current != NULL)
    {
        Node *next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    list->head = sorted;
}
