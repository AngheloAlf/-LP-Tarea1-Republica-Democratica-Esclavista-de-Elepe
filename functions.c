#include "functions.h"

int primerNumero(void){
	int character = getchar();
	return (int)(character-48);
}

char *leerComando(void){
	char *comando = malloc(sizeof(char) * LARGO);
	int character;
	int indice = 0;
	while((character = getchar()) != '\n'){
		comando[indice] = character;
		indice++;
		if(indice >= LARGO){
			break;
		}
	}
	comando[++indice] = '\0';
	return comando;
}

char *agregarDB(char *palabra){
	char *argumento = malloc(sizeof(char)*LARGO);
	strcpy(argumento, "db/");
	strcat(argumento, palabra);
	free(palabra);
	return argumento;
}

int charAInt(char *numero){
	int retornar = 0, indice = 0, multiplicar = 1;
	if(numero[0] == '-'){
		multiplicar = -1;
		indice = 1;
	}
	for(; indice < strlen(numero); indice++){
		retornar += (int)(numero[indice] - '0');
		retornar *= 10;
	}
	retornar /= 10;
	return retornar*multiplicar;
}
