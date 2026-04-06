#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lista_encadeada.h"
#include "fila.h"
#include "delay.h"

#define SLEEP_TIME 1000

void execucaoOrdenacaoLista();
void execucaoFila();
void desisfileirarComEfeito(Queue *q);

void main()
{
    printf("Execução da Ordenação com Lista Encadeada\n\n");
    execucaoOrdenacaoLista();

    printf("\nExecução da manipulação da Fila com Lista Encadeada\n\n");
    execucaoFila();

    printf("\nFim das execuções\n");
}

void execucaoFila()
{
    Queue fila;
    initQueue(&fila);

    printf("Enfileirando...\n");

    enqueue(&fila, 1);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 2);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 3);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 4);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 5);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 6);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 7);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 8);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    enqueue(&fila, 9);
    printf("\r");
    printQueue(&fila);
    delay_ms(SLEEP_TIME);
    fflush(stdout);

    desisfileirarComEfeito(&fila);
}
void execucaoOrdenacaoLista()
{
    LinkedList list;
    initList(&list);

    insertAtEnd(&list, 4);
    insertAtEnd(&list, 2);
    insertAtEnd(&list, 5);
    insertAtEnd(&list, 1);
    insertAtEnd(&list, 3);
    insertAtEnd(&list, 9);
    insertAtEnd(&list, 7);
    insertAtEnd(&list, 6);
    insertAtEnd(&list, 8);
    insertAtEnd(&list, 0);

    printf("Lista sem ordenar: ");
    printList(&list);
    printf("\n");

    printf("Ordenando Lista com Insertion Sort...\n");
    delay_ms(SLEEP_TIME);
    insertionSort(&list);

    printf("Lista Ordenada: ");
    printList(&list);
    printf("\n");
}

void desisfileirarComEfeito(Queue *q)
{
    if (isEmpty(q))
    {
        return;
    }

    printf("\nDesinfileirando...\n");
    printQueue(q);
    fflush(stdout);
    delay_ms(1000);

    while (q->list.head != NULL)
    {
        
        printf("\033[2K\r");
        dequeue(q);
        printQueue(q);
        delay_ms(1000);
        fflush(stdout);
        
        
    }
}