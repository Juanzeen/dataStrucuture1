#define STACKSIZE 10

typedef struct stack{
    int top;
    int stackItems[STACKSIZE];
} Stack;


void startStack(Stack *stack);
int empty(Stack *stack);
void push(Stack *stack, int number);
void pop(Stack *stack);
void topElement(Stack *stack);
void stackElementsRemoved(Stack *stack);
int sizeStack( Stack *stack);
void freeStack(Stack *stack);
 