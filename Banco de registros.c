#include <stdio.h>
#include <string.h>

void escreveRegistros(FILE *arq){
	
	char c, str[50], *token;
	
	c=fgetc(arq);
	
	while(c!=EOF){
		
		fread(str, c, 1, arq);
		str[c] = '\0';
		
		token = strtok(str, "|");
		
		while(token != 0){
			printf("%s\n", token);
		
			token = strtok(NULL, "|");
		}
	   
	   printf("\n");
	   
	   c=fgetc(arq);

	}
	
	rewind(arq);
}


void escreveEscolhido(FILE *arq, int aux){
	char c, str[50], *token;
	int i;
	
	for(i=0;i<aux-1;i++){
		c=fgetc(arq);
		fseek(arq,c,SEEK_CUR);
	}
	
	c=fgetc(arq);
	
	fread(str,c, 1, arq);
	
	str[c] = '\0';
	
	token = strtok(str, "|");
			
	while(token != 0){
			
		printf("\n%s", token);
		
		token = strtok(NULL, "|");
	}
}


int pedeNumero(void){
	int aux;
	
	printf("\nNumero de 1 a 10:");
	scanf("%d", &aux);
	
	while(aux<1||aux>10){
		
		printf("\nNumero invalido, tente de novo:");
		scanf("%d", &aux);
	}
	
	return aux;
}


int main(){
	
	FILE *arq = fopen("campo_var_reg_var.dad", "rb");
	
	if (arq == NULL){
		
		printf("ERRO!");
		return 0;
	}
	
	escreveRegistros(arq);
	
	escreveEscolhido(arq, pedeNumero());
	
	fclose(arq);
	
}
