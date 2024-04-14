#include "Conj.h"

int main (void){
//need some tests
    stConj *conjzn = createConj();
    stConj *conju = createConj();
    insert(conjzn, 2);
    insert(conjzn, 4);
    insert(conjzn, 5);
    insert(conjzn, 3);
    insert(conjzn, 6);

    insert(conju, 3);
    insert(conju, 8);
    insert(conju, 14);
    insert(conju, 2);

    show(conjzn);
    printf("The bigger: %d\n", bigger(conjzn));
    printf("The smaller: %d\n", smaller(conjzn));

    show(conju);
    printf("The bigger: %d\n", bigger(conju));
    printf("The smaller: %d\n", smaller(conju));


    stConj *myIntersection = intersection(conju, conjzn);
    stConj *myUnion = unionF(conju, conjzn);
    stConj *myDifference = difference(conju, conjzn);

    printf("The intersec: ");
    show(myIntersection);
    printf("The union: ");
    show(myUnion);
    printf("The difference: ");
    show(myDifference);

    printf("Checking if the conj1 has the 5 element (1 = true, 0 = false): %d", hasEl(conju, 5));

    explodeSet(conjzn);
    explodeSet(conju);
    return 0;
}