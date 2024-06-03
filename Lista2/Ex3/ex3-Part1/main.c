#include <stdio.h>
#include <stdlib.h>
#define TAMANHOFILA 5

typedef struct queue{
    int head, tail; // head indica o indice do primeiro elemento da fila e tail indica o indice do ultimo elemento 
    int queueItems[TAMANHOFILA];
} Queue;


void clearScreen() { 
    system("clear"); 
}

int empty(Queue *fila){
    // como a head e a tail irão inicializar na ultima posicao do vetor
    if(fila->head == fila->tail){
        return 1;
    }
    return 0;
}

void startQueue(Queue *fila){
    fila->head = fila->tail = - 1;
}

void enqueue(Queue *fila, int number){
    fila->tail = (fila->tail == TAMANHOFILA - 1) ? 0:fila->tail + 1; // verificacao se o ultimo elemento esta na posicao final ou nao do array.
    
    if(fila->tail == fila->head){
        printf("\n Fila cheia!\n");
    }
    else{
        fila->queueItems[fila->tail] = number;
    }
}

void dequeue(Queue *fila){
    if(empty(fila)){
        printf("\nFila vazia\n");
    }
    else{
        fila->head = (fila->head == TAMANHOFILA - 1) ? 0:fila->head + 1;
        printf("\nElemento removido %d\n", fila->queueItems[fila->head]);
        fila->queueItems[fila->head] = 0;
    }
    
}


void showQueue(Queue *fila){
    for(int index = 0; index < TAMANHOFILA; index++){
        printf("-|%d|", fila->queueItems[index]); // posso fazer isso pois em C, quando alocamos
                                                  //  é passado um valor genérico. No caso de inteiro, é zero
    }
}

int main(void){

    Queue *fila = (Queue*)malloc(sizeof(Queue)); 
    startQueue(fila);
    int option;
    
    do{
        

        printf("\n\n----- SUA FILA ------\n\n");
        showQueue(fila);
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