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
	}
	exit(0);
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
		printf("Se han insertado %d de %d registros (%d%%) satisfactoriamente.\n", contsi,contot,(contsi*100/contot));
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
				printf("LEYENDOELINPUT\n" );
				nomarch = agregarDB(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				
				else{
					printf("ELARCHIVOEXISTE\n");
					arch3=fopen("db/nuarch","w");
					while(fscanf(arch2," %[^\n]s",lineac)==1){
						if (cont==linea){
							printf("OMITIENDOLINEA\n");
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
			while(fscanf(arch1,"%s %d %s",nomarch,&linea,kiWord)==3){
				nomarch = agregarDB(nomarch);
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
		int ver;
		char *nomarch = malloc(sizeof(char) * LARGO), lineac[LARGO];
		int linea,cont=0;
		if (arch1==NULL){
			printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
		}
		else{
			while(fscanf(arch1,"%s %d",nomarch,&linea)==2){
				ver=0;
				nomarch = agregarDB(nomarch);
				arch2=fopen(nomarch,"r");
				if (arch2==NULL){
					printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
				}
				else{
					while(fscanf(arch2," %[^\n]s",lineac)==1){
						if (cont==linea){
							ver=1;
							printf(">>>%s\n",lineac);
							break;
						}
						cont++;
					}
					fclose(arch2);
				}
				if (!ver){printf(">>>NO SE PUDO MOSTRAR LINEA\n");}
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
				nomarch = agregarDB(nomarch);
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
	}
}

void mostrarDatosOrdenados(char *nombrearch){
	if(strcmp(nombrearch, "db/noargs")){

	}
}
