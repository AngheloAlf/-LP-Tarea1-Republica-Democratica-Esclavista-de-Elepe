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

struct l_node *recuAgregarDatos(struct l_node **lista, char **frase, int iteracion, size_t n_tokens, void (*callback)(char *)){
	if(iteracion >= n_tokens){
		if((*lista) == NULL){
			iniciarLista(&(*lista));
		}
		if((*lista)->data == NULL){
			iniciarArbol(&((*lista)->data));
		}
		if((*lista)->data->callback == NULL){
			(*lista)->data->callback = callback;
		}
		return (*lista);
	}
	if((*lista) != NULL){
		if((*lista)->data != NULL){
			if((*lista)->data->word != NULL){
				if(!strcmp((*lista)->data->word, frase[iteracion])){ //son iguales
					(*lista)->data->children = recuAgregarDatos(&((*lista)->data->children), frase, iteracion+1, n_tokens, callback);
					return (*lista);
				}
				else{
					(*lista)->next = recuAgregarDatos(&((*lista)->next), frase, iteracion, n_tokens, callback);
					return (*lista);
				}
			}
			else{
				agregarPalabraHoja(&(*lista)->data, frase[iteracion]);
				return (*lista);
			}
		}
		else{
			iniciarArbol(&((*lista)->data));
			agregarPalabraHoja(&((*lista)->data), frase[iteracion]);
			(*lista)->data->children = recuAgregarDatos(&((*lista)->data->children), frase, iteracion+1, n_tokens, callback);
			return (*lista);
		}
	}
	else{
		iniciarLista(&(*lista));
		iniciarArbol(&((*lista)->data));
		agregarPalabraHoja(&((*lista)->data), frase[iteracion]);
		(*lista)->data->children = recuAgregarDatos(&((*lista)->data->children), frase, iteracion+1, n_tokens, callback);
		return (*lista);
	}
}

void agregarDatosArbol(struct t_node **arbol, char **frase, size_t n_tokens, void (*callback)(char *)){
	if((*arbol)->children == NULL){// primera ejecucion del arblo
		iniciarLista(&((*arbol)->children));
	}

	int wea;
	for(wea = 0; wea < n_tokens; wea++){
		(*arbol)->children = recuAgregarDatos(&((*arbol)->children), frase, 0, n_tokens, callback);
	}
	return;
}

void llamarCallback(struct l_node *lista, char *argumento, char **frase, size_t n_tokens, int iteracion){
	if(iteracion >= n_tokens){
		if(lista->data->callback != NULL){
			lista->data->callback(argumento);
		}
		return;
	}
	if(lista != NULL){
		if(lista->data != NULL){
			if(lista->data->word != NULL){
				if(!strcmp(lista->data->word, frase[iteracion])){ //son iguales
					llamarCallback(lista->data->children, argumento, frase, n_tokens, iteracion+1);
				}
				else{
					llamarCallback(lista->next, argumento, frase, n_tokens, iteracion);
				}
			}
		}
	}
}

void llamarFuncionCallback(struct t_node *arbol, char *argumento, char **frase, size_t n_tokens){
	llamarCallback(arbol->children, argumento, frase, n_tokens, 0);
}

void ejecutarFuncionArbol(struct t_node *arbol, char **frase, size_t n_tokens){
	llamarFuncionCallback(arbol, frase[n_tokens-1], frase, n_tokens-1);
}

void freeLista(struct l_node **lista){
	if((*lista) != NULL){
		if((*lista)->data != NULL){
			if((*lista)->data->word != NULL){
				free((*lista)->data->word);
			}
			if((*lista)->data->children != NULL){
				freeLista(&((*lista)->data->children));
				free((*lista)->data->children);
			}
			free((*lista)->data);
		}
		if((*lista)->next != NULL){
			freeLista(&((*lista)->next));
			free((*lista)->next);
		}
	}
}

void freeArbol(struct t_node **arbol){
	if((*arbol) != NULL){
		freeLista(&((*arbol)->children));
	}
	free((*arbol));
}