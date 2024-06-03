#include <stdio.h>
#include <stdlib.h>

typedef struct nodePoly{
    int coefficient, degree;
    struct nodePoly *link;
} NodePoly;

int empty(NodePoly *head){
    return (head->link == NULL ) ? 1:0;
}

void node(NodePoly *head, int coef, int grau){
    NodePoly *newNode = (NodePoly*)malloc(sizeof(NodePoly));
    if(newNode){
        newNode->coefficient = coef;
        newNode->degree = grau;
        if(empty(head)){
            head->link = newNode;
            newNode->link = NULL;
        }
        else{
            NodePoly *currentNode = head->link;
            while(currentNode->link != NULL){
                currentNode = currentNode->link;
            }
            currentNode->link = newNode;
            newNode->link = NULL;
        }
    }

}


void showPoly(NodePoly *head){
    if(empty(head)){
        printf("\nA lista esta vazia\n");
        exit(1);
    }
    else{
        NodePoly *currentNode = head->link;
        while(currentNode != NULL){
            printf("%dx^%d\t", currentNode->coefficient, currentNode->degree);
            currentNode = currentNode->link;
        }
    }
}

void sumOfPoly(NodePoly *head1, NodePoly *head2, NodePoly *head3){

    NodePoly *aux1, *aux2;
    aux1 = head1->link;
    aux2 = head2->link;
    
    do{
        if(aux1 == NULL && aux2!= NULL){
            node(head3,aux2->coefficient,aux2->degree);
            aux2 = aux2->link;
        }
        else if(aux1 != NULL && aux2 == NULL){
            node(head3,aux1->coefficient,aux1->degree);
            aux1= aux1->link;
        }

        else if(aux1->degree == aux2->degree){
            int sum = aux1->coefficient + aux2->coefficient;
            node(head3, sum, aux1->degree);
            aux1 = aux1->link;
            aux2 = aux2->link;
        }
        else if(aux1->degree > aux2->degree){
            node(head3,aux1->coefficient,aux1->degree);
            aux1 = aux1->link;
        }  
        else{
            node(head3, aux2->coefficient,aux2->degree);
            aux2 = aux2->link;
        } 
    } while(!(aux1 == NULL && aux2 == NULL));
}



int main(void){

    NodePoly *poly1 = (NodePoly*)malloc(sizeof(NodePoly));
    NodePoly *poly2 = (NodePoly*)malloc(sizeof(NodePoly));
    NodePoly *poly3 = (NodePoly*)malloc(sizeof(NodePoly));

    int grau,x = 0;


    if(poly1 && poly2 && poly3){
        printf("----- polinomio 1 -----\n\n");
        printf("Digite o grau do polinomio: ");
        scanf("%d", &grau);
        while(grau >= x){
            printf("\n\n Digite o coeficiente da variavel de expoente %d: ", grau);
            int coef;
            scanf("%d", &coef);
            node(poly1, coef, grau);
            grau--;
        }

        printf("\n----- polinomio 2 -----\n\n");
        printf("Digite o grau do polinomio: ");
        scanf("%d", &grau);
        while(grau >= x){
            printf("\n\n Digite o coeficiente da variavel de expoente %d: ", grau);
            int coef;
            scanf("%d", &coef);
            node(poly2, coef, grau);
            grau--;
        }

        printf("\n\n");
        showPoly(poly1);
        printf("\n");
        showPoly(poly2);
        sumOfPoly(poly1,poly2,poly3);
        printf("\n");
        showPoly(poly3);
        
    }
    else{
        printf("\n Erro de alocacao\n");
    }

    return 0;
}