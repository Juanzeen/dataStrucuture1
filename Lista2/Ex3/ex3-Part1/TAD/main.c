#include <stdio.h>
#include <stdlib.h>
#include "auxiliar.c"


int main(void){

    Fila *fila = (Fila*)malloc(sizeof(Fila)); 
    inicializando(fila);
    int option;
    

    do{
        

        printf("\n\n----- SUA FILA ------\n\n");
        showEqueue(fila);
        printf("\n\n --- ESCOLHA UMA DAS OPCOES ----\n");
        printf("[1]- Inserir elemento na fila\n");
        printf("[2]- Remover elemento na fila\n");
        printf("[3]- Liberar fila\n");
        printf("[4]- Sair\n");
        printf("\n opcao escolhida: ");
        scanf("%d", &option);
        
        switch (option)
        {
        case 1:
            printf("\nDigite o numero que quer inserir na fila: ");
            int number;
            scanf("%d", &number);
            enqueue(fila, number);
            break;
        case 2:
            dequeue(fila);
            break;
        case 3:
            free(fila);
            printf("\n Fila liberada\n");
            exit(1);
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("\n Escolha uma opcao valida\n");
            break;
        }
    } while(option != 4);

    return 0;
}