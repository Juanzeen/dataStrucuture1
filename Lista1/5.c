#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* recursiveShift(char *s1, char *s2, int index){
    if(index > strlen(s1)) return s2;
    else{
        s2[index] = s1[index + 1];
        index++;
    }
    return recursiveShift(s1, s2, index);
}

int recursiveCounter(char *stringP, char *substringP, int accChar, int accWord, int index){
    char shiftedString[strlen(stringP) -1];
    int k = 0;

    if(strlen(stringP) <=0){
         return accWord;
    }

    if(stringP[0] == substringP[index]){
        accChar++;
        index++;
    }else{
        accChar = 0;
        index = 0;
    }

    if(accChar == strlen(substringP)){
        accWord++;
        index = 0;
    }
      recursiveShift(stringP, shiftedString, 0);

    return recursiveCounter(shiftedString, substringP, accChar, accWord, index);
}


int main (void){
    char *string = "Estrutura de dados é minha paixão e minha paixão são os dados";
    char *substring = "dados";
    char stringteste[5];

    printf("A quantidade de repetições da substring foi: %d\n\n", recursiveCounter(string, substring,0,0,0));
    
    return 0;
}