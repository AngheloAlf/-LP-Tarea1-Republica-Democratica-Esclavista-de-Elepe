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

struct l_node *recuAgregarDatos(struct l_node **lista, char **frase, int *iteracion){
	if((*lista)->data == NULL){
		printf("\t((*lista)->data == NULL) %d\n", *iteracion);
		//se crea el nodo hoja (arbol)
		//struct t_node *hojita = NULL;
		iniciarArbol(&((*lista)->data));
		
		//se le agrega la palabra correspondiente
		agregarPalabraHoja(&((*lista)->data), frase[*iteracion]);
		//se apunta al siguiente y se le asigna memoria
		//lista->data = hojita;
		iniciarLista(&((*lista)->data->children));
		return (*lista);
	}
	else{
		printf("\telse ((*lista)->data == NULL) %d\n", *iteracion);
		if((*lista)->data->word != NULL){
			printf("\t((*lista)->data->word != NULL) %d\n", *iteracion);
			if(!strcmp((*lista)->data->word, frase[*iteracion])){ //palabra almacenada igual a palabra
				printf("\t(!strcmp((*lista)->data->word, frase[*iteracion])) %d\n", *iteracion);
				if((*lista)->data->children == NULL){
					iniciarLista(&((*lista)->data->children));
				}
				if((*lista)->data->children->next == NULL){
					iniciarLista(&((*lista)->data->children->next));
				}
				++(*iteracion);
				(*lista)->data->children->next = recuAgregarDatos(&((*lista)->data->children->next), frase, iteracion);
				return (*lista);

			}
			else{
				printf("\telse (!strcmp((*lista)->data->word, frase[*iteracion])) %d\n", *iteracion);
				if((*lista)->data->children == NULL){
					iniciarLista(&((*lista)->data->children));
				}
				(*lista)->data->children = recuAgregarDatos(&((*lista)->data->children), frase, iteracion);
				return (*lista);
			}
		}
		else{
			printf("\telse ((*lista)->data->word != NULL) %d\n", *iteracion);
			
			agregarPalabraHoja(&((*lista)->data), frase[*iteracion]);
			//se apunta al siguiente y se le asigna memoria
			//lista->data = hojita;
			iniciarLista(&((*lista)->data->children));
			return (*lista);
			}
	}
	return NULL;
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
		printf("iteracion %d\n", iteracion);
		(*arbol)->children = recuAgregarDatos(&((*arbol)->children), frase, &iteracion);
	}
}

struct t_node *recuAgregarFuncion(struct t_node **arbol, void (*callback)(const char *), char **frase, size_t n_tokens, int iteracion){
	if((*arbol)->children->data != NULL){
		if(((*arbol)->children->data->word != NULL) && (!strcmp((*arbol)->children->data->word, frase[iteracion]))){
			if((iteracion+1) == n_tokens){
				(*arbol)->children->data->callback = callback;
			}
			else if((iteracion+1) < n_tokens){
				(*arbol)->children->data = recuAgregarFuncion(&((*arbol)->children->data), callback, frase, n_tokens, iteracion+1);
			}
			return (*arbol);
		}
	}
	if((*arbol)->children->next != NULL){
		if(((*arbol)->children->next->data != NULL) && ((*arbol)->children->next->data->word != NULL)){
			if(!strcmp((*arbol)->children->next->data->word , frase[iteracion])){
				if((iteracion+1) == n_tokens){
					(*arbol)->children->next->data->callback = callback;
				}
				else if((iteracion+1) < n_tokens){
					(*arbol)->children->next->data = recuAgregarFuncion(&((*arbol)->children->next->data), callback, frase, n_tokens, iteracion+1);
				}
				return (*arbol);
			}
		}
	}
	return (*arbol);
}

void agregarFuncionArbol(struct t_node **arbol, void (*callback)(const char *), char **frase, size_t n_tokens){
	(*arbol) = recuAgregarFuncion(arbol, callback, frase, n_tokens, 0);
}

void llamarFuncionCallback(struct t_node *arbol, const char *argumento, char **frase, size_t n_tokens){
	
}