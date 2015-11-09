#include "stdio.h"
#include "stdlib.h"

struct cola{
	struct cola *sig;
	char *dato;
};

void agregar(struct cola **ejemplo, char *palabra){
	struct cola *aux = malloc(sizeof(struct cola));
	aux->dato = malloc(sizeof(char)*10);
	aux->dato = palabra;
	aux->sig = *ejemplo;
	(*ejemplo) = aux;
}

int main(){
	struct cola *wea = NULL;
	char a[] = {"hola"};
	char b[] = {"mundo"};
	char c[] = {"alf"};
	agregar(&wea, a);
	agregar(&wea, b);
	agregar(&wea, c);
	printf("%s\n", wea->dato);
	printf("%s\n", wea->sig->dato);
	printf("%s\n", wea->sig->sig->dato);
	return 0;
}