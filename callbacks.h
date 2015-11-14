#ifndef CALLBACKS_H
#define CALLBACKS_H

#include <stdio.h>
#include "string.h"

void terminar_programa(char *nombrearch);
void insertar(char *nombrearch);
void eliminar_linea(char *nombrearch);
void eliminar_coincidencia(char *nombrearch);
void mostrar_por_linea(char *nombrearch);
void crear_archivo(char *nombrearch);
void eliminar_archivo(char *nombrearch);
void truncar_archivo(char *nombrearch);
void mostrarDatosOrdenados(char *nombrearch);

#endif