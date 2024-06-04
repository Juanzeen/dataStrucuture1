
typedef struct node{
    int data;
    struct node *link;
}NODE;

int emptyList(NODE *head);
void startList(NODE *head);
void insertionBegin(NODE *head, int x);
void insertionEnd(NODE *head, int x);
void inserirOrdenado(NODE *head, int x);
void removeBegin(NODE *head);
void removeFinal(NODE *head);
void removeSpecific(NODE *head, int number);
void specificPosition(NODE *head, int position);
void showList(NODE *head);
void freeList(NODE *head);

