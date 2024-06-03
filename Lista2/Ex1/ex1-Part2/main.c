#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack *link;
} Stack;


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

int main(void){
  Stack *pilha = (Stack*)malloc(sizeof(Stack));
  if(pilha != NULL){
     startStack(pilha);
  }
  int option;

  do{
        printf("\n\n-------- CHOICE AN OPTION --------\n\n");
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
            exit(1);
            break;
        case 5:
            printf("%d",sizeStack(pilha));
            break;
        case 6:
            freeStack(pilha);
            exit(1);
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