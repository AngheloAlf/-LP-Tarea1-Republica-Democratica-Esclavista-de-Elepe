#include "split.h"
#include "nodes.h"
#include "unistd.h"
#include "callbacks.h"

size_t tamanoArreglo(char *arreglo){
	int tamano;
	for(tamano = 0; tamano < LARGO; tamano++){
		if(arreglo[tamano] == '\0'){
			break;
		}
	}
	return tamano;
}

int primerNumero(void){
	int character = getchar();
	return (int)(character-48);
}

char *leerComando(void){
	char *comando = malloc(sizeof(char) * LARGO);
	int character = getchar();
	int indice = 0;
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

void ejemplo(char *alf){
	printf("hello %s!\n", alf);
}

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
		comando = leerComando(); //se lee el resto del comando
		comandoProcesado = split(comando, tamanoArreglo(comando), ' ', &tamanoComandoProcesado); // se splitea

		//se agrega el comando y la funcion al arbol
		if(indiceFuncion < 8){
			agregarDatosArbol(&arbol, comandoProcesado, tamanoComandoProcesado, arregloCallbacks[indiceFuncion]);
		}
		if(indiceFuncion == 9){
			agregarDatosArbol(&arbol, comandoProcesado, tamanoComandoProcesado, arregloCallbacks[9]);
		}
	}

	return 0;
}