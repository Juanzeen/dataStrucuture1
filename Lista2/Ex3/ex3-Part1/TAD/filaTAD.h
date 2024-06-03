#define TAMANHOFILA 5

typedef struct fila{
    int head, tail; // head indica o indice do primeiro elemento da fila e tail indica o indice do ultimo elemento 
    int queueItems[TAMANHOFILA];
} Fila; 


void clearScreen();
int empty(Fila *fila);
void inicializando(Fila *fila);
void enqueue(Fila *fila, int number);
void dequeue(Fila *fila);
void showEqueue(Fila *fila);