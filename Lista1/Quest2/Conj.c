#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Conj.h"

typedef struct arrConjuntos
{
    int length;
    int els[100];
} stConj;

int *bubbleSort(int *arr, int size)
{
    int change;
    int aux;

    while (true)
    {
        change = false;
        for (int j = 0; j < size; j++)
        {
            if (arr[j] > arr[j + 1] && arr[j + 1])
            {
                aux = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = aux;
                change = true;
                j = 0;
            }
        }
        if (change == false)
        {
            break;
        }
    }

    return arr;
}

void show(stConj *conj)
{
    int i;
    printf("{");
    for (i = 0; i < conj->length; i++){
        if(i == conj->length - 1) {
            printf("%d", conj->els[i]);
            break;
        }
        printf("%d, ", conj->els[i]);
    }
    printf("}\n");
}

stConj *createConj()
{
    stConj *conj = (stConj *)malloc(sizeof(stConj));
    if (!conj)
        return NULL;
    conj->length = 0;
    return conj;
}

stConj *insert(stConj *conjP, int elP)
{
    conjP->els[conjP->length] = elP;
    conjP->length++;
    if (conjP->length > 0)
        bubbleSort(conjP->els, conjP->length);
    return conjP;
}

stConj *removeEl(stConj *conjP, int removeEl)
{
    stConj *conjWRemoved;

    conjWRemoved = createConj();

    for (int i = 0; i < conjP->length; i++)
    {
        if (conjP->els[i] != removeEl)
            insert(conjWRemoved, conjP->els[i]);
    }
    return conjWRemoved;
}

int hasEl(stConj *conjP, int srcEl)
{
    int has = 0;

    for (int i = 0; i < conjP->length; i++)
    {
        if (conjP->els[i] == srcEl)
        {
            has = 1;
            break;
        }
    }
    return has;
}

int smaller(stConj *conjP)
{
    return conjP->els[0];
}

int bigger(stConj *conjP)
{
    return conjP->els[conjP->length];
}

stConj *intersection(stConj *conj1, stConj *conj2)
{
     stConj *intersec = createConj();
    int itsEqual = 0;

    int bigger = conj1->length > conj2->length ? 1 : 2;

    if (bigger == 1)
    {
        for (int i = 0; i < conj1->length; i++)
        {
            itsEqual = 0; 
                for (int j = 0; j < conj2->length; j++)
                {
                    itsEqual = conj1->els[i] == conj2->els[j] ? 1 : 0;
                if (itsEqual){
                    insert(intersec, conj1->els[i]); 
                    break;
                    }
                }
        }
    }
    else
    {
        for (int i = 0; i < conj2->length; i++)
        {
            itsEqual = 0;
                for (int j = 0; j < conj1->length; j++)
                {
                    itsEqual = conj2->els[i] == conj1->els[j] ? 1 : 0;
                if (itsEqual){
                    insert(intersec, conj2->els[i]);
                    break;
                }
                }
        }
    }

    return intersec;
}

stConj *unionF(stConj *conj1, stConj *conj2)
{
    stConj *unit = createConj();
    int itsDifferent;

    int bigger = conj1->length > conj2->length ? 1 : 2;

    if (bigger == 1)
    {
        for (int i = 0; i < conj1->length; i++)
        {
            insert(unit, conj1->els[i]);
        }
        for (int i = 0; i < conj2->length; i++)
        {
            itsDifferent = 0;
            for (int j = 0; j < unit->length; j++)
            {
                itsDifferent = conj2->els[i] != unit->els[j] ? 1 : 0;
            }
            if (itsDifferent)
                insert(unit, conj2->els[i]);
        }
    }
    else
    {
        for (int i = 0; i < conj2->length; i++)
        {
            insert(unit, conj2->els[i]);
        }
        for (int i = 0; i < conj1->length; i++)
        {
            itsDifferent = 0;
            for (int j = 0; j < unit->length; j++)
            {
                itsDifferent = conj1->els[i] != unit->els[j] ? 1 : 0;
            }
            if (itsDifferent)
                insert(unit, conj1->els[i]);
        }
    }

    return unit;
}

stConj *difference(stConj *conj1, stConj *conj2)
{
    stConj *diff = createConj();
    int itsDifferent = 0;

    int bigger = conj1->length > conj2->length ? 1 : 2;

    if (bigger == 1)
    {
        for (int i = 0; i < conj1->length; i++)
        {
            itsDifferent = 0; 
                for (int j = 0; j < conj2->length; j++)
                {
                    itsDifferent = conj1->els[i] != conj2->els[j] ? 1 : 0;
                     
                     if (!itsDifferent){
                        break;
                     }
                }
                     if(itsDifferent)
                        insert(diff, conj1->els[i]); 
               
        }
    }
    else
    {
        for (int i = 0; i < conj2->length; i++)
        {
            itsDifferent = 0;
                for (int j = 0; j < conj1->length; j++)
                {
                    itsDifferent = conj2->els[i] != conj1->els[j] ? 1 : 0;
                    if (!itsDifferent){
                        break;
                     }
                }
                     if(itsDifferent)
                        insert(diff, conj2->els[i]); 
        }
    }

    return diff;
}

void explodeSet(stConj *willBeExploded){
    free(willBeExploded);
}

