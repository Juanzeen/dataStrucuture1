#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void){
    int num, i;
     int *numsArray;
    printf("%s", "Digite um numero: ");
    scanf("%d", &num);
    numsArray = malloc(num*sizeof(int));
    srand(time(0));
    for(i = 0; i< num; i++){
        numsArray[i] = rand()%100;
    }
    for(i = 0; i< num; i++){
        printf("%s %d %s %d\n", "O", i+1, "numero sorteado foi: ", numsArray[i]);
    }
    return 0;
}