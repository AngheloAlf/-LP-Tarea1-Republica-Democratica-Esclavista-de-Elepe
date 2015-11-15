#include "callbacks.h"
#include "split.h"
#include "functions.h"

void terminar_programa(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO];
		int linea,cont=0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea)==1){
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					while(fscanf(arch2,"%s",lineac)==1){
						printf(">>>%s\n",lineac);
						cont++;
					}
					fclose(arch2);
				}
			}
			fclose(arch1);
		}
	}
	exit(0);
}

void insertar(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2,*arch3;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO], *rawLine = malloc(sizeof(char) * LARGO);
		int indice, linea, cont=0;
		size_t n_tokens, tamanoRaw = LARGO;
		char **inputLine = malloc(sizeof(char) * LARGO);

		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(!feof(arch1)){
				getline(&rawLine, &tamanoRaw, arch1);

				inputLine = split(rawLine, strlen(rawLine), ' ', &n_tokens);
				linea = (int)(inputLine[1][0] - '0');
				nomarch = inputLine[0];
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"r");

				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					arch3=fopen("bd/nuarch","w");
					while(fscanf(arch2,"%s",lineac)==1){
						if(cont==linea){
							for(indice = 2; indice < n_tokens; indice++){
								fprintf(arch2, "%s ", inputLine[indice]);
							}
							fprintf(arch2, "\n");
						}
						fprintf(arch3, "%s\n",lineac );
						cont++;
					}
					remove(nomarch);
					rename("bd/nuarch",nomarch);
					fclose(arch2);
					fclose(arch3);
				}

			}
			fclose(arch1);
		}
	}
}

void eliminar_linea(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2,*arch3;
		arch1 = fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO];
		int linea,cont=0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					arch3=fopen("bd/nuarch","w");
					while(fscanf(arch2,"%s",lineac)==1){
						if (cont==linea){
							continue;
						}
						fprintf(arch3, "%s\n",lineac );
						cont++;
					}
					remove(nomarch);
					rename("bd/nuarch",nomarch);
					fclose(arch2);
					fclose(arch3);
				}
			}
			fclose(arch1);
		}
	}
}

void eliminar_coincidencia(char *nombrearch){ //Base de eliminar lineas
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2,*arch3;
		arch1 = fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO], kiWord[LARGO];
		int linea;
		size_t n_tokens;
		char **inputLine = malloc(sizeof(char) * LARGO);
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d %s",nomarch,&linea,kiWord)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					arch3=fopen("bd/nuarch","w");
					while(fscanf(arch2," %[^\n]s",lineac)==1){ //Linea completa
						inputLine=split(lineac,strlen(lineac),' ',&n_tokens);
						if (!strcmp(inputLine[linea],kiWord)){
							continue;
						}
						fprintf(arch3, "%s\n",lineac );
					}
					remove(nomarch);
					rename("bd/nuarch",nomarch);
					fclose(arch2);
					fclose(arch3);
				}

			}
			fclose(arch1);
		}
	}
}

void mostrar_por_linea(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO];
		int linea,cont=0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					while(fscanf(arch2,"%s",lineac)==1){
						if (cont==linea){
							printf(">>>%s\n",lineac);
							break;
						}
						cont++;
					}
					fclose(arch2);
				}
			}
			fclose(arch1);
		}
	}
}

void crear_archivo(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO);
		if(arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s",nomarch)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"w");
				fclose(arch2);
				printf("ARCHIVO CREADO: %s\n", nomarch);
			}
			fclose(arch1);
		}
	}
}

void eliminar_archivo(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO);
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s",nomarch)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"r");
				if(arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n", nomarch);
				}
				else{
					remove(nomarch);
					fclose(arch2);
				}
			}
			fclose(arch1);
		}
	}
}

void truncar_archivo(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO);
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s",nomarch)==1){
				nomarch = agregarBD(nomarch);
				arch2=fopen(nomarch,"w");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n", nomarch);
				}
				else{
					fclose(arch2);
				}
			}
			fclose(arch1);
		}
	}
}

void mostrarDatosOrdenados(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){

	}
}
