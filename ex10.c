#include <stdio.h>
#include <stdlib.h>

int cont =0;

int * expansao(int n, int * vet){

     int *result, aux=0;

     result = malloc (1);

     for(int i=0; i<n; i++){

          aux = aux + vet[i];

          result = realloc(result, aux * sizeof(int));

          for(int j=0; j < vet[i]; j++){
               result[cont] = vet[i];
               cont++;
          }

     }

     return result;
}


int main(){

     int n, *vetor;

     scanf("%d", &n);

     vetor = malloc (n * sizeof(int));

     for(int i=0; i<n; i++){

          scanf("%d", &vetor[i]);
     }


     vetor = expansao(n, vetor);

     for(int i=0; i<cont; i++){
          printf("%d ", vetor[i]);
     }

     free(vetor);
}
