#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH 1
typedef struct element{ //struct dos elementos
    char name[2];
    int value2k, value90;
    struct element *next;
}stElement;

typedef struct list{//struct da lista
    stElement *source2k, *source90, *last2k, *last90;
}stList;

stElement *createEl(){
    stElement *elementParam = (stElement*)malloc(sizeof(stElement));
    elementParam->next = NULL;
    elementParam->value2k = 0;
    elementParam->value90 = 0;
    elementParam->name[2] = "df";//se eu nao coloco predefinido ele nao fica salvo depois de ler e inserir, se eu coloco ele dá segmentation fault
    return elementParam;
}
stList *createList(){
    stList *multiLinkList = (stList*)malloc(sizeof(stList));
    multiLinkList->source2k = createEl();
    multiLinkList->last2k = createEl();
    multiLinkList->source90 = createEl();
    multiLinkList->last90 = createEl();
}

stElement *findLast(stList *list){
    stElement *iterableNode = createEl();
    iterableNode = list->source2k;
    while(iterableNode->next){
        iterableNode = iterableNode->next;
    }
    return iterableNode;
}

void *insertIn2k(stList *list, stElement *el){//inserindo elementos na lista de 2000

    if(list->source2k == NULL){//quando a raiz é vazia
        list->source2k = el;
        list->last2k = el;
        printf("entrei aqui na funcao de nao ter raiz!\n");
    }else if(list->source2k->value2k > el->value2k){//quando o elemento é menor que a raiz
        stElement *aux = list->source2k;
        list->source2k = el;
        list->source2k->next = aux;
        printf("entrei aqui na funcao de inserir antes da raiz\n");
    }else{//casos onde não é mais necessário verificar a raiz
        if(el->value2k > list->last2k->value2k){//verificando se é maior que o último elemento
            printf("entrei aqui na funcao de inserir no final!\n");
            stElement *aux = createEl();
            aux = list->last2k;
            aux->next = el;
            list->last2k = el;

        }else{//caso onde o elemento vai ser inserido no meio da lista
        printf("entrei aqui na funcao de inserir no meio da lista\n");
            stElement *iterableNode = createEl();
            iterableNode = list->source2k;
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

      printf("valor da raiz %d e valor do que será inserido: %d\n", list->source2k->value2k, el->value2k);

}

void insertIn90(stList *list, stElement *el){
    stElement *source = list->source90;
}

void showList2k(stList *list){
    stElement *showElement = createEl();
    showElement = list->source2k;
    while(showElement){
        printf("The state of: %s had in 2000 the population of: %d\n", showElement->name, showElement->value2k);
        showElement = showElement->next;
    }
}

int main(void){
    stList *multiLinkList;

    multiLinkList = createList();
    for(int i = 0; i < LENGTH; i++){
        stElement *currentEl = createEl();

        printf("Put here the name of the area with abreviation (ex: New York = NY): ");
        scanf("%s", &currentEl->name);
        printf("Put here the census of the area in 2k: ");
        scanf("%d", &currentEl->value2k);
        printf("Put here the name of the area in 90: ");
        scanf("%d", &currentEl->value90);
        insertIn2k(multiLinkList, currentEl);
        free(currentEl);
    }
           printf("valor da raiz %d\n\n", multiLinkList->source2k->value2k);//o valor nao é exibido aqui, nao sei o porque, porque aparentemente ta tudo certo.
        showList2k(multiLinkList);
    return 0;
}