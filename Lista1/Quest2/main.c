#include "Conj.h"

int main (void){
//need some tests
    stConj *conjzn = createConj();
    stConj *conju = createConj();
    insert(conjzn, 2);
    insert(conjzn, 4);
    insert(conjzn, 3);

    insert(conju, 3);
    insert(conju, 4);
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

    printf("Checking if the conj1 has the 3 element: %s\n", hasEl(conju, 3)? "true" : "false");
    printf("Checking if the sets are equals: %s\n", checkEqual(conju, conjzn)? "true" : "false");

    explodeSet(conjzn);
    explodeSet(conju);
    return 0;
}