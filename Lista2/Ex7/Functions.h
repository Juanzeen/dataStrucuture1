#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct element stElement;
typedef struct list stList;

stElement *createEl();
stList *createList();
stElement *putInfos(char *name, int value2k, int value90);
void *insertIn2k(stList *list, stElement *el);
void insertIn90(stList *list, stElement *el);
void showList2k(stList *list);
void showList90(stList *list);