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
	iniciarArbol(&arbol);
	char **frase = malloc(sizeof(char*) * 2);
	frase[0] = malloc(sizeof(char) * LARGO);
	frase[0][0] = 'm';
	frase[0][1] = 'o';
	frase[0][2] = 'n';
	frase[0][3] = 'o';
	frase[0][4] = '\0';
	frase[1] = malloc(sizeof(char) * LARGO);
	frase[1][0] = 'a';
	frase[1][1] = 'l';
	frase[1][2] = 'f';
	frase[1][3] = '\0';
	
	agregarDatosArbol(&arbol, frase, 2);
	printf("%s\n", arbol->children->data->word);
	printf("%s\n", arbol->children->data->children->data->word);


	frase[1][0] = 'w';
	frase[1][1] = 'e';
	frase[1][2] = 'o';
	frase[1][3] = 'n';
	frase[1][4] = '\0';
	printf("\n\n\n\n\n\nver desde aqui\n");
	agregarDatosArbol(&arbol, frase, 2);

	printf("\n%s\n", arbol->children->data->word);
	printf("%s\n", arbol->children->data->children->next->data->word);

//	leerConsola();
	return 0;
}