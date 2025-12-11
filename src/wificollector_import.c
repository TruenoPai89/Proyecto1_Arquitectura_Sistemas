#include <stdlib.h>
#include <stdio.h>
#include "../incl/wificollector_import.h"

struct nodo_collectors* crear_nodo_archivo(FILE *f_archivo);
struct nodo_collectors* insertar_archivos(FILE *f,struct nodo_collectors* nodo_raiz);
struct nodo_collectors* concatenar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz);

void wificollector_import(struct nodo_collectors **collectors) {
    char nombre_archivo[SIZE_TEXT]="\0";
    char ruta_archivo[SIZE_TEXT]="\0";
    struct nodo_collector *nodo_aux=NULL;

    printf("Indique el nombre del fichero: ");
    scanf("%s",nombre_archivo);
    sprintf(ruta_archivo,"../bin/%s.bin",nombre_archivo);
    FILE *f_bin=fopen(ruta_archivo,"rb");

    if(f_bin==NULL) {
        printf("Error, no se encontro el archivo\n");
    }else {
        fseek(f_bin,0,SEEK_END);
        long tamano_archivo=ftell(f_bin);
        long numero_elementos=tamano_archivo/(long)sizeof(struct wificollector_collect);
        fseek(f_bin,0,SEEK_SET);
        nodo_aux=crear_nodo_archivo(f_bin);
        if(ftell(f_bin)!=tamano_archivo) {
            int f=1;
            for (long i = ftell(f_bin); i < tamano_archivo; i=i+(long)sizeof(struct wificollector_collect)) {
                fseek(f_bin,sizeof(struct wificollector_collect)*f,SEEK_SET);
                insertar_archivos(f_bin,nodo_aux);
                f++;
            }
        }
        fclose(f_bin);
        *collectors=concatenar(nodo_aux,*collectors);
    }
}

struct nodo_collectors* crear_nodo_archivo(FILE *f_archivo) {
    struct nodo_collectors *nuevo_nodo = calloc(1,sizeof(struct nodo_collectors));
    fread(&nuevo_nodo->inicio, sizeof(struct nodo_collectors), 1, f_archivo);
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

struct nodo_collectors* insertar_archivos(FILE *f,struct nodo_collectors* nodo_raiz) {
    struct nodo_collectors *nodo_aux1=nodo_raiz;
    if (nodo_aux1->siguiente==NULL) {
        nodo_aux1->siguiente=crear_nodo_archivo(f);
    }else {
        nodo_aux1->siguiente=insertar_archivos(f,nodo_aux1->siguiente);
    }
    return nodo_aux1;
}
struct nodo_collectors* concatenar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz) {
    struct nodo_collectors *nodo_aux1=nodo_raiz;
    struct nodo_collectors *nodo_aux2=nodo_nuevo;

    if (nodo_aux1==NULL) {
        nodo_aux1=nodo_aux2;
    }else if (nodo_aux1->siguiente==NULL){
        nodo_aux1=nodo_aux2;
    }else {
        nodo_aux1->siguiente=insertar(nodo_aux2,nodo_aux1->siguiente);
    }

    return nodo_aux1;
}


