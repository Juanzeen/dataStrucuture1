#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivo.h" 

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