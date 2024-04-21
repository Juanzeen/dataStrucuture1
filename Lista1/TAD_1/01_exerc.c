#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct locadora{
   char nome_filme[50], genero[15];
   int ano_lanca;
} Filme;

void clearScreen() { // funcao para limpar o terminal
    system("clear"); 
 }

void aloca(Filme **locadora, int *ptr_totalF){
  (*locadora) = (Filme *)realloc(*locadora, (*ptr_totalF + 1)*sizeof(Filme));
  if ((*locadora) == NULL){
    printf("\nErro de alocação\n");
    exit(1);
  }
}

void verificacao_input(char *name){
  if ((strlen(name)>0) && (name[strlen(name) - 1] == '\n')){ // aspas simples pois é um caractere 
    name[strlen(name) - 1] = '\0';
  }

}

void consulta(Filme locadora[], int total_filmes){
     printf("\n ****** FILMES DISPONIVEIS ******\n\n");

     for(int i = 0; i < total_filmes; i++){
      printf("\n Filme %d\n", i);
      printf("\n Nome: %s", locadora[i].nome_filme);
      printf("\n Genero:  %s", locadora[i].genero);
      printf("\n ano de lancamento: %d\n", locadora[i].ano_lanca);
     }
}

void pesquisar( Filme *locadora, int total_entradas){
  char nome[50],op;
  int i = 0;
  printf("Digite o nome do filme que quer verificar se tem disponivel: ");
  fgets(nome,50,stdin);
  verificacao_input(nome);
  for(i = 0; i< total_entradas;i++){
    int tamanho_string = strcmp(locadora[i].nome_filme,nome); // funcao que compara duas strings caractere por caracter
    if(tamanho_string == 0){ // o resultado da strcmp é um inteiro. Se esse inteiro for igual 0, significa que as strings são iguais
      printf("\nFilme encontrado\n");
      printf("\nNome do filme: %s", locadora[i].nome_filme);
      printf("\nGenero do filme:  %s", locadora[i].genero);
      printf("\nAno de lancamento: %d\n", locadora[i].ano_lanca);
      break;
    }
    else {
      printf("\nFilme não encontrado!\n");
    }
  }
}

void excluir( Filme **locadora, int *total_entradas){
  char nome[50],op;
  int i = 0;
  printf("Digite o nome do filme quer alugar: ");
  fgets(nome,50,stdin);
  verificacao_input(nome);
  for(i = 0; i< *total_entradas;i++){
    int tamanho_string = strcmp((*locadora)[i].nome_filme,nome); 
    if(tamanho_string == 0){ 
      printf("\nFilme encontrado\n");
      printf("\nNome do filme: %s", (*locadora)[i].nome_filme);
      printf("\nGenero do filme:  %s", (*locadora)[i].genero);
      printf("\nAno de lancamento: %d\n", (*locadora)[i].ano_lanca);
      printf("\nDeseja alugar? [s] ou [n]: ");
      scanf("%c", &op);

      if(op == 's' || op == 'S'){
        (*locadora)[i]= (*locadora)[(*total_entradas) - 1]; //copiando o ultimo elemento para a posicao penultima
        (*total_entradas)--;
        aloca(locadora,total_entradas); // realloca com a quantidade atual dos filmes
      }
      break;
    }
    else {
      printf("\nFilme não encontrado!\n");
    }
  }
}

void alterar(Filme *locadora, int total_entradas){
  char nome[50],op;
  int i = 0;
  printf("Digite o nome do filme que quer alterar: ");
  fgets(nome,50,stdin);
  verificacao_input(nome);
  for(i = 0; i< total_entradas;i++){
    int tamanho_string = strcmp(locadora[i].nome_filme,nome); 
    if(tamanho_string == 0){ 
      printf("\nFilme encontrado\n");
      printf("\nNome do filme: %s", locadora[i].nome_filme);
      printf("\nGenero do filme:  %s", locadora[i].genero);
      printf("\nAno de lancamento: %d\n", locadora[i].ano_lanca);
      
      clearScreen();
      printf("\n*** Fazendo alteracao ***\n\n");
      printf("Digite o nome do filme: ");
      fgets(locadora[i].nome_filme,50,stdin);
      verificacao_input(locadora[i].nome_filme);
      printf("Digite o genero do filme: ");
      fgets(locadora[i].genero,50,stdin);
      verificacao_input(locadora[i].genero);
      printf("Digite o ano de lancamento: ");
      scanf("%d", &locadora[i].ano_lanca);
    
      break;
    }
    else {
      printf("\nFilme não encontrado!\n");
    }
  }
}

int main(void){
  Filme *locadora;
  int total_filmes = 0,opcao;

  locadora = (Filme*)malloc(sizeof(Filme)); // alocando para a posição 0 do vetor
  if (locadora == NULL){
   printf("Erro de alocacao");
   exit(1);  // funcao encerra o programa !!!
  }
  
  do {
    
    printf("\n****** Bem vindo a sua locadora de filmes ******\n\n");
    printf("[1]- Incluir filme na locadora\n");
    printf("[2]- Alterar um filme da locadora\n");
    printf("[3]- Consultar filme na locadora\n");
    printf("[4]- Pesquisar se um filme tem na locadora \n");
    printf("[5]- Alugar (Excluir) um filme na locadora\n");
    printf("[6]- SAIR\n\n");
    printf("Diga a opcao escolhida: ");
    scanf("%d", &opcao);
    getchar(); // funcao que le uma entrada no teclado e retorna essa entrada como tipo int

   switch (opcao)
   {
   case 1:
    aloca(&locadora, &total_filmes); // precisa passar o endereco mesmo a locadora sendo um vetor, pois tem ponteiro duplo
    printf("\n ***** INCLUSAO *****\n\n"); // preenche o vetor na posicao "total entradas", mas a alocacao libera mais um espaco
    printf("Digite o nome do filme: ");
    fgets(locadora[total_filmes].nome_filme, 50, stdin); // para preencher o nome nao precisa do &, pois o nome vai ser um array de caracteres.
    verificacao_input(locadora[total_filmes].nome_filme);
    printf("Digite o genero do filme: ");
    fgets(locadora[total_filmes].genero, 50, stdin);
    verificacao_input(locadora[total_filmes].genero);
    printf("Digite o ano de lancamento do filme: ");
    scanf("%d", &locadora[total_filmes].ano_lanca);

    total_filmes++;

    break;
   case 2:
    clearScreen();
    alterar(locadora, total_filmes);
    break;
   case 3:
    clearScreen();
    consulta(locadora,total_filmes);
    break;
   case 4:
    clearScreen();
    pesquisar(locadora, total_filmes);
    break;
   case 5:
    clearScreen();
    excluir(&locadora,&total_filmes);
    break;
   case 6:
      printf("\n Obrigado e volte sempre!!!");
      break;
   default:
     printf("\n Voce não digitou uma da opcoes possiveis");
    break;
   }

  } while(opcao != 6);


   return 0;
}