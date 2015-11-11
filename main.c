#include "split.h" //arreglar warning de split.c
#include "nodes.h"
#include "unistd.h"


int tamanoArreglo(char *arreglo){
	int tamano;
	for(tamano = 0; tamano < LARGO; tamano++){
		if(arreglo[tamano] == '\0'){
			break;
		}
	}
	return tamano;
}

char *leerComando(){
	char *comando = malloc(sizeof(char) * LARGO);
	printf(">> ");
	int character = getchar();
	comando[0] = character;
	int indice = 1;
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

void leerConsola(void){
	int cantidadInstrucciones;
	scanf("%d", &cantidadInstrucciones);
	getchar();
	char *comando;

	for(int iteracion = 0; iteracion < cantidadInstrucciones; iteracion++){
		comando = leerComando();
		printf("%s\n", comando);
		printf("%d\n", tamanoArreglo(comando));
	}
}

void ejemplo(const char *alf){
	printf("hello %s!\n", alf);
}

int fileExists(const char *fname){
	if(access(fname, F_OK) != -1){
		return 1;
	}
	return 0;
}

int mensajeError(const char *palabra){
	if(!fileExists(palabra)){
		printf("\n\t[ERROR]\n\t\tNo se ha encontrado el archivo %s\n\t[ERROR]\n\n", palabra);
		return 1;
	}
	return 0;
}

void endExecution(const char *palabra){ //funcion 0;
	if(strcmp("noargs", palabra)){ //son distintas
		if(!mensajeError(palabra)){
			//abrir archivo
		}
	}
	exit(0);
}

int main(){
	printf("%d\n", fileExists("la wea weon qlo"));
	struct t_node *arbol = NULL;
	iniciarArbol(&arbol);
	size_t n_tokens1 = NULL, n_tokens2 = NULL, n_tokens3 = NULL, n_tokens4 = NULL, n_tokens5 = NULL;
	
	char a[] = "SAY MY NAME";
	char b[] = "HASTA LA VISTA BABY";
	char c[] = "OLA K ASE?";
	char d[] = "OLA WEON";
	char e[] = "MONO ALF WEA";

	char **frase1 = split(a, 11, ' ', &n_tokens1);
	char **frase2 = split(b, 19, ' ', &n_tokens2);
	char **frase3 = split(c, 10, ' ', &n_tokens3);
	char **frase4 = split(d, 8, ' ', &n_tokens4);
	char **frase5 = split(e, 12, ' ', &n_tokens5);
	
	agregarDatosArbol(&arbol, frase1, n_tokens1, ejemplo);
	agregarDatosArbol(&arbol, frase2, n_tokens2, ejemplo);
	agregarDatosArbol(&arbol, frase3, n_tokens3, ejemplo);
	agregarDatosArbol(&arbol, frase4, n_tokens4, ejemplo);
	agregarDatosArbol(&arbol, frase5, n_tokens5, ejemplo);

	llamarFuncionCallback(arbol, "alf", frase2, n_tokens2);
	llamarFuncionCallback(arbol, "alf", frase3, n_tokens3);
	llamarFuncionCallback(arbol, "alf", frase4, n_tokens4);
	llamarFuncionCallback(arbol, "alf", frase5, n_tokens5);
	llamarFuncionCallback(arbol, "alf", frase1, n_tokens1);

	freeArbol(&arbol);
/*
	printf("%s\n", arbol->children->data->word);
	printf("%s\n", arbol->children->data->children->data->word);
	printf("%s\n", arbol->children->data->children->data->children->data->word);

	printf("\n%s\n", arbol->children->next->data->word);
	printf("%s\n", arbol->children->next->data->children->data->word);
	printf("%s\n", arbol->children->next->data->children->data->children->data->word);
	printf("%s\n", arbol->children->next->data->children->data->children->data->children->data->word);

	printf("\n%s\n", arbol->children->next->next->data->word);
	printf("%s\n", arbol->children->next->next->data->children->data->word);
	printf("%s\n", arbol->children->next->next->data->children->data->children->data->word);

	printf("\n%s\n", arbol->children->next->next->data->word);
	printf("%s\n", arbol->children->next->next->data->children->next->data->word);

	printf("\n%s\n", arbol->children->next->next->next->data->word);
	printf("%s\n", arbol->children->next->next->next->data->children->data->word);
	printf("%s\n", arbol->children->next->next->next->data->children->data->children->data->word);
*/

//	leerConsola();
	return 0;
}