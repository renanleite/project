#include <stdio.h>

void copiarCabecalho(FILE *arq, FILE *novo){

     int aux = 0;
     char c;

     while(aux !=3){
          c = fgetc(arq);
          fputc(c, novo);

          if(c == '\n'){
               aux++;
          }
     }
}

void limiar(FILE *arq, FILE *lim){

     int limiar, pixel;

     printf("Valor do Limiar:\n");
     scanf("%d", &limiar);

     copiarCabecalho(arq, lim);


     while(fscanf(arq, "%d", &pixel) == 1){       //loop até o final do arquivo, recebendo cada valor da matriz do pgm

          if(pixel > limiar){
               fprintf(lim, "255 ");
          }

          else {
               fprintf(lim, "0 ");
          }
     }

     rewind(arq);
     fclose(lim);

}

void negativo(FILE *arq, FILE *neg){

     int pixel;

     copiarCabecalho(arq, neg);

     while(fscanf(arq, "%d", &pixel) == 1){    //loop até o final do arquivo, recebendo cada valor da matriz do pgm

         fprintf(neg, "%d ", 255-pixel);
     }

     rewind(arq);
     fclose(neg);

}

void histograma(FILE *arq, FILE *his){

     char c;
     int aux, pixel, vetor[256] = {0};

     //////////pula o cabecalho//////////////
     aux = 0;
     while(aux !=3){
          c = fgetc(arq);

          if(c == '\n'){
               aux++;
          }
     }
     ////////////////////////////////////////

     while(fscanf(arq, "%d", &pixel) == 1){       //loop até o final do arquivo, recebendo cada valor da matriz do pgm

          vetor[pixel]++;
     }

     for(int i=0; i<=255; i++){

          fprintf(his, "%d: %d\n", i, vetor[i]);
     }

     fclose(his);
}



int main(){

     FILE *arq, *lim, *neg, *his;

     arq = fopen("baboon.pgm", "r");

     if (arq == NULL){
          printf("Erro na leitura do arquivo!");
          return 0;
     }

     lim = fopen("baboon_limiarizado.pgm", "w");

     neg = fopen("baboon_negativado.pgm", "w");

     his = fopen("baboon_histograma.txt", "w");

     limiar(arq, lim);

     negativo(arq, neg);

     histograma(arq, his);

     fclose(arq);
}
