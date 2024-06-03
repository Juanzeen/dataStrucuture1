#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "auxiliar.c"



int main(void){
    NODE *head = (NODE*)malloc(sizeof(NODE));
    int option;
    int number;
    

    if(head){
        startList(head);

        do{
            clearScreen();
            printf("\n-------- SUA LISTA --------\n\n");
            showList(head);
            printf("\n\n ------ ESCOLHA UMA OPCAO ------\n");
            printf("[1] - Inserir elemento no inicio da lista\n");
            printf("[2] - Inserir elemento no final da lista\n");
            printf("[3] - Inserir elemento de maneira ordenada na lista\n");
            printf("[4] - remover o primeiro elemento da lista\n");
            printf("[5] - remover o ultimo elemento da lista\n");
            printf("[6] - remover um elemento em especifico da lista\n");
            printf("[7] - Saber qual elemento esta em uma posicao especifica lista\n");
            printf("[8]- liberar lista\n");
            printf("[9]- Sair\n\n");
            printf("Digite a opcao escolhida: ");
            scanf("%d", &option);

            switch (option)
            {
            case 1:
                
                printf("\n Digite o numero que deseja inserir: ");
                scanf("%d", &number);
                insertionBegin(head, number);
                printf("\nElemento inserido");
                break;
            
            case 2:
                
                printf("\n Digite o numero que deseja inserir: ");
                scanf("%d", &number);
                insertionEnd(head, number);
                printf("\nElemento inserido");
                break;
            
            case 3:
             
                printf("\n Digite o numero que deseja inserir: ");
                scanf("%d", &number);
                inserirOrdenado(head, number);
                printf("\nElemento inserido");
                break;
            
            case 4:
              
                removeBegin(head);
                break;
            
            case 5:
        
                removeFinal(head);
                break;
            
            case 6:
               
                printf("\n Digite o elemento que quer remover: ");
                int x;
                scanf("%d", &x);
                removeSpecific(head, x);
                break;
            
            case 7:
              
                printf("\nDigite a posicao em quer remover: ");
                int position;
                scanf("%d", &position);
                specificPosition(head,position);
                break;
            
            case 8:
                freeList(head);
                printf("\n Fila Liberada\n");
                //exit(1);
                break;
            case 9:
                exit(1);
                break;
            
            default:
                printf("\n Escolha uma opcao valida\n");
                break;
            }

        } while(option != 9);
    }

}