#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct arrConjuntos stConj;

int *bubbleSort(int *arr, int size);
void show(stConj *conj);
stConj *createConj();
stConj *insert(stConj *conjP, int elP);
stConj *removeEl(stConj *conjP, int removeEl);
int hasEl(stConj *conjP, int srcEl);
int smaller(stConj *conjP);
int bigger(stConj *conjP);
stConj *intersection(stConj *conj1, stConj *conj2);
stConj *unionF(stConj *conj1, stConj *conj2);
stConj *difference(stConj *conj1, stConj *conj2);
void explodeSet(stConj *willBeExploded);