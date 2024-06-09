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

void enqueue(stQueue *queue, void *el)
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
        if (isOperator(queue->array[i]))
        {
            printf("|%c", queue->array[i]);
        }
        else
        {
            printf("|%d", queue->array[i]);
        }
    }

    printf("\n");
}

void searchingResult(stQueue *queue)
{
    int twoInRow = 0;
    void *dequedOperator = NULL, *dequedNumber1 = NULL, *dequedNumber2 = NULL;
    bool haveOperator = false, haveApplied = false;

    for (queue->start; queue->start <= queue->end && queue->end < MAX; queue->start)
    {
        // showQueue(queue);
        if (isOperator(queue->array[queue->start]))
        { // quando sabemos que é operador
            if (haveOperator)
            { // se já tinha um operador antes, ele é inserido ao final
                enqueue(queue, dequedOperator);
            }
            if (dequedNumber1)
            { // remoção de numero no seguinte caso: apareceu um operador, em seguida veio um numero e logo depois outro operador
              // resumidamente, remove um numero entre dois operadores
                enqueue(queue, dequedNumber1);
                dequedNumber1 = NULL;
            }
            dequedOperator = dequeue(queue);
            haveOperator = true;
            haveApplied = false;
            twoInRow = 0; // reinicizalizando contagem de numeros depois de um operador e pegando um operador novo
        }
        else
        { // aqui vem somente os operandos
            if (twoInRow == 0 && haveOperator)
            { // ocorrencia de primeiro numero quando existe operador
                dequedNumber1 = dequeue(queue);
                twoInRow++;
            }
            else if (twoInRow == 1 && haveOperator)
            { // ja existindo um primeiro numero e um operador, faz operação e insere ao fim
                dequedNumber2 = dequeue(queue);
                queue->result = applyOperator(dequedOperator, dequedNumber1, dequedNumber2);
                enqueue(queue, queue->result);
                haveOperator = false;
                haveApplied = true;
                twoInRow = 0;
                dequedNumber1 = NULL;
                dequedNumber2 = NULL;
            }
            else
            { // caso onde acabou de ser feita uma operação e em seguida vem um outro numero
                if (haveApplied)
                {
                    dequedNumber1 = dequeue(queue);
                    enqueue(queue, dequedNumber1);
                }
            }
        }
    }
}

int main(void)
{
    stQueue *queue = createQueue();

    enqueue(queue, '-');
    enqueue(queue, '+');
    enqueue(queue, '*');
    enqueue(queue, 9);
    enqueue(queue, '+');
    enqueue(queue, 2);
    enqueue(queue, 8);
    enqueue(queue, '*');
    enqueue(queue, '+');
    enqueue(queue, 4);
    enqueue(queue, 8);
    enqueue(queue, 6);
    enqueue(queue, 3);
    showQueue(queue);
    searchingResult(queue);
    printf("The result was: %d\n", queue->result);
    return 0;
}