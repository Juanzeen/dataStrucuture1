#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH 2
typedef struct element{ //struct dos elementos
    char name[2];
    int value2k, value90;
    struct element *next;
}stElement;

typedef struct list{//struct da lista
    stElement *source2k, *source90, *last2k, *last90;
}stList;

stElement *findLast(stList *list){
    stElement *iterableNode = list->source2k;
    while(iterableNode->next){
        iterableNode = iterableNode->next;
    }
    return iterableNode;
}

void insertIn2k(stList *list, stElement *el){//inserindo elementos na lista de 2000
    stElement *source = list->source2k;
    

    if(!source){//quando a raiz é vazia
        list->source2k = el;
        list->last2k = el;
    }else if(source->value2k > el->value2k){//quando o elemento é menor que a raiz
        stElement *aux = source;
        list->source2k = el;
        list->source2k->next = aux;
    }else{//casos onde não é mais necessário verificar a raiz
        if(el->value2k > list->last2k->value2k){//verificando se é maior que o último elemento
            stElement *aux = list->last2k;
            aux->next = el;
            list->last2k = el;
        }else{//caso onde o elemento vai ser inserido no meio da lista
            stElement *iterableNode = list->source2k;
            while(iterableNode->next){//percorre enquanto tiver proximo pois quando nao tiver mais é o ultimo
                if(iterableNode->next->value2k > el->value2k){
                    stElement *aux = iterableNode->next;
                    el->next = aux;
                    iterableNode->next = el;
                    break;
                }
            }
        }
        
    }

}

void insertIn90(stList *list, stElement *el){
    stElement *source = list->source90;
}

void showList2k(stList *list){
    stElement *showElement = list->source2k;
    while(showElement){
        printf("The state of: %s had in 2000 the population of: %d\n", showElement->name, showElement->value2k);
        showElement = showElement->next;
    }
}

int main(void){
    stList *multiLinkList;

    multiLinkList = (stList*)malloc(sizeof(stList));
    for(int i = 0; i < LENGTH; i++){
        stElement *currentEl;
        currentEl = (stElement*)malloc(sizeof(stElement)) ;

        printf("Put here the name of the area with abreviation (ex: New York - NY): ");
        scanf("%s", &currentEl->name);
        printf("Put here the census of the area in 2k: ");
        scanf("%d", &currentEl->value2k);
        printf("Put here the name of the area in 90: ");
        scanf("%d", &currentEl->value90);
        insertIn2k(multiLinkList, currentEl);
        free(currentEl);
    }
        printf("State: %s and census: %d", multiLinkList->source2k->name, multiLinkList->source2k->value2k);
        showList2k(multiLinkList);
    return 0;
}