#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 7

typedef struct queue{
    char array[MAX];
    int start, end, result;
}stQueue;


stQueue *createQueue(){
    stQueue *queue = (stQueue *)malloc(sizeof(stQueue));
    queue->start = 0;
    queue->end = 0;
    queue->result = 0;
    return queue;
}

void showQueue(stQueue *queue){
    for(queue->start; queue->start < queue->end ; queue->start++){
        printf("|%c", queue->array[queue->start]);
    }
}

char dequeue(stQueue * queue){
    char returningChar = queue->array[queue->start];
    queue->start++;
    return returningChar;
}

void enqueue(stQueue *queue, char el){
    queue->array[queue->end] = el;
    queue->end++;
}

void fillQueue(stQueue *queue, int length){
    for(int i = 0; i < length; i++){
        printf("Put the %d operator or operand: ",i+1);
        scanf(" %c", queue->array[queue->end]);
        fflush(stdin);
        queue->end++;
    }
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
        return 0;
        break;
    }
}

int searchingResult(stQueue *queue){
    int twoInRow = 0, result = 0;
    stQueue *functionQueue;

    for(queue->start; queue->start < queue->end ; queue->start++){


        if(isOperator(queue->start)){//se for constatado que é um operador
            twoInRow = 0;
            char dequedOperator = dequeue(queue);     
        }else{//não é operador
            char dequedNumber = dequeue(queue);
            twoInRow++;//incrementa um para a conferencia se temos dois numeros seguidos
        }
    }
}

int main(void){
    stQueue *queue = createQueue();
    int operationLength = 0;
    //printf("Put here the operation length: ");
    //scanf("%d", &operationLength);
    //fillQueue(queue, operationLength);
    enqueue(queue, '+');
    enqueue(queue, '-');
    enqueue(queue, '*');
    enqueue(queue, '8');
    enqueue(queue, '5');
    enqueue(queue, '2');
    enqueue(queue, '1');
    showQueue(queue);

    return 0;
}