#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "stackTAD.h"



int empty(HeadStack *head){
    return (head->count == 0) ? 1:0; // pq esta vendo pela count e não pelo topo?
}

/*HeadStack *createStack(){ // aqui é a criacao da head, ou seja, a criacao da pilha
    HeadStack *head;
    head = (HeadStack*)malloc(sizeof(HeadStack));
    if(head){
        head->count = 0;
        head->top = NULL;
    }
    return head;
}*/


void push(HeadStack *head, void *data){
   
    StackElements *newNode = (StackElements*)malloc(sizeof(StackElements));
    if(!newNode){
        return;
    }
    else{
        newNode->data = data;
        newNode->link = head->top;
        head->top = newNode;

        head->count++;       
    }
}

void *pop(HeadStack *head){
    void *auxData;

    if(empty(head)){
        auxData = NULL;
    }
    else{
        StackElements *aux = head->top; // guardando o primeiro node
        auxData = head->top->data; // pegando o dado do primeiro node
        head->top = head->top->link; // fazendo a cabeca apontar para o segundo node
        free(aux); 
        head->count--;
    }    
    return auxData;
}

void* elementTop(HeadStack *head){
    if(empty(head)){
        printf("\nPilha vazia\n");
        return NULL;
    }
    else{
        return head->top->data;
    }
}

bool fullStack(HeadStack *head){
    StackElements *verification;
    verification = (StackElements*)malloc(sizeof(*(head->top)));
    if(verification){
        free(verification);
        return false;
    }

    return true; // significa que a pilha esta cheia
}

int totalElements(HeadStack *head){
   return head->count;
}

HeadStack *freeStack(HeadStack *head){

    if(head){
        while(head->top!= NULL){
            free(head->top->data);

            StackElements *aux = head->top;
            head->top = head->top->link;
            free(aux);
        }
        free(head);
    }
    return NULL;

}



