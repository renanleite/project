#include <stdio.h>
#include <ctype.h>

void filter(char *str, char c){

     int cont = 0;

     if(*str == c || *str == tolower(c)){

          while(*str != '\0'){
               cont++;
               *str = *(str+1);
               str = str + 1;
          }

          str = str-cont;
     }

     else{
     str = str+1;
     }

     if(*str == '\0'){
          return;
     }

     return filter(str, c);
}

int main(){

     char c, str[50];

     scanf("%c", &c);

     scanf(" %[^\n]%*c", str);

     filter(str, c);

     printf("%s", str);
}
