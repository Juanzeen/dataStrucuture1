#include <stdio.h>
#include <stdlib.h>
#include "auxilixarQueue.c"


int main (void){
    HeadQueue *head = (HeadQueue*)malloc(sizeof(HeadQueue));
    if(head){
       int option;
       do{
            printf("\n\n----- Escola uma opcao -----\n\n");
            printf("[1]- Inserir elemento na fila\n");
            printf("[2]- Remover elemento na fila\n");
            printf("[3]- Primeiro elemento na fila\n");
            printf("[4]- Ultimo elemento na fila\n");
            printf("[5]- Quantos elemento tem na fila\n");
            printf("[6]- Liberar fila\n");
            printf("[7]- Sair\n");
            printf("Escolha uma opcao: ");
            scanf("%d", &option);

            switch (option){
            case 1:
                printf("\n Digite o numero a ser inserido: ");
                int number;
                scanf("%d", &number);
                enqueue(head, number);
                printf("\n Elemento inserido");
                break;
            case 2:
                dequeue(head);
                break;
            case 3:
                printf("\nO primeiro elemento da fila e %d", firstElement(head));
                break;
            case 4:
                printf("\nO ultimo elemento da fila e %d", lastElement(head));
                break;
            case 5:
                printf("\nExistem %d elementos na fila\n", size(head));
                break;
            case 6:
                freeEqueue(head);
                exit(1);
                break;
            case 7:
                exit(1);
                break;
            default:
                printf("\nscola uma opcao valida!");
                break;
            }

        } while(option != 7);
    }

    return 0;
}