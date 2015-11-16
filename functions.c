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
	//la forma mas changa de la vida para hacerlo :c
	argumento[0] = 'd';
	argumento[1] = 'b';
	argumento[2] = '/';
	size_t indice, tamanoFrase = tamanoArreglo(palabra);
	for(indice = 0; indice < tamanoFrase; indice++){
		argumento[indice+3] = palabra[indice];
	}
	argumento[indice+3] = '\0';
	return argumento;
}

int charAInt(char *numero){
	int retornar = 0, indice = 0, multiplicar = 1;
	if(numero[0] == '-'){
		multiplicar = -1;
		indice = 1;
	}
	for(; indice < tamanoArreglo(numero); indice++){
		retornar += (int)(numero[indice] - '0');
		retornar *= 10;
	}
	retornar /= 10;
	return retornar*multiplicar;
}
