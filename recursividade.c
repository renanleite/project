#include <stdio.h>

void PosisaoHermione(int L_inicial, int C_inicial, int L, int C, char matriz[][C]){

          if(matriz[L_inicial+1][C_inicial]=='H' && (L_inicial+1)<L){           // baixo

               matriz[L_inicial+1][C_inicial] = '-';

               PosisaoHermione(L_inicial+1, C_inicial, L, C, matriz);
          }

          else if(matriz[L_inicial][C_inicial-1]=='H' && (C_inicial-1)>=0){          //esq

               matriz[L_inicial][C_inicial-1] = '-';

               PosisaoHermione(L_inicial, C_inicial-1, L, C, matriz);
          }

          else if(matriz[L_inicial-1][C_inicial]=='H' && (L_inicial-1)>=0){            //cima

               matriz[L_inicial-1][C_inicial] = '-';

               PosisaoHermione(L_inicial-1, C_inicial,L, C, matriz);
          }

          else if(matriz[L_inicial][C_inicial+1]=='H' && (C_inicial+1)<C){          //dir

               matriz[L_inicial][C_inicial+1] = '-';

               PosisaoHermione(L_inicial, C_inicial+1,L, C, matriz);
          }

          else{
               printf("%d %d", L_inicial+1, C_inicial+1);
          }

     return;
}

int main(){

     int L, C, L_inicial, C_inicial;

     scanf("%d %d", &L, &C);

     char matriz[L][C];

     for(int i=0; i<L; i++){
          for(int j=0; j<C; j++){
               scanf(" %c", &matriz[i][j]);
               if (matriz[i][j] == 'o'){
                    L_inicial = i;
                    C_inicial = j;
               }
          }
     }

     PosisaoHermione(L_inicial, C_inicial, L, C, matriz);

}

