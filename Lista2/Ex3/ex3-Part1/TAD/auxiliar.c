#include <stdio.h>
#include <stdlib.h>
#include "filaTAD.h"

void clearScreen() { 
    system("clear"); 
}

int empty(Fila *fila){
    // como a head e a tail irão inicializar na ultima posicao do vetor
    if(fila->head == fila->tail){
        return 1;
    }
    return 0;
}

void inicializando(Fila *fila){
    fila->head = fila->tail = - 1;
}

void enqueue(Fila *fila, int number){
    fila->tail = (fila->tail == TAMANHOFILA - 1) ? 0:fila->tail + 1; // verificacao se o ultimo elemento esta na posicao final ou nao do array.
    
    if(fila->tail == fila->head){
        printf("\n Fila cheia!\n");
    }
    else{
        fila->queueItems[fila->tail] = number;
    }
}

void dequeue(Fila *fila){
    if(empty(fila)){
        printf("\nFila vazia\n");
    }
    else{
        fila->head = (fila->head == TAMANHOFILA - 1) ? 0:fila->head + 1;
        printf("\nElemento removido %d\n", fila->queueItems[fila->head]);
        fila->queueItems[fila->head] = 0;
    }
    
}



void showEqueue(Fila *fila){
    for(int index = 0; index < TAMANHOFILA; index++){
        printf("-|%d|", fila->queueItems[index]); // posso fazer isso pois em C, quando alocamos
                                                  //  é passado um valor genérico. No caso de inteiro, é zero
    }
}