#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "linkedListTAD.h"


int emptyList(NODE *head){
   return (head->link == NULL) ? 1:0;
}

void startList(NODE *head){
    head->link = NULL;
}

void insertionBegin(NODE *head, int x){
    NODE *newNode =(NODE*)malloc(sizeof(NODE));
    if(newNode){
        newNode->data = x;
        if(emptyList(head)){
            head->link = newNode;
            newNode->link = NULL;
        }
        else{
            NODE *oldHead = head->link;
            head->link = newNode;
            newNode->link = oldHead;
        }
    }
    else{
        printf("\n No alocation\n");
        exit(1);
    }
}

void insertionEnd(NODE *head, int x){    
    NODE  *newNodo = (NODE *)malloc(sizeof(NODE));
    newNodo->data = x;
    if(!newNodo){
        printf("No alocation");
        exit(1);
    }
    else{
        if(emptyList(head)){ 
            head->link = newNodo;
            newNodo->link = NULL;
        }
        else
        {
            NODE *aux = head->link;
            while(aux->link != NULL){
                aux = aux->link;
            }
            aux->link = newNodo;
            newNodo->link = NULL;
        }
    }
}


void inserirOrdenado(NODE *head, int x) {

    NODE *newNodo = (NODE*)malloc(sizeof(NODE));
    newNodo->data = x;
    newNodo->link = NULL;
    if(!newNodo){
        printf("\nNo alocation\n");
        exit(1);
    }
    else{

        if (head == NULL || x < head->data) {
            newNodo->link = head;
            head = newNodo;
        } else {
            NODE *aux = head;
            // sabendo onde inserir
            while (aux->link != NULL && aux->link->data < x) {
                aux = aux->link;
            }   
            newNodo->link = aux->link;
            aux->link = newNodo;
        }
    }
}

void removeBegin(NODE *head){
    if(emptyList(head)){
        printf("\n A lista esta vazia \n");
    }
    else{
        NODE *oldHead = head->link;
        printf("\n Elemento removido %d\n", oldHead->data);
        head->link = oldHead->link;
        free(oldHead);
    }
}

void removeFinal(NODE *head){
    if(emptyList(head)){
        printf("\n A lista esta vazia \n");
    }
    else{
        NODE *penultimateNode, *aux = head->link;
        while(aux->link != NULL){
            penultimateNode = aux;
            aux = aux->link;
        }
        penultimateNode->link = aux->link; // NULL
        free(aux);
        
    }
}


void removeSpecific(NODE *head, int number){
    if(emptyList(head)){
        printf("\n A lista esta vazia \n");
    }
    else{
        NODE *specificNode, *aux = head->link;
        while(aux->link != NULL && aux->data != number){
            specificNode = aux;
            aux = aux->link;
        }
        if(aux == NULL){
            printf("\n Nao encontrado \n");
        }
        if(aux == head->link){
            head->link = aux->link;
        }
        else{
            specificNode->link = aux->link;
        }
        free(aux);
    }
}


void specificPosition(NODE *head, int position){
    int aux = 1;
    if(emptyList(head)){
        printf("\n Lista vazia\n");
    }

    NODE *currentNode = head->link;
    while(currentNode != NULL && aux < position){
        currentNode = currentNode->link;
        aux++;
    }
    if(currentNode == NULL){
        printf("\n Elemento não encontrado \n");
    }
    else{
        printf("\n Elemento encontrado\n");
        printf("\né o elemento %d", currentNode->data);
    }
}



void showList(NODE *head){
    if(emptyList(head)){
        printf("\n A lista esta vazia\n");

    }
    else{
        NODE *aux = head->link;
        while(aux != NULL){
            printf("%d\t", aux->data);
            aux = aux->link;
        }
    }
}

void freeList(NODE *head){
    if(emptyList(head)){
        free(head);
       
    }
    else{
        NODE *currentNode = head->link;
        while(currentNode != NULL){
            NODE *aux = currentNode;
            currentNode= currentNode->link;
            free(aux);
        }
        free(head);
    }
}

