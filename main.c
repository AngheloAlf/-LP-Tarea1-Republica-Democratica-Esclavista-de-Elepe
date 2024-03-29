#include "split.h"
#include "nodes.h"
#include "unistd.h"
#include "callbacks.h"
#include "functions.h"

int main(){
	//se inicia el arbol
	struct t_node *arbol = NULL;
	iniciarArbol(&arbol);
	
	//se inicia el arreglo de funciones
	void (*arregloCallbacks[9])(char *arg);
	arregloCallbacks[0] = terminar_programa;
	arregloCallbacks[1] = insertar;
	arregloCallbacks[2] = eliminar_linea;
	arregloCallbacks[3] = eliminar_coincidencia;
	arregloCallbacks[4] = mostrar_por_linea;
	arregloCallbacks[5] = crear_archivo;
	arregloCallbacks[6] = eliminar_archivo;
	arregloCallbacks[7] = truncar_archivo;
	arregloCallbacks[8] = mostrarDatosOrdenados;
	
	//se inicializan variables
	int cantidadInstrucciones;
	scanf("%d", &cantidadInstrucciones);
	getchar();
	char *comando, **comandoProcesado;
	int indiceFuncion;
	size_t tamanoComandoProcesado;
	int iteracion;
	for(iteracion = 0; iteracion < cantidadInstrucciones; iteracion++){ //leyendo los comandos
		printf(">> ");
		indiceFuncion = primerNumero(); //se lee el numero de funcion
		getchar();
		comando = leerComando(); //se lee el resto del comando
		comandoProcesado = split(comando, strlen(comando), ' ', &tamanoComandoProcesado); // se splitea

		//se agrega el comando y la funcion al arbol
		if(indiceFuncion < 8){
			agregarDatosArbol(&arbol, comandoProcesado, tamanoComandoProcesado, arregloCallbacks[indiceFuncion]);
		}
		if(indiceFuncion == 9){
			agregarDatosArbol(&arbol, comandoProcesado, tamanoComandoProcesado, arregloCallbacks[9]);
		}
	}
	free(comando);
	free(comandoProcesado);

	printf("\n");

	char *comandoARealiar = NULL;
	char **comandoARealiarSpliteado;
	size_t tamanoComandoARealizar;
	int comandoExiste, iterandoArreglos;
	while(ejecucion){
		comandoExiste = 0;
		printf("> ");
		comandoARealiar = leerComando();
		
		if(strlen(comandoARealiar)>0){
			comandoARealiarSpliteado = split(comandoARealiar, strlen(comandoARealiar), ' ', &tamanoComandoARealizar);

			comandoExiste = ejecutarFuncionArbol(arbol, comandoARealiarSpliteado, tamanoComandoARealizar);
			
			if(!comandoExiste){
				printf(">>>No existe el comando [");
				for(iterandoArreglos = 0; iterandoArreglos<(tamanoComandoARealizar-1); iterandoArreglos++){
					printf("%s", comandoARealiarSpliteado[iterandoArreglos]);
					if(iterandoArreglos<tamanoComandoARealizar-2){
						printf(" ");
					}
				}
				printf("]\n");
			}
		}
		
	}
	free(comandoARealiar);
	free(comandoARealiarSpliteado);
	freeArbol(&arbol);
	return 0;
}