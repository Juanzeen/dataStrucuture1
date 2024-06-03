#include <stdio.h>
#include <stdlib.h>
#include "filaTAD.h"


int main (void){
    HeadQueue *head = (HeadQueue*)malloc(sizeof(HeadQueue));
    if(head){
       int option;
       int number;
       int *dataPtr;

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
                dataPtr = (int*)malloc(sizeof(int));
                scanf("%d", &number);
                *dataPtr = number;
                enqueue(head, dataPtr);
                printf("\n Elemento inserido");
                break;
            case 2:
                dataPtr = (int*)dequeue(head);
                printf("\n O elemento %d foi retirado\n", *dataPtr);
                free(dataPtr);
                break;
            case 3:
                dataPtr = (int*)firstElement(head);
                printf("\nO primeiro elemento da fila e %d", *dataPtr);
                free(dataPtr);
                break;
            case 4:
                dataPtr = (int*)lastElement(head);
                printf("\nO ultimo elemento da fila e %d", *dataPtr );
                free(dataPtr);
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
}