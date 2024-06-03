#include <stdbool.h> 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void random_vector(int *vet, int size){
    srand(time(NULL)); 
    for(int i = 0; i < size; i++){
        vet[i] = rand()%100;
    }
}

void copy(int vet1[], int vetCopia[], int n){
   
   for (int i = 0; i<n; i++){
    vetCopia[i] = vet1[i];
   }
    
}

void vis_random(int *vet, int size){
    
    printf("******* VETOR ALEATORIO ********\n\n");
    
    for(int i = 0; i<size;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
}

void bubble_sort(int *vet,int  size){
    bool change;
    int comparacoes = 0, atribuicoes = 0;
    int aux;
     while (true) {
        change = false; 
        comparacoes ++;
        for (int j = 0; j < size; j++){
             comparacoes +=1;
            if (vet[j] > vet[j + 1]){
                aux = vet[j];
                vet[j] = vet[j + 1];
                vet[j+1]=aux;
                atribuicoes += 9;
                change = true;
            }
        }
        if (!change) {
            break;
        }
    }
    printf("\nO numero de comparacoes foi: %d", comparacoes);
    printf("\nO numero de atribuicoes foi foi: %d\n", atribuicoes);
}

void selection_sort(int *vet,int size){ 
    int x = 0,aux,comparacoes = 0,atribuicoes = 0;
    while (x < size){
       comparacoes ++;
       int menor = x;
       atribuicoes += 3;
        for(int i=x+1; i<size; i++){
            comparacoes ++;
            if (vet[menor]>vet[i]){ 
                menor = i;         // o selection sort vai pelo indice
                atribuicoes += 3;          // pegando o indice do menor elemento
            }
        }
        if (x != menor){     // se o elemento tiver o mesmo indice, nao tem pq haver troca
            aux = vet[x];
            vet[x] = vet[menor];
            vet[menor] = aux;
            atribuicoes += 9;
        }
        x += 1;
        
    }
    printf("\nO numero de comparacoes foi: %d", comparacoes);
    printf("\nO numero de atribuicoes foi foi: %d\n", atribuicoes);

}

void insertion_sort(int *vet, int size){
    int aux,next,comparacoes = 0,atribuicoes= 0;
    for (int i = 1; i<size; i++){
        comparacoes ++;
        next = i;
        while((next != 0) && (vet[next] < vet[next-1])){
            comparacoes ++;
            aux = vet[next];
            vet[next] = vet[next - 1];
            vet[next - 1] = aux;
            atribuicoes += 9;
            next -= 1;
        }
    }
    printf("\nO numero de comparacoes foi: %d", comparacoes);
    printf("\nO numero de atribuicoes foi foi: %d\n", atribuicoes);
}

void ordered_vector(int *vet, int size){ // para verificar a ordenacao
   
    printf("****** VETOR ORDENADO *******\n\n");
   
    for(int i = 0; i<size;i++){
        printf("| %d |\t", vet[i]);
    }
    printf("\n\n");
} 

int main (void){
  int vector_size, *vector, option;
  clock_t time;
  
  printf("Enter the size of the vector: ");
  scanf("%d", &vector_size);

  vector = (int *)malloc(vector_size * sizeof(int));
  int copia1[vector_size];
  int copia2[vector_size];

  if (vector){
    random_vector(vector,vector_size);
    copy(vector,copia1,vector_size);
    copy(vector,copia2,vector_size);
    
    printf("\n\n ***** BUBBLE SORT ****** \n");
    time = clock();
    bubble_sort(vector,vector_size);
    time = clock() - time;
    printf("Runtime %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));

    time = 0;
    printf("\n\n ***** SELECTION SORT ****** \n");
    time = clock();
    selection_sort(copia1,vector_size);
    time = clock() - time;
    printf("Runtime %lf", ((double)time)/((CLOCKS_PER_SEC/1000)));

    time = 0;
    printf("\n\n ***** INSERTION SORT ****** \n");
    time = clock();
    insertion_sort(copia2,vector_size);
    time = clock() - time;
    printf("Runtime %lf\n", ((double)time)/((CLOCKS_PER_SEC/1000)));
    

    
    
  }
      
  free(vector);

 return 0;

}