#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct node{
    void *data;
    struct node *link;
}NODE;

int emptyList(NODE *head);
void startList(NODE *head);
void insertionBegin(NODE *head, void *x);
void insertionEnd(NODE *head, void *x);
void inserirOrdenado(NODE *head, void *x);
void removeBegin(NODE *head);
void removeFinal(NODE *head);
void removeSpecific(NODE *head, void *number);
void specificPosition(NODE *head, int position);
void showList(NODE *head);
void freeList(NODE *head);
