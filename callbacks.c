#include "callbacks.h"
#include "split.h"
#include "functions.h"

void terminar_programa(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1;
		arch1=fopen(nombrearch,"r");
		char *lineac = malloc(sizeof(char) * LARGO);
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fgets(lineac, LARGO, arch1) != NULL){
				printf("%s", lineac);
			}
			fclose(arch1);
		}
		free(lineac);
	}
	else{
		printf("\n");
	}
	ejecucion = 0;
	//exit(0);
}

void insertar(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2,*arch3;
		arch1=fopen(nombrearch,"r");
		char *nomarch = malloc(sizeof(char) * LARGO), *lineac  = malloc(sizeof(char) * LARGO), *rawLine = malloc(sizeof(char) * LARGO);
		int indice, linea, cont = 0,contsi = 0,contot = -1;
		size_t n_tokens, tamanoRaw = LARGO;
		char **inputLine = malloc(sizeof(char) * LARGO);

		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(!feof(arch1)){
				getline(&rawLine, &tamanoRaw, arch1);

				contot++;
				inputLine = split(rawLine, strlen(rawLine), ' ', &n_tokens);
				linea = charAInt(inputLine[1]);
				nomarch = inputLine[0];
				nomarch = agregarDB(nomarch);
				arch2 = fopen(nomarch, "r");

				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n", nomarch);
				}
				else{
					arch3 = fopen("db/nuarch.tmp", "w");
					cont = 0;
					if(linea >= 0){
						if(fgets(lineac, LARGO, arch2)){
							do{
								if(cont == linea){
									contsi++;
									for(indice = 2; indice < n_tokens; indice++){
										fputs(inputLine[indice], arch3);
										if(indice+1 != n_tokens){
											fputs(" ", arch3);
										}
									}
								}
								fputs(lineac, arch3);
								++cont;
							}while(fgets(lineac, LARGO, arch2));
						}
						else{
							contsi++;
							for(indice = 2; indice < n_tokens; indice++){
								fputs(inputLine[indice], arch3);
								if(indice+1 != n_tokens){
									fputs(" ", arch3);
								}
							}
						}
					}
					else{
						while(fgets(lineac, LARGO, arch2)){
							fputs(lineac, arch3);
						}
						contsi++;
						for(indice = 2; indice < n_tokens; indice++){
							fputs(inputLine[indice], arch3);
							if(indice+1 != n_tokens){
								fputs(" ", arch3);
							}
						}
						
					}
					fclose(arch2);
					fclose(arch3);
					remove(nomarch);
					rename("db/nuarch.tmp",nomarch);
				}

			}
			fclose(arch1);
		}
		if(contot <= 0){
			printf(">>>Se han insertado 0 de 0 registros (0%%) satisfactoriamente.\n");
		}
		else{
			printf(">>>Se han insertado %d de %d registros (%d%%) satisfactoriamente.\n", contsi,contot,(contsi*100/contot));
		}
		free(nomarch);
		free(lineac);
		free(rawLine);
		free(inputLine);
	}
}

void eliminar_linea(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1, *arch2, *arch3;
		arch1 = fopen(nombrearch, "r");
		char *nomarch = malloc(sizeof(char) * LARGO), *lineac = malloc(sizeof(char) * LARGO);
		int linea = 0, cont = 0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea) == 2){
				cont=0;
				
				nomarch = agregarDB(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				
				else{
					
					arch3=fopen("db/nuarch","w");
					while(fscanf(arch2," %[^\n]s",lineac)==1){
						if (cont==linea){
							
							printf(">>> %s\n",lineac );
							cont++;
							continue;
						}
						fprintf(arch3, "%s\n",lineac );
						
						cont++;
					}
					fclose(arch2);
					fclose(arch3);
					remove(nomarch);
					rename("db/nuarch", nomarch);
				}
			}
			fclose(arch1);
		}
		free(nomarch);
		free(lineac);
	}
}

void eliminar_coincidencia(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1, *arch2, *arch3;
		arch1 = fopen(nombrearch, "r");
		char *nomarch = malloc(sizeof(char) * LARGO), *lineac = malloc(sizeof(char) * LARGO), *kiWord = malloc(sizeof(char) * LARGO);
		int linea, a, indicePalabra, encontrado;
		size_t n_tokens;
		char **inputLine = malloc(sizeof(char) * LARGO);
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d %s",nomarch,&linea,kiWord) == 3){
				encontrado = 0;
				
				nomarch = agregarDB(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				
				else{
					
					arch3=fopen("db/nuarch","w");

					while(fscanf(arch2," %[^\n]s",lineac)==1){
						inputLine=split(lineac,strlen(lineac),' ',&n_tokens);
						if (linea<n_tokens){
							if (!strcmp(inputLine[linea],kiWord)){
								printf("Se elimino [");
								for(indicePalabra = 0; indicePalabra < n_tokens; indicePalabra++){
									printf("%s", inputLine[indicePalabra]);
									if(indicePalabra+1 < n_tokens){
										printf(" ");
									}
								}
								printf("] de %s satisfactoriamente.\n", nomarch);
								encontrado = 1;
								continue;
							}
						}
						for (a=0;a<n_tokens;a++){
							fprintf(arch3,"%s",inputLine[a] );
							if (a+1!=n_tokens){fprintf(arch3," ");}
						}
						fprintf(arch3,"\n");
					}
					if(!encontrado){
						printf("No existe %d: %s en %s.\n", linea, kiWord, nomarch);
					}
					fclose(arch2);
					fclose(arch3);
					remove(nomarch);
					rename("db/nuarch", nomarch);
				}
			}
			fclose(arch1);
		}

		free(nomarch);
		free(lineac);
		free(kiWord);
		free(inputLine);
	}
}

void mostrar_por_linea(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){
		FILE *arch1,*arch2;
		arch1=fopen(nombrearch,"r");
		int ver;
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO];
		int linea, cont = 0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea)==2){
				cont = 0;
				ver = 0;
				nomarch = agregarDB(nomarch);
				arch2 = fopen(nomarch, "r");
				if (arch2 == NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					while(fscanf(arch2," %[^\n]s",lineac)==1){
						if(cont == linea){
							ver=1;
							printf(">>>%s\n",lineac);
							break;
						}
						cont++;
					}
					fclose(arch2);
				}
				if(!ver){
					printf(">>>NO SE PUDO MOSTRAR LINEA\n");
				}
			}
			fclose(arch1);
		}
		free(nomarch);
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
				nomarch = agregarDB(nomarch);
				arch2=fopen(nomarch,"w");
				fclose(arch2);
				printf("ARCHIVO CREADO: %s\n", nomarch);
			}
			fclose(arch1);
		}
		free(nomarch);
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
				nomarch = agregarDB(nomarch);
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
		free(nomarch);
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
				nomarch = agregarDB(nomarch);
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
		free(nomarch);
	}
}

void mostrarDatosOrdenados(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){

	}
}
