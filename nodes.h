#ifndef NODES_H
#define NODES_H

#include "string.h"
#include "functions.h"

struct l_node;

struct t_node{
	struct l_node *children;
	char *word;
	void (*callback)(char *);
};

struct l_node{
	struct t_node *data;
	struct l_node *next;
};

//pide memoria para el arbol y sus partes las apunta a NULL
void iniciarArbol(struct t_node **arbol);
//pide memoria para la lista y sus partes las apunta a NULL
void iniciarLista(struct l_node **lista);
//pide memoria para la palabra (word) y le copia lo que contiene *palabra
void agregarPalabraHoja(struct t_node **hoja, char *palabra);

//funcion recursiva para agregar las palabras y la funcion al arbol
//no se recomienda usar
struct l_node *recuAgregarDatos(struct l_node **lista, char **frase, int iteracion, size_t n_tokens, void (*callback)(char *));
//funcion que recibe al **arbol, el arreglo de palabras, la cantidad de palabras y la funcion a agregar
//para agregar palabras/funciones al arbol hay que llamar a esta funcion
void agregarDatosArbol(struct t_node **arbol, char **frase, size_t n_tokens, void (*callback)(char *));

//no se recomienda usar
//funcion recursiva que recorre el arbol y llama a la funcion que encuentre
int llamarCallback(struct l_node *lista, char *argumento, char **frase, size_t n_tokens, int iteracion);
//funcion auxiliar que facilita el la ejecucion del codigo
int ejecutarFuncionArbol(struct t_node *arbol, char **frase, size_t n_tokens);

//funciones que liberan la memoria usada en el **arbol
//se recomienda llamar a freeArbol
void freeLista(struct l_node **lista);
void freeArbol(struct t_node **arbol);

#endif
