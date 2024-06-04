

typedef struct queueItems{
    int data;
    struct queueItems *link;
} QueueItems;

typedef struct headQueue{
    QueueItems *firstNode, *lastNode;
    int size;
} HeadQueue;


void init(HeadQueue *head);

int empty(HeadQueue *head);
void enqueue(HeadQueue *head, int number);
void dequeue(HeadQueue *head);
int firstElement (HeadQueue *head);
int lastElement(HeadQueue *head);
int size(HeadQueue *head);
void freeEqueue(HeadQueue *head);

