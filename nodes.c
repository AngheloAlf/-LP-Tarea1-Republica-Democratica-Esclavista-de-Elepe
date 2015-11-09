#include "nodes.h"

void iniciarArbol(struct t_node **arbol){
	(*arbol) = malloc(sizeof(struct t_node));
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

struct l_node *recuAgregarDatos(struct l_node **lista, char **frase, *iteracion){
	if((*lista)->data == NULL){
		//se crea el nodo hoja (arbol)
		//struct t_node *hojita = NULL;
		iniciarArbol(&((*lista)->data));
		
		//se le agrega la palabra correspondiente
		agregarPalabraHoja(&((*lista)->data), frase[iteracion]);
		//se apunta al siguiente y se le asigna memoria
		//lista->data = hojita;
		iniciarLista(&((*lista)->data->children));
		return (*lista);
	}
	else{
		if((*lista)->data->word != NULL){
			if(!strcmp((*lista)->data->word, frase[iteracion])){ //palabra almacenada igual a palabra
				if((*lista)->data->children == NULL){
					iniciarLista(&((*lista)->data->children));
				}
				if((*lista)->data->children->next == NULL){
					iniciarLista(&((*lista)->data->children->next));
				}

				(*lista)->data->children->next = recuAgregarDatos((*lista)->data->children->next, frase, &(++iteracion));
			}
			else{
				if((*lista)->data->children == NULL){
					iniciarLista(&((*lista)->data->children));
				}
				(*lista)->data->children = recuAgregarDatos(&((*lista)->data->children), &frase[iteracion]);
				return (*lista);
			}
		}
		else{/*
			//se le agrega la palabra correspondiente
			agregarPalabraHoja(&(lista->data), frase[iteracion]);

			//se apunta al siguiente y se le asigna memoria
			lista = lista->data->children;
			iniciarLista(&lista);
			continue;*/
		}
	}
}

void agregarDatosArbol(struct t_node **arbol, char **frase, size_t n_tokens){
	struct l_node *lista = NULL;
	if((*arbol)->children == NULL){// primera ejecucion del arblo
		iniciarLista(&lista);
		(*arbol)->children = lista;
	}
	else{
		lista = (*arbol)->children;
	}

	for(int iteracion = 0; iteracion < n_tokens; iteracion++){
		(*arbol)->children = recuAgregarDatos(&((*arbol)->children), frase[iteracion], frase, &iteracion);
	}
}