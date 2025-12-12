/**
*@author Carlos Condor
 *@date 2025-12-11
 *@file wificollector_import.c
 *@brief Implementacion de funciones para importar archivos binarios a la lista
 */

#include <stdlib.h>
#include <stdio.h>
#include "../incl/wificollector_import.h"

/**
 * @brief Declaracion de una funcion interna crear_nodo_archivo de la funcion wificollector_import
 * @param f_archivo Puntero del archivo a leer en donde se encuentra los datos
 * @return Retorna una dirrección de memoria del nuevo nodo creado a partir de los datos del archivo bin seleccionado
 */
struct nodo_collectors* crear_nodo_archivo(FILE *f_archivo);

/**
 * @brief Declaracion de una funcion interna insertar_archivos de la funcion wificollector_import
 * @param f Puntero del archivo a leer en donde se encuentra los datos
 * @param nodo_raiz Nodo inicial que sirve de base para la union de nuevas celdas que esten en el archivo que apunta f
 * @return Retorna una nueva dirreccion de memoria con las celdas concatenadas
 */
struct nodo_collectors* insertar_archivos(FILE *f,struct nodo_collectors* nodo_raiz);

/**
 * @brief Declaracion de una funcion interna concatenar de la funcion wificollector_import
 * @param nodo_nuevo Nodo creado apartir de los archivos de que importamos
 * @param nodo_raiz Nodo principal donde se unira el nuevo nodo de los archivos
 * @return Retorna una dirreccion al nodo principal con los 2 nodos unidos
 */
struct nodo_collectors* concatenar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz);

/**
 * @brief Implementacion de la funcion wificollector_import
 * @param collectors Variable que apunta al puntero collector que tiene la dirreccion donde está la lista
 */
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

/**
 * @brief Implementacion de la funcion crear_nodo
 * @details Recibimos un archivo donde se encunetre las redes, asignamos memoria a un nuevo nodo que contendra los datos
 * de la celda y luego los rellenamos con los datos del archivo usando fread, inicializamos el nodo siguiente como vacio
 */
struct nodo_collectors* crear_nodo_archivo(FILE *f_archivo) {
    struct nodo_collectors *nuevo_nodo = calloc(1,sizeof(struct nodo_collectors));
    fread(&nuevo_nodo->inicio, sizeof(nuevo_nodo->inicio), 1, f_archivo);
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

/**
 * @brief Implementacion del codigo de la funcion interna insertar_archivo
 * @details Recibimos un archivo y el nodo donde se empezo la creacion de los nodos, luego con un nodo auxiliar empezamos
 * a recorrer la lista, una vez llegamos al siguiente se llama a crear nodo que nos devolvera una dirrecion con el nodo
 * creado, luego saldra y devolvera la dirreccion de la lista que estan concatenadas
 */
struct nodo_collectors* insertar_archivos(FILE *f,struct nodo_collectors* nodo_raiz) {
    struct nodo_collectors *nodo_aux1=nodo_raiz;
    if (nodo_aux1->siguiente==NULL) {
        nodo_aux1->siguiente=crear_nodo_archivo(f);
    }else {
        nodo_aux1->siguiente=insertar_archivos(f,nodo_aux1->siguiente);
    }
    return nodo_aux1;
}

/**
 * @brief Implementacion de la funcion interna concatenar
 * @details Pasamos como parametros a las listas nodo nuevo y el nodo raiz, luego empezamos a recorrer el nodo raiz con
 * la ayuda de un nodo auxiliar y una vez llegamos al final concatenamos el nodo raiz con el nuevo que tiene varias listas
 * ya enlazadas
 */
struct nodo_collectors* concatenar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz) {
    struct nodo_collectors *nodo_aux1=nodo_raiz;

    if (nodo_aux1==NULL) {
        nodo_aux1=nodo_nuevo;
    }else if (nodo_aux1->siguiente==NULL){
        nodo_aux1=nodo_nuevo;
    }else {
        nodo_aux1->siguiente=insertar(nodo_nuevo,nodo_aux1->siguiente);
    }

    return nodo_aux1;
}


