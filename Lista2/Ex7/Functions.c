#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Functions.h"

typedef struct element
{ // struct dos elementos
    char *name;
    int value2k, value90;
    struct element *next;
} stElement;

typedef struct list
{ // struct da lista
    stElement *source2k, *source90, *last2k, *last90;
} stList;

stElement *createEl()
{
    stElement *elementParam = (stElement *)malloc(sizeof(stElement));
    elementParam->name = NULL;
    elementParam->value2k = NULL;
    elementParam->value90 = NULL;
    elementParam->next = NULL;
    return elementParam;
}
stList *createList()
{
    stList *multiLinkList = (stList *)malloc(sizeof(stList));
    multiLinkList->source2k = createEl();
    multiLinkList->last2k = createEl();
    multiLinkList->source90 = createEl();
    multiLinkList->last90 = createEl();

    if (multiLinkList)
    {
        return multiLinkList;
    }
    else
    {
        printf("Explosão no alloc");
        return NULL;
    }
}

stElement *putInfos(char *name, int value2k, int value90){
    stElement *addingElement = createEl();
    addingElement->name = name;
    addingElement->value2k = value2k;
    addingElement->value90 = value90;

}

void *insertIn2k(stList *list, stElement *el)
{ // inserindo elementos na lista de 2000
    if (!list->source2k->value2k)
    { // quando a raiz é vazia
        list->source2k = el;
        list->last2k = el;
    }
    else if (el->value2k > list->source2k->value2k)
    { // quando o elemento é maior que a raiz
        stElement *aux = createEl();
        aux = list->source2k;
        list->source2k = el;
        list->source2k->next = aux;
    }
    else
    { // casos onde não é mais necessário verificar a raiz
        if (el->value2k < list->last2k->value2k)
        { // verificando se é menor que o último elemento
            stElement *aux = createEl();
            aux = list->last2k;
            aux->next = el;
            list->last2k = el;
            list->last2k->next = NULL;
            
        }
        else
        { // caso onde o elemento vai ser inserido no meio da lista
            stElement *iterableNode = createEl();
            iterableNode = list->source2k;
            while (iterableNode->next)
            { // percorre enquanto tiver proximo pois quando nao tiver mais é o ultimo
                if (iterableNode->next->value2k < el->value2k)
                {
                    stElement *aux = iterableNode->next;
                    el->next = aux;
                    iterableNode->next = el;
                    break;
                }
                iterableNode = iterableNode->next;
            }
        }
    }
    
}

void insertIn90(stList *list, stElement *el)
{
    if (!list->source90->value90)
    { // quando a raiz é vazia
        list->source90 = el;
        list->last90 = el;
    }
    else if (el->value90 > list->source90->value90)
    { // quando o elemento é maior que a raiz
        stElement *aux = createEl();
        aux = list->source90;
        list->source90 = el;
        list->source90->next = aux;
    }
    else
    { // casos onde não é mais necessário verificar a raiz
        if (el->value90 < list->last90->value90)
        { // verificando se é menor que o último elemento
            stElement *aux = createEl();
            aux = list->last90;
            aux->next = el;
            list->last90 = el;
            list->last90->next = NULL;
        }
        else
        { // caso onde o elemento vai ser inserido no meio da lista
            stElement *iterableNode = createEl();
            iterableNode = list->source90;
            while (iterableNode->next)
            { // percorre enquanto tiver proximo pois quando nao tiver mais é o ultimo
                if (iterableNode->next->value90 < el->value90)
                {
                    stElement *aux = iterableNode->next;
                    el->next = aux;
                    iterableNode->next = el;
                    break;
                }
                iterableNode = iterableNode->next;
            }
        }
    }
}

void showList2k(stList *list)
{
    stElement *showElement = createEl();
    showElement = list->source2k;
    while (showElement)
    {
        printf("The state of: %s had in 2000 the population of: %d\n", showElement->name, showElement->value2k);
        showElement = showElement->next;
    }
}

void showList90(stList *list)
{
    stElement *showElement = createEl();
    showElement = list->source90;
    while (showElement)
    {
        printf("The state of: %s had in 90 the population of: %d\n", showElement->name, showElement->value90);
        showElement = showElement->next;
    }
}