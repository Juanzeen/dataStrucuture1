

typedef struct stack{
    void *data;
    struct stack *link;
} StackElements;

typedef struct{   
    int count;
    StackElements *top;
} HeadStack; // pq "head"?" pois é atraves desta "cabeca" que iremos acessar a pilha


int empty(HeadStack *head);
void push(HeadStack *head, void *data);
void *pop(HeadStack *head);
void *elementTop(HeadStack *head);
//bool fullStack(HeadStack *head);
int totalElements(HeadStack *head);
HeadStack *freeStack(HeadStack *head);