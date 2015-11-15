#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LARGO 256

#include "stdlib.h"
#include "stdio.h"

int primerNumero(void);
char *leerComando(void);
//retorna el tamano de un arreglo caracteres de LARGO o menor tamano
size_t tamanoArreglo(char *arreglo);
char *agregarBD(char *palabra);

#endif