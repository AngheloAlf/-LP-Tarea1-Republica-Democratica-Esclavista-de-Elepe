#include "nodes.h"

void iniciarArbol(struct t_node **arbol){
	*arbol = malloc(sizeof(struct t_node));
	(*arbol)->children = NULL;
	(*arbol)->word = NULL;
	(*arbol)->callback = NULL;
}

void iniciarLista(struct l_node **lista){
	(*lista) = malloc(sizeof(struct l_node));
	(*lista)->data = NULL;
	(*lista)->next = NULL;
}

void agregarPalabraHoja(struct t_node **hoja, char *palabra){
	(*hoja)->word = malloc(sizeof(char) * LARGO);
	strcpy((*hoja)->word, palabra);
}

void agregarDatosArbol(struct t_node **arbol, char **frase, size_t n_tokens){
	printf("0\n");
	if(((*arbol)->word == NULL) && ((*arbol)->children == NULL) && ((*arbol)->callback == NULL)){ //El arbol no tiene nada aun
		//crear una hoja y le agregro la primera palabra
		printf("1\n");
		struct t_node *hojaArbol = NULL;
		printf("2\n");
		iniciarArbol(&hojaArbol);
		printf("3\n");
		agregarPalabraHoja(&hojaArbol, frase[0]);
		printf("4\n");

		//crear lista
		struct l_node *hijoLista = NULL;
		printf("5\n");
		iniciarLista(&hijoLista);
		printf("6\n");

		//se indexa el la hoja y la lista al arbol principal
		hijoLista->data = hojaArbol;
		printf("7\n");
		(*arbol)->children = hijoLista;
		printf("8\n");
	}
	/*
	int iteracion;
	for(iteracion = 0; )
	if(arbol->word == NULL){
		if((arbol->children != NULL) && (arbol->children->data != NULL)){

		}
	}*/

}