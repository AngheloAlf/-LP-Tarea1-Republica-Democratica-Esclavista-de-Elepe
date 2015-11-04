#include "stdio.h"
#include "split.h" //arreglar warning de split.c
#include "nodes.h"

char *leerComando(){
	char *comando = malloc(sizeof(char) * 50);
	printf(">> ");
	int character = getchar();
	comando[0] = character;
	int indice = 1;
	while((character = getchar()) != '\n'){
		comando[indice] = character;
		indice++;
	}
	comando[++indice] = '\0';
	//printf("\n");
	return comando;
}

void leerConsola(void){
	int cantidadInstrucciones;
	scanf("%d", &cantidadInstrucciones);
	getchar();
	char *comando;

	for(int iteracion = 0; iteracion < cantidadInstrucciones; iteracion++){
		comando = leerComando();
		printf("%s\n", comando);
		int wea = sizeof(comando);
		printf("%d\n", wea);
	}
}

int main(){
	leerConsola();
	return 0;
}