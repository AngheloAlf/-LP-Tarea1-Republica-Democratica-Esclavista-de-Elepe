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

size_t tamanoArreglo(char *arreglo){
	int tamano;
	for(tamano = 0; tamano < LARGO; tamano++){
		if(arreglo[tamano] == '\0'){
			break;
		}
	}
	return tamano;
}

char *agregarBD(char *palabra){
	char *argumento = malloc(sizeof(char)*LARGO);
	//la forma mas changa de la vida de hacerlo :c
	argumento[0] = 'd';
	argumento[1] = 'b';
	argumento[2] = '/';
	size_t indice, tamanoFrase = tamanoArreglo(palabra);
	for(indice = 0; indice < tamanoFrase; indice++){
		argumento[indice+3] = palabra[indice];
	}
	return argumento;
}
