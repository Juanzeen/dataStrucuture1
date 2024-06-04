#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element{ //struct dos elementos
    char name[2];
    float value2k, value90;
    stElement *next;
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

                }
            }
        }
        
    }

}

void insertIn90(stList *list, stElement *el){
    stElement *source = list->source90;
}

int main(void){
    stElement *baseArray[20];
    stList *multiLinkList;

    *baseArray = (stElement*)malloc(sizeof(stElement));
    multiLinkList = (stList*)malloc(sizeof(stList));

    for(int i = 0; i < 20; i++){
        printf("Put here the name of the area with abreviation (ex: New York - NY): ");
        scanf("%s", baseArray[i]->name);
        printf("Put here the census of the area in 2k: ");
        scanf("%s", baseArray[i]->value2k);
        printf("Put here the name of the area in 90: ");
        scanf("%s", baseArray[i]->value90);

        insertIn2k(multiLinkList->source2k, baseArray[i]);
        insertIn90(multiLinkList->source2k, baseArray[i]);

    }



    return 0;
}