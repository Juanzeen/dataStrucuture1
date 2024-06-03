#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h"

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

void consulta(Filme *locadora, int total_filmes){
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