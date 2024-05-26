#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX  3

void copyStackReverse(char stack1[MAX], char stack2[MAX]){
    int i = 0, j = MAX - 1;
    for(i ; i < MAX; i++){
    stack2[i] = stack1[j];
    j--;
    }
}

void show(char stack[MAX]){
    for(int i = 0; i < MAX; i++){
        if(i < MAX) printf("%c |", stack[i]);
        else{
            printf("%c", stack[i]);
        }
    }
}

bool checkPalindrome(char stack1[MAX], char stack2[MAX]){
    int j = MAX - 1;
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
    char myString[MAX];
    char auxArray[MAX];
    scanf("%s", &myString);
    copyStackReverse(myString, auxArray);
    printf("%s", checkPalindrome(myString, auxArray)? "true\n": "false\n");

return 0;
}