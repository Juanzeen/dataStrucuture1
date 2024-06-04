#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.c"



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