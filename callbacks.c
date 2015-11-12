#include "split.h"
#include "callbacks.h"
void terminar_programa(){
	exit(0);
}
void insertar(char *nombrearch){

}
void eliminar_linea(char *nombrearch){
	FILE *arch1,*arch2,*arch3;
	arch1=fopen(nombrearch,"r");
	char nomarch[50], lineac[256];
	int linea,cont=0;
	if (arch1==NULL){
		printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
	}
	else{
		while(fscanf(arch1,"%s %d",nomarch,&linea)==1){
			arch2=fopen(nomarch,"r");
			if (arch2==NULL) printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
			else{
				arch3=fopen("nuarch","w")
				while(fscanf(arch2,"%s",lineac)==1){
					if (cont==linea){
						continue;
					}
					fprintf(arch3, "%s\n",lineac );
					cont++;
				}
				remove(arch2);
				rename("nuarch",nomarch);
				fclose(arch2);
				fclose(arch3);
			}

		}
	}
	fclose(nombrearch);
}
void eliminar_coincidencia(char *nombrearch){

}
void mostrar_por_linea(char *nombrearch){
	FILE *arch1,*arch2;
	arch1=fopen(nombrearch,"r");
	char nomarch[50], lineac[256];
	int linea,cont=0;
	if (arch1==NULL){
		printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
	}
	else{
		while(fscanf(arch1,"%s %d",nomarch,&linea)==1){
			arch2=fopen(nomarch,"r");
			if (arch2==NULL) printf(">>>ARCHIVO %s NO EXISTE\n",nomarch);
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
		}
	fclose(nombrearch);
}
void crear_archivo(char *nombrearch){
	FILE *arch1,*arch2;
	arch1=fopen(nombrearch,"r");
	char nomarch[50];
	if (arch1==NULL){
		printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
	}
	else{
		while(fscanf(arch1,"%s",nomarch)==1){
			arch2=fopen(nomarch,"w");
			fclose(arch2);
			}
		}
	fclose(nombrearch);

}
void eliminar_archivo(char *nombrearch){
	FILE *arch1,*arch2;
	arch1=fopen(nombrearch,"r");
	char nomarch[50];
	if (arch1==NULL){
		printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
	}
	else{
		while(fscanf(arch1,"%s",nomarch)==1){
			arch2=fopen(nomarch,"r");
			if (arch2==NULL){
				printf(">>>ARCHIVO %s NO EXISTE\n", nomarch);
			}
			else{
				fclose(arch2);
				remove(arch2);

			}
		}
	}
	fclose(nombrearch);

}
void truncar_archivo(char *nombrearch){
	FILE *arch1,*arch2;
	arch1=fopen(nombrearch,"r");
	char nomarch[50];
	if (arch1==NULL){
		printf(">>>ARCHIVO %s NO EXISTE\n",nombrearch );
	}
	else{
		while(fscanf(arch1,"%s",nomarch)==1){
			arch2=fopen(nomarch,"w");
			if (arch2==NULL){
				printf(">>>ARCHIVO %s NO EXISTE\n", nomarch);
			}
			else{
				fclose(arch2);
			}
		}
	}
	fclose(nombrearch);
}