#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int data;
    struct stack *link;
} StackItems;

typedef struct headStack{
    StackItems *top;
    int *topElement;
} HeadStack;


void startStack(HeadStack *head){
    head->top = NULL;
}

int empty(HeadStack *head){
     return (head->top == NULL) ? 1:0;
}

void push(HeadStack *head, int x){
    StackItems *newNodo = (StackItems*)malloc(sizeof(StackItems));
    if(newNodo){
        newNodo->data = x;
    }

    if(empty(head)){
        head->top = newNodo;
        newNodo->link = NULL;
        head->topElement = &newNodo->data;
    } 
    else{
        StackItems *oldHead = head->top;
        head->top = newNodo;
        newNodo->link = oldHead;
        head->topElement = &newNodo->data;
    }
    printf("\n Elemento inserido\n");

}

void pop(HeadStack *head){
    if(empty(head)){
        printf("\n Underflow\n");
    }
    else{
        StackItems *aux = head->top;
        printf("\n Elemento removido %d\n", aux->data);
        head->top= head->top->link;
        head->topElement = &head->top->data;
        free(aux);
    }
}

int sizeStack(HeadStack *head){
    int counter = 0;
    if(empty(head)){
        return counter;
    }
    else{
        StackItems *aux = head->top;
        while(aux != NULL){
            aux = aux->link;
            counter += 1;
        }
        return counter;
    }
}

void stackElementsRemoved(HeadStack *head){
    if(empty(head)){
        printf("\nUnderflow\n ");
    }
    else{
        StackItems *currentNode = head->top;
        while(currentNode != NULL){
            printf("\nElemento removido %d", currentNode->data);
            StackItems *aux = currentNode;
            currentNode = currentNode->link;
            free(aux); 
        } 
        free(head); // liberando o meu topo, no caso, o endereço da minha head
    }
}


void topElement(HeadStack *head){
    if(empty(head)){
        printf("\nUnderflow\n");
    }
    else{
        printf("\nO elemento do topo é %d", *head->topElement);
    }
}

void freeStack(HeadStack *head){
    if(empty(head)){
        free(head);
    }
    else{
        
        StackItems *currentNode = head->top;
        while(currentNode != NULL){
            StackItems *aux = currentNode;
            currentNode = currentNode->link;
            free(aux);
        }
        //free(head); 
        printf("\n Pilha liberada\n ");
    }
}

int main(void){
  HeadStack *pilha = (HeadStack*)malloc(sizeof(HeadStack));
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