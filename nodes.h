#ifndef NODES_H
#define NODES_H

#define LARGO 50

#include "stdlib.h"
#include "string.h"
#include "stdio.h"

struct l_node;

struct t_node{
	struct l_node *children;
	char *word;
	void (*callback)(const char *);
};

struct l_node{
	struct t_node *data;
	struct l_node *next;
};

void iniciarArbol(struct t_node **arbol);
void iniciarLista(struct l_node **lista);
void agregarPalabraHoja(struct t_node **hoja, char *palabra);
void agregarDatosArbol(struct t_node **arbol, char **frase, size_t n_tokens);
void agregarFuncionArbol(struct t_node **arbol, void (*callback)(const char *), char **frase, size_t n_tokens);

#endif // NODES_H
