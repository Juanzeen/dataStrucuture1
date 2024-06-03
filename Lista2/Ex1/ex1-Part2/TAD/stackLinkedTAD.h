

typedef struct stack{
    int data;
    struct stack *link;
} Stack;


void startStack(Stack *stack);
int empty(Stack *stack);
void push(Stack *head, int x);
void pop(Stack *head);
void stackElementsRemoved(Stack *head);
void topElement(Stack *head);
void freeStack(Stack *head);