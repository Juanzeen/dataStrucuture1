#include "Functions.h"

int main(void)
{
    stList *multiLinkList;
    multiLinkList = createList();
    stElement *el, *el1, *el2, *el3, *el4, *el5;
    el = createEl();
    el = putInfos("NY", 21199865,19549649);
    el1 = createEl();
    el1 = putInfos("LA", 16373645, 14531529);
    el2 = createEl();
    el2 = putInfos("SF", 7039362, 6253311);
    el3 = createEl();
    el3 = putInfos("MI", 3876380, 3192582);
    el4 = createEl();
    el4 = putInfos("SL", 2603607, 2492525);
    el5 = createEl();
    el5 = putInfos("SJ", 2450292, 2270808);

    insertIn2k(multiLinkList, el2);
    insertIn2k(multiLinkList, el);
    insertIn2k(multiLinkList, el1);
    insertIn2k(multiLinkList, el4);
    insertIn2k(multiLinkList, el3);
    insertIn2k(multiLinkList, el5);
    insertIn90(multiLinkList, el3);
    insertIn90(multiLinkList, el1);
    insertIn90(multiLinkList, el);
    insertIn90(multiLinkList, el2);
    insertIn90(multiLinkList, el5);
    insertIn90(multiLinkList, el4);
    printf("Organization in 2k: \n");
    showList2k(multiLinkList);
    printf("\nOrganization in 90: \n");
    showList90(multiLinkList);
    return 0;
}