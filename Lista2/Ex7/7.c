#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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


void *insertIn2k(stList *list, stElement *el)
{ // inserindo elementos na lista de 2000
    if (!list->source2k->value2k)
    { // quando a raiz é vazia
        list->source2k = el;
        list->last2k = el;
    }
    else if (list->source2k->value2k > el->value2k)
    { // quando o elemento é menor que a raiz
        stElement *aux = createEl();
        aux = list->source2k;
        list->source2k = el;
        list->source2k->next = aux;
    }
    else
    { // casos onde não é mais necessário verificar a raiz
        if (el->value2k > list->last2k->value2k)
        { // verificando se é maior que o último elemento
            stElement *aux = createEl();
            aux = list->last2k;
            aux->next = el;
            list->last2k = el;
        }
        else
        { // caso onde o elemento vai ser inserido no meio da lista
            stElement *iterableNode = createEl();
            iterableNode = list->source2k;
            while (iterableNode->next)
            { // percorre enquanto tiver proximo pois quando nao tiver mais é o ultimo
                if (iterableNode->next->value2k > el->value2k)
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
    else if (list->source90->value90 > el->value90)
    { // quando o elemento é menor que a raiz
        stElement *aux = createEl();
        aux = list->source90;
        list->source90 = el;
        list->source90->next = aux;
    }
    else
    { // casos onde não é mais necessário verificar a raiz
        if (el->value90 > list->last90->value90)
        { // verificando se é maior que o último elemento
            stElement *aux = createEl();
            aux = list->last90;
            aux->next = el;
            list->last90 = el;
        }
        else
        { // caso onde o elemento vai ser inserido no meio da lista
            stElement *iterableNode = createEl();
            iterableNode = list->source90;
            while (iterableNode->next)
            { // percorre enquanto tiver proximo pois quando nao tiver mais é o ultimo
                if (iterableNode->next->value90 > el->value90)
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

int main(void)
{
    stList *multiLinkList;
    multiLinkList = createList();
    stElement *el, *el1, *el2, *el3, *el4, *el5;
    el = createEl();
    el->name = "NY";
    el->value2k = 21199865;
    el->value90 = 19549649;
    el1 = createEl();
    el1->name = "LA";
    el1->value2k = 16373645;
    el1->value90 = 14531529;
    el2 = createEl();
    el2->name = "SF";
    el2->value2k = 7039362;
    el2->value90 = 6253311;
    el3 = createEl();
    el3->name = "MI";
    el3->value2k = 3876380;
    el3->value90 = 3192582;
    el4 = createEl();
    el4->name = "DE";
    el4->value2k = 2581506;
    el4->value90 = 1980140;
    el5 = createEl();
    el5->name = "SJ";
    el5->value2k = 2450292;
    el5->value90 = 2270808;
    insertIn2k(multiLinkList, el);
    insertIn2k(multiLinkList, el1);
    insertIn2k(multiLinkList, el2);
    insertIn2k(multiLinkList, el3);
    insertIn2k(multiLinkList, el4);
    insertIn2k(multiLinkList, el5);
    insertIn90(multiLinkList, el);
    insertIn90(multiLinkList, el1);
    insertIn90(multiLinkList, el2);
    insertIn90(multiLinkList, el3);
    insertIn90(multiLinkList, el4);
    insertIn90(multiLinkList, el5);
    printf("Organization in 2k: \n");
    showList2k(multiLinkList);
    printf("\nOrganization in 90: \n");
    showList90(multiLinkList);
    return 0;
}