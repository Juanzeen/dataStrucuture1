typedef struct queueItems{
    void *data;
    struct queueItems *link;
} QueueItems;

typedef struct headQueue{
    QueueItems *firstNode, *lastNode;
    int size;
} HeadQueue;


void init(HeadQueue *head);
int empty(HeadQueue *head);
void enqueue(HeadQueue *head, void *data);
void *dequeue(HeadQueue *head);

void *firstElement (HeadQueue *head);
void *lastElement(HeadQueue *head);
int size(HeadQueue *head);
void freeEqueue(HeadQueue *head);