#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 15

typedef struct queue{
    char array[MAX];
    int start, end, result;
}stQueue;

typedef struct stack {
    int top;
    char array[MAX];
}stStack;

stQueue *createQueue(){
    stQueue *queue = (stQueue *)malloc(sizeof(stQueue));
    queue->start = 0;
    queue->end = 0;
    queue->result = 0;
    return queue;
}

void showQueue(stQueue *queue){
    for(queue->start; queue->start < queue->end ; queue->start++){
        printf("%c -", queue->array[queue->start]);
    }
}

char dequeue(stQueue * queue){
    char returningChar = queue->array[queue->start];
    queue->start++;
    return returningChar;
}

stStack *createStack(){
    stStack *stack = (stStack*)malloc(sizeof(stStack));
    stack->top = -1;
    return stack;
}

void pushToStack(char el, stStack *stack){
    stack->top++;
    stack->array[stack->top] = el;
}

char popFromStack(stStack *stack){
    char poppedEl = stack->array[stack->top];
    stack->top--;
    return poppedEl;
}

bool isOperator(char el){
     switch (el)
    {
    case '+':
        return true;
        break;

    case '-':
        return true;
        break;

    case '*':
        return true;
        break;

    case '/':
        return true;
        break;
    
    default:
        return false;
        break;
    }

}

int applyOperator(char operator, char n1, char n2){
    switch (operator)
    {
    case '+':
        return (int)n1 + (int)n2;
        break;

    case '-':
        return (int)n1 - (int)n2;
        break;

    case '*':
        return (int)n1 * (int)n2;
        break;

    case '/':
        return (int)n1 / (int)n2;
        break;
    
    default:
        return NULL;
        break;
    }
}

void fillQueue(stQueue *queue){
    for(int i = 0; i < MAX; i++){
        scanf("%c", &queue->array[queue->end]);
        queue->end++;
    }
}

int searchingResult(stQueue *queue){
    stStack *operatorStack = createStack();
    stStack *numbersStack = createStack();
    int twoInRow = 0, result = 0;

    for(queue->start; queue->start < queue->end ; queue->start++){
        if(isOperator(queue->start)){//se for constatado que é um operador
            twoInRow = 0;
            char dequedOperator = dequeue(queue); 
            pushToStack(operatorStack, dequedOperator);//adiciona em uma pilha só para operadores
        }else{//não é operador
            char dequedNumber = dequeue(queue);
            pushToStack(numbersStack, dequedNumber);//manda para a pilha de numeros
            twoInRow++;//incrementa um para a conferencia se temos dois numeros seguidos
            if(twoInRow == 2){//se temos dois numeros seguidos, fazemos a operação de somar
                char operator, n1, n2;
                operator = popFromStack(operatorStack);
                n1 = popFromStack(numbersStack);
                n2 = popFromStack(numbersStack);
                result += applyOperator(operator, n1, n2);
                twoInRow = 1;
            }
        }
    }
}

int main(void){
    stQueue *queue = createQueue();
    fillQueue(queue);
    showQueue(queue);

    return 0;
}