#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LENGTH  3

typedef struct stack {
    int top;
    char array[LENGTH];
}stStack;


void push(char el, stStack *stack){
    stack->top++;
    stack->array[stack->top] = el;
}

stStack *createStack(){
    stStack *stack = (stStack*)malloc(sizeof(stStack));
    stack->top = -1;
    return stack;
}

stStack *fillStack(char stringP[LENGTH]){
    stStack *newStack = createStack();
    for(int i = 0; i < LENGTH; i++){
    push(stringP[i], newStack);
    }

    return newStack;
}


char pop(stStack *stack){
    char poppedEl = stack->array[stack->top];
    stack->top--;

    return poppedEl;
}

stStack *copyStackReverse(stStack *stack1){
    stStack *newStack;
    newStack = createStack();
    while(stack1->top != - 1){
        char copiedElement = pop(stack1);
        push(copiedElement, newStack);
    }

    return newStack;
}


void show(stStack *stack){
    for(int i = 0; i < LENGTH; i++){
        if(i == LENGTH - 1) printf("%c|\n", stack->array[i]);
        else{
            printf("|%c|", stack->array[i]);
        }
    }
}

bool checkPalindrome(stStack *stack1, stStack *stack2){
    bool itsPalindrome = true;
    for(stack1->top; stack1->top >0; stack1->top-- && stack2->top--){

        char elstack1, elstack2;
        elstack1 = pop(stack1);
        elstack2 = pop(stack2);

        if(elstack1 == elstack2){
            itsPalindrome = true;
        }else{
            itsPalindrome = false;
            break;
        }
        
    }
    return itsPalindrome;
}

int main(void){
    stStack *stack1, *stack2, *auxStack;
    stack1 = createStack();//
    stack2 = createStack();
    auxStack= createStack();
    stack1 = fillStack("ana"); 
    auxStack = fillStack("ana");
    show(stack1);
    stack2 = copyStackReverse(auxStack);
    free(auxStack);
    show(stack2);
    printf("%s", checkPalindrome(stack1, stack2)? "true\n": "false\n");

return 0;
}