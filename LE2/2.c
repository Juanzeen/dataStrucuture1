#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH  32

void copyStackReverse(char stack1[LENGTH], char stack2[LENGTH]){
    int i = 0, j = LENGTH - 1;
    for(i ; i < LENGTH; i++){
    stack2[i] = stack1[j];
    j--;
    }
}

void show(char stack[LENGTH]){
    for(int i = 0; i < LENGTH; i++){
        if(i < LENGTH) printf("%c |", stack[i]);
        else{
            printf("%c", stack[i]);
        }
    }
}

bool checkPalindrome(char stack1[LENGTH], char stack2[LENGTH]){
    int j = LENGTH - 1;
    bool itsPalindrome = true;
    for(j; j>0; j--){
        if(stack1[j] == stack2[j]){
            itsPalindrome = true;
        }else{
            itsPalindrome = false;
            break;
        }
    }
    return itsPalindrome;
}

int main(void){
    char myString[LENGTH] = "socorrammesubinoonibusemmarrocos"; //Socorram-me, subi no ônibus em Marrocos
    char auxArray[LENGTH];
    copyStackReverse(myString, auxArray);
    printf("%s", checkPalindrome(myString, auxArray)? "true\n": "false\n");

return 0;
}