#include "split.h" //arreglar warning de split.c
#include "nodes.h"


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

int main(){
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
//	llamarFuncionCallback(arbol, "alf", frase1, n_tokens1);
//	printf("%s\n", arbol->children->data->word);
//	printf("%s\n", arbol->children->data->children->data->word);

	//arbol->callback = ejemplo;
	//arbol->callback("alf");*/
/*	agregarFuncionArbol(&arbol, ejemplo, frase, 2);
	printf("\nllamar funcion\n");
	llamarFuncionCallback(arbol, "alf", frase, 2);

	frase[1][0] = 'w';
	frase[1][1] = 'e';
	frase[1][2] = 'o';
	frase[1][3] = 'n';
	frase[1][4] = '\0';
	agregarDatosArbol(&arbol, frase, 2);
	agregarFuncionArbol(&arbol, ejemplo, frase, 2);
*/
//	printf("\n%s\n", arbol->children->data->word);
//	printf("%s\n", arbol->children->data->children->next->data->word);


//	printf("\n\n\n\n");
//	arbol->children->data->children->next->data->callback("mono");
//	leerConsola();
	return 0;
}