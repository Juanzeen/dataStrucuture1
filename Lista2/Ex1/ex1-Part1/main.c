#include <stdlib.h>
#include <stdio.h>
#define STACKSIZE 10



typedef struct stack{
    int top;
    int stackItems[STACKSIZE];
} Stack;


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
 

int main(void){
 Stack *pilha = (Stack *)malloc(sizeof(Stack));
 if(pilha != NULL){
   startStack(pilha);  
 }
 int option;

 do{
        printf("\n\n-------- ESCOLHA UMA OPCAO --------\n\n");
        printf("[1]- Inserir elemento na pilha\n");
        printf("[2]- Remover elemento na pilha\n");
        printf("[3]- Mostrar o ultimo elemento da pilha sem retira-lo\n");
        printf("[4]- Mostrar todos os elementos da lista, sabendo que eles serão removidos\n");
        printf("[5]- Mostrar quantos elementos tem na pilha\n");
        printf("[6]- Liberar pilha\n");
        printf("[7]- SAIR\n");
        printf("\n Escolha uma das opcoes: ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEscolha um elemento para inserir: ");
            int number;
            scanf("%d", &number);
            push(pilha, number);
            break;
        case 2:
            pop(pilha);
            break;
        case 3:
            topElement(pilha);
            break;
        case 4:
            stackElementsRemoved(pilha);
            break;
        case 5:
            printf("%d",sizeStack(pilha));
            break;
        case 6:
            freeStack(pilha); // se liberar duas vezes, da double free
            break;
        case 7:
            exit(1);
            break;
        default:
            printf("\nEscolha uma opcao válida");
            break;
        }
    } while(option != 7);



    return 0;
}