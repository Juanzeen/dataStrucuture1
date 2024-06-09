#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 50

typedef struct queue
{
    void *array[MAX];
    int start, end, result;
} stQueue;

stQueue *createQueue()
{
    stQueue *queue = (stQueue *)malloc(sizeof(stQueue));
    queue->start = 0;
    queue->end = 0;
    queue->result = 0;
    return queue;
}

void *dequeue(stQueue *queue)
{
    void *returningChar = queue->array[queue->start];
    queue->start++;
    return returningChar;
}

void enqueue(stQueue *queue, void* el)
{
    queue->array[queue->end] = el;
    queue->end++;
}


bool isOperator(void *el)
{
    char convertedEl = (char)el;
    switch (convertedEl)
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

int applyOperator(char operator, int n1, int n2)
{
    switch (operator)
    {
    case '+':
        return n1 + n2;
        break;

    case '-':
        return n1 - n2;
        break;

    case '*':
        return n1 * n2;
        break;

    case '/':
        return n1 / n2;
        break;

    default:
        return 0;
        break;
    }
}


void showQueue(stQueue *queue)
{
    for (int i = 0; i < queue->end; i++)
    {
        if(isOperator(queue->array[i])){
            printf("|%c", queue->array[i]);
        }else{
        printf("|%d", queue->array[i]);
        }
    }
}


void searchingResult(stQueue *queue)
{
    int twoInRow = 0, result;
    void *dequedOperator , *dequedNumber1 , *dequedNumber2 ;
    bool haveOperator = false;
    printf("iu");

    for (queue->start; queue->start <= queue->end && queue->end < MAX; queue->start)
    {
        if(queue->end == MAX){
            printf("EXPLODE PRAGA RUIM");
        }

        if (isOperator(queue->start))
        { // se for constatado que é um operador
            twoInRow = 0;
            dequedOperator = dequeue(queue);
            haveOperator = true;
            enqueue(queue, dequedNumber1);
        }
        else
        { // não é operador
        if(twoInRow == 0){
            dequedNumber1 = dequeue(queue);
            twoInRow++; // incrementa um para a conferencia se temos dois numeros seguidos
            }
        else if(twoInRow == 1){//as operações dependem de dois numeros, exceção para achar o segundo
            dequedNumber2 = dequeue(queue);
            twoInRow++;
            }
        }

        if (twoInRow == 2 && haveOperator && dequedNumber1 && dequedNumber2)
        {
            twoInRow = 0;
            haveOperator = false;
            queue->result = applyOperator(dequedOperator, dequedNumber1, dequedNumber2);
            printf("\nO resultado parcial é: %d\n", result);   
            enqueue(queue, queue->result);
        } else if(twoInRow == 0 && haveOperator){
            enqueue(queue, dequedOperator);
            haveOperator = false;
        }
    }

}

int main(void)
{
    stQueue *queue = createQueue();

    enqueue(queue, '+');
    enqueue(queue, '-');
    enqueue(queue, 8);
    enqueue(queue, 5);
    enqueue(queue, 2);
    showQueue(queue);    
    searchingResult(queue);
    return 0;
}