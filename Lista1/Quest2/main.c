#include "Conj.h"

int main (void){

    stConj *conjzn = createConj();
    insert(conjzn, 1);
    insert(conjzn, 2);
    insert(conjzn, 3);
    insert(conjzn, 4);
    insert(conjzn, 5);
    insert(conjzn, 6);
    show(conjzn);

    return 0;
}