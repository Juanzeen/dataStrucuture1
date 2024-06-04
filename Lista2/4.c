#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 15

typedef struct queue{
    char array[15];
    int start, end, result;
}stQueue;

stQueue *createQueue(){
    stQueue *queue = (stQueue *)malloc(sizeof(stQueue));
    queue->start = 0;
    queue->end = 0;
    queue->result = 0;
    return queue;
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

char dequeue(stQueue * queue){
    char returningChar = queue->array[queue->start];
    queue->start++;
    return returningChar;
}

int searchingResult(stQueue *queue){
    for(int i = 0; i < MAX; i++){
        
    }
}

int main(void){
    stQueue *queue = createQueue();
    fillQueue(queue);


    return 0;
}