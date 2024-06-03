#include <stdio.h>
#include <stdlib.h>

typedef struct queueItems{
    int data;
    struct queueItems *link;
} QueueItems;

typedef struct headQueue{
    QueueItems *firstNode, *lastNode;
    int size;
} HeadQueue;


void init(HeadQueue *head){
    head->firstNode = NULL;
    head->lastNode = NULL;
    head->size = 0;
}

int empty(HeadQueue *head){
    return (head->firstNode ==  NULL) ? 1:0;
}

void enqueue(HeadQueue *head, int number){
    QueueItems *newNode = (QueueItems*)malloc(sizeof(QueueItems));
    if(newNode){
        newNode->data = number;
        if(empty(head)){
            head->firstNode = newNode;
            newNode->link = NULL;
            head->lastNode = newNode; // se a lista só tiver um elemento, o primeiro e o ultimo sera o mesmo elemento
            head->size++;
        }
        else{
            head->lastNode->link = newNode;
            newNode->link = NULL;
            head->lastNode = newNode;
            head->size++;
        }
    }
}

void dequeue(HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n ");
    }
    else{
        QueueItems *aux = head->firstNode;
        head->firstNode = head->firstNode->link;
        printf("\n O elemento %d foi retirado\n", aux->data);
        free(aux);
        head->size--;
    }
}

int firstElement (HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n");
        return 0;
    }
    else{
        return head->firstNode->data;
    }
}


int lastElement(HeadQueue *head){
    if(empty(head)){
        printf("\n A fila esta vazia\n");
        return 0;
    }
    else{
        return head->lastNode->data;
    }
}


int size(HeadQueue *head){
    if(empty(head)){
        return 0;
    }
    else{
        return head->size;
    }
}

void freeEqueue(HeadQueue *head){
    if(empty(head)){
        free(head);
    }
    else{
        QueueItems *currentNode = head->firstNode;
        while(currentNode != NULL){
            QueueItems *aux = currentNode;
            currentNode= currentNode->link;
            free(aux);
        }
        free(head);
        printf("\n Fila Liberada!!\n");
    }
}




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