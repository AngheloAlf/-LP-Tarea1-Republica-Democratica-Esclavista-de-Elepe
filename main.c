#include "split.h" //arreglar warning de split.c
#include "nodes.h"


int tamanoArreglo(char *arreglo){
	int tamano;
	for(tamano = 0; tamano < LARGO; tamano++){
		if(arreglo[tamano] == '\0'){
			break;
		}
	}
	return tamano;
}

char *leerComando(){
	char *comando = malloc(sizeof(char) * LARGO);
	printf(">> ");
	int character = getchar();
	comando[0] = character;
	int indice = 1;
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

void leerConsola(void){
	int cantidadInstrucciones;
	scanf("%d", &cantidadInstrucciones);
	getchar();
	char *comando;

	for(int iteracion = 0; iteracion < cantidadInstrucciones; iteracion++){
		comando = leerComando();
		printf("%s\n", comando);
		printf("%d\n", tamanoArreglo(comando));
	}
}

int main(){
	struct t_node *arbol = NULL;
	printf("wea1\n");
	iniciarArbol(&arbol);
	printf("wea2\n");
	char **frase = malloc(sizeof(char*));
	frase[0] = malloc(sizeof(char) * LARGO);
	frase[0][0] = 'm';
	frase[0][1] = 'o';
	frase[0][2] = 'n';
	frase[0][3] = 'o';
	frase[0][4] = '\0';
	
	printf("wea3\n");
	agregarDatosArbol(&arbol, frase, 1);
	printf("wea4\n");
	printf("%s\n", arbol->children->data->word);
	printf("wea5\n");

//	leerConsola();
	return 0;
}