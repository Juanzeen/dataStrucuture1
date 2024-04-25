#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct aluno{
    int id_aluno;
    float cr;
} ALUNO;

typedef struct node{  // definindo um nó
    ALUNO *informacoes_aluno;
    struct node *link;
} NODE;


 void clearScreen() { // funcao para limpar o terminal
    system("clear"); 
 }


NODE *criacao_raiz(ALUNO *info_aluno){
    NODE *ptrnode; 
    ptrnode = (NODE *)malloc(sizeof(NODE));
    ptrnode->informacoes_aluno = info_aluno;
    ptrnode->link = NULL;  
    
    return ptrnode;
}


NODE *criacao_no(ALUNO *info_aluno, NODE *raiz){ // funcao que cria o nó em memoria
    NODE *iterativenode = raiz;    
    NODE *ptrnode;    // alocando os nós em memoria

    ptrnode = (NODE *)malloc(sizeof(NODE));
    ptrnode->informacoes_aluno = info_aluno;
    ptrnode->link = NULL;

    while(iterativenode->link != NULL){
        iterativenode = iterativenode->link;
    }
    
    iterativenode->link = ptrnode;
    return ptrnode;

}


void exibe(NODE *linkedList){
    int counter = 1;
    if(linkedList->link == NULL){
        printf("A lista esta vazia");
        return;
    }
    else{
        while(linkedList != NULL){
            printf("%ID do aluno %d: \n", linkedList->informacoes_aluno->id_aluno);
            printf("CR do aluno %f: \n", linkedList->informacoes_aluno->cr);
            printf("\n");
            counter+=1;
            linkedList = linkedList->link;
        }
    }
    printf("\n");
}


void comparacao(float cr1, float cr2, int contador){
    if(cr1 > cr2){
        printf("\n O aluno %d tem o maior CR: %.2f\n", contador - 1, cr1);
    }
    else if ( cr1 < cr2){
        printf("\n O aluno %d tem o maior CR: %.2f\n", contador, cr2);
    }
    else{
        printf("Ambos os alunos tem o mesmo CR\n");
    }
}


int main(void){
  int contador = 1, x= 0, id;
  float cr;
  bool temRaiz = 0;
  ALUNO *nova_informacao;
  ALUNO *atual_informacao;
  NODE *no, *raiz;

  while (x < 2){
    
    printf("\nDigite o ID do %d aluno: ", contador);
    scanf("%d", &id);
    printf("Digite o CR do %d aluno: ", contador);
    scanf("%f", &cr);
     
    if(!temRaiz){
    nova_informacao = (ALUNO *)malloc(sizeof(ALUNO));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;

    raiz = criacao_raiz(nova_informacao);  //OBS: struct já é um endereco de memoria, por isso nao precisa do *
    atual_informacao = raiz->informacoes_aluno;

    contador += 1;
    clearScreen();

    printf("Digite o ID do %d aluno: ", contador);
    scanf("%d", &id);
    printf("Digite o CR do %d aluno: ", contador);
    scanf("%f", &cr);

    nova_informacao = (ALUNO *)malloc(sizeof(ALUNO));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;


    raiz->link = criacao_no(nova_informacao, raiz); // criando outro nó no link do anterior;
    atual_informacao = raiz->link->informacoes_aluno;
    
    clearScreen();
    float cr_1 = raiz->informacoes_aluno->cr, cr_2 = raiz->link->informacoes_aluno->cr;
    int id_1 = raiz->informacoes_aluno->id_aluno, id_2 = raiz->link->informacoes_aluno->id_aluno;

    printf("****** INFORMAÇOES ******\n\n");
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador - 1,cr_1,id_1);
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador, cr_2,id_2);
    comparacao(cr_1,cr_2,contador);
    contador += 1;
    x += 1;
    temRaiz = true;

    }else{

     // ALUNO 1
    nova_informacao = (ALUNO *)malloc(sizeof(ALUNO));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;

    no = criacao_no(nova_informacao, raiz);  //OBS: struct já é um endereco de memoria, por isso nao precisa do *
    atual_informacao = no->informacoes_aluno;
    
        // ALUNO 2
    contador += 1;
    clearScreen();

    printf("Digite o ID do %d aluno: ", contador);
    scanf("%d", &id);
    printf("Digite o CR do %d aluno: ", contador);
    scanf("%f", &cr);

    nova_informacao = (ALUNO *)malloc(sizeof(ALUNO));
    nova_informacao->id_aluno = id;
    nova_informacao->cr = cr;


    no->link = criacao_no(nova_informacao, raiz); // criando outro nó no link do anterior;
    atual_informacao = no->link->informacoes_aluno;
    
    clearScreen();
    float cr_1 = no->informacoes_aluno->cr, cr_2 = no->link->informacoes_aluno->cr;
    int id_1 = no->informacoes_aluno->id_aluno, id_2 = no->link->informacoes_aluno->id_aluno;

    printf("****** INFORMAÇOES ******\n\n");
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador - 1,cr_1,id_1);
    printf("Informacoes do aluno %d: CR: %.2f e ID: %d\n", contador, cr_2,id_2);
    comparacao(cr_1,cr_2,contador);
    contador += 1;
    x += 1;
    }
    
  }
  
  exibe(raiz);
    return 0;
}