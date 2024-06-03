#include <stdio.h>
#include <stdlib.h>
#include "queueLinkedTAD.h"

void init(HeadQueue *head){
    head->firstNode = NULL;
    head->lastNode = NULL;
    head->size = 0;
}

int empty(HeadQueue *head){
    return (head->firstNode ==  NULL) ? 1:0;
}

void enqueue(HeadQueue *head, int number){
    QueueItems *newNode = (QueueItems*)malloc(sizeof(QueueItems));
    if(newNode){
        newNode->data = number;
        if(empty(head)){
            head->firstNode = newNode;
            newNode->link = NULL;
            head->lastNode = newNode; // se a lista só tiver um elemento, o primeiro e o ultimo sera o mesmo elemento
            head->size++;
        }
        else{
            head->lastNode->link = newNode;
            newNode->link = NULL;
            head->lastNode = newNode;
            head->size++;
        }
    }
}

void dequeue(HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n ");
    }
    else{
        QueueItems *aux = head->firstNode;
        head->firstNode = head->firstNode->link;
        printf("\n O elemento %d foi retirado\n", aux->data);
        free(aux);
        head->size--;
    }
}

int firstElement (HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n");
        return 0;
    }
    else{
        return head->firstNode->data;
    }
}


int lastElement(HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n");
        return 0;
    }
    else{
        return head->lastNode->data;
    }
}


int size(HeadQueue *head){
    if(empty(head)){
        return 0;
    }
    else{
        return head->size;
    }
}

void freeEqueue(HeadQueue *head){
    if(empty(head)){
        free(head);
    }
    else{
        QueueItems *currentNode = head->firstNode;
        while(currentNode != NULL){
            QueueItems *aux = currentNode;
            currentNode= currentNode->link;
            free(aux);
        }
        free(head);
        printf("\n Fila Liberada!!\n");
    }
}

