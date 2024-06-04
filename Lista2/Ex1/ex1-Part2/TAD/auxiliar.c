#include <stdio.h>
#include <stdlib.h>
#include "stackLinkedTAD.h"

void startStack(Stack *stack){
    stack->link = NULL;
}

int empty(Stack *stack){
     return (stack->link == NULL) ? 1:0;
}

void push(Stack *head, int x){
    Stack *newNodo = (Stack*)malloc(sizeof(Stack));
    if(newNodo){
        newNodo->data = x;
    }

    if(empty(head)){
        head->link = newNodo;
        newNodo->link = NULL;
    } 
    else{
        Stack *oldHead = head->link;
        head->link = newNodo;
        newNodo->link = oldHead;
    }
    printf("\n Elemento inserido\n");

}

void pop(Stack *head){
    if(empty(head)){
        printf("\n Underflow\n");
    }
    else{
        Stack *aux = head->link;
        printf("\n Elemento removido %d\n", aux->data);
        head->link = head->link->link;
        free(aux);
    }
}

int sizeStack(Stack *head){
    int counter = 0;
    if(empty(head)){
        return counter;
    }
    else{
        Stack *aux = head->link;
        while(aux != NULL){
            aux = aux->link;
            counter += 1;
        }
        return counter;
    }
}

void stackElementsRemoved(Stack *head){
    if(empty(head)){
        printf("\nUnderflow\n ");
    }
    else{
        Stack *currentNode = head->link;
        while(currentNode != NULL){
            printf("\nElemento removido %d", currentNode->data);
            Stack *aux = currentNode;
            currentNode = currentNode->link;
            free(aux); 
        } 
        free(head); // liberando o meu topo, no caso, o endereço da minha head
    }
}


void topElement(Stack *head){
    if(empty(head)){
        printf("\nUnderflow\n");
    }
    else{
        int topElement = head->link->data;
        printf("\nO elemento do topo é %d", topElement);
    }
}

void freeStack(Stack *head){
    if(empty(head)){
        free(head);
    }
    else{
        Stack *currentNode = head->link;
        while(currentNode != NULL){
            Stack *aux = currentNode;
            currentNode = currentNode->link;
            free(aux);
        }
        //free(head); 
        printf("\n Pilha liberada\n ");
    }
}