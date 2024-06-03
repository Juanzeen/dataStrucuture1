#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10
#include "stackTAD.h"


void startStack(Stack *stack){
    stack->top = -1; // inicializando a pilha
}

int empty(Stack *stack){
    return (stack->top == -1) ? 1:0;
}

void push(Stack *stack, int number){
    if (stack->top + 1 == STACKSIZE){
        printf("\nOverflow\n");
    }
    else{
        stack->top += 1; // anda com o topo e depois adiciona
        stack->stackItems[stack->top] = number;
        printf("\nElemento adicionado");
    }
}

void pop(Stack *stack){
    if(empty(stack)){
        printf("\nUnderflow\n ");
    }
    else{
        int returnedValue = stack->stackItems[stack->top];
        printf("\n Element removed: %d\n", returnedValue);
        stack->stackItems[stack->top] = 0;
        stack->top--;
    }
}

void topElement(Stack *stack){
    if(empty(stack)){
        printf("\nUnderflow\n ");
    }
    else{
       printf("\nO ultimo elemento: %d", stack->stackItems[stack->top]);
    }
}


void stackElementsRemoved(Stack *stack){
    if(empty(stack)){
        printf("Underflow");
    }
    else{
        for(int index = 0; index < STACKSIZE;index++){
            if(empty(stack)){
                break;
            }
            pop(stack);
        }
    }
}

int sizeStack( Stack *stack){
    if(empty(stack)){
        return 0;
    }
    else{
        return stack->top + 1;
    }
}


void freeStack(Stack *stack){
    free(stack);
    printf("\n Pilha liberada\n");
}
 