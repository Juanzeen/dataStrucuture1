#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct subStringData{
    int reps;
    int addressesLength;
    int addresses[100];
}stSsData;

stSsData *createData()
{
    stSsData *data = (stSsData *)malloc(sizeof(stSsData));

    if (!data)
        return NULL;

    data->addressesLength = 0;
    data->reps = 0;
    return data;
}


char* recursiveShift(char *s1, char *s2, int index){
    if(index > strlen(s1)) return s2;
    else{
        s2[index] = s1[index + 1];
        index++;
    }
    return recursiveShift(s1, s2, index);
}

stSsData *recursiveCounter(char *stringP, char *substringP, int accChar, int indexSub, int indexString, stSsData *subData){
    char shiftedString[strlen(stringP) -1];
    int k = 0;

    if(strlen(stringP) <=0){
         return subData;
    }

    if(stringP[0] == substringP[indexSub]){
        accChar++;
        indexSub++;
    }else{
        accChar = 0;
        indexSub = 0;
    }

    if(accChar == strlen(substringP)){
        subData->reps++;
        subData->addresses[subData->addressesLength] = indexString - (strlen(substringP) - 1);
        subData->addressesLength++;
        indexSub = 0;
    }
      recursiveShift(stringP, shiftedString, 0);

        indexString++;
    return recursiveCounter(shiftedString, substringP, accChar, indexSub, indexString, subData);
}

void showIndex(stSsData *data){
    for(int i = 0; i < data->addressesLength; i++){
        if(i == data->addressesLength-1)
            printf("%d", data->addresses[i]);
        else
            printf("%d|", data->addresses[i]);
    }
}


int main (void){
    char *string = "Estrutura de dados é minha paixão dados e minha paixão são os dados";
    char *substring = "dados";
    stSsData *result = createData();
    result = recursiveCounter(string, substring, 0, 0, 0, result);
    printf("O total de repeticoes foi: %d", result->reps);
    printf("\nAs repeticoes ocorreram nas posicoes: ");
    showIndex(result);
    return 0;
}