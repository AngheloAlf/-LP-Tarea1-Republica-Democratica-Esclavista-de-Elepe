#include "split.h"

int main(){

//char **split(const char *phrase, const size_t length, const char delimiter, size_t *n_tokens);
	
	char nombre[] = {"Hola Mono!"};

	int valor = NULL;

	char **wea;
	size_t tamano = sizeof(nombre);
	wea = split(nombre, tamano, ' ', &valor);
    printf("alfe\n");

	int a;
	for(a = 0; a<valor; a++){
		printf("%s\n", wea[a]);
	}

	return 0;
}