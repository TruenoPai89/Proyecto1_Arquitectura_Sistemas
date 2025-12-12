/**
*@author Carlos Condor
 *@date 2025-12-11
 *@file wificollector_export.c
 *@brief Implementacion de funciones para exportar archivos binarios a la lista
 */
#include <stdio.h>

#include "../incl/wificollector_export.h"

/**
 *@brief Implementacion de la funcion wificollector_export
 *@param collector Parametro que accede a la lista con las celdas a exportar
 *@details Recibimos como parametro por valor la lista collector, se pregunta el nombre con él se desea guardar, se abre
 *un archivo en modo escritura binaria, se verifica que se pueda crear dicho archivo, mediante un for recorremos el archivo
 *y empezamos a escribir, una vez terminado cerramos el mismo y mostramos la ruta donde se ha guardado
 */
void wificollector_export(struct nodo_collectors *collector) {
    char nombre_archivo[SIZE_TEXT];
    char ruta_completa[SIZE_TEXT];

    printf("Indique el nombre del fichero: ");
    scanf("%s", nombre_archivo); // Leemos el nombre

    sprintf(ruta_completa, "../bin/%s.bin", nombre_archivo);


    FILE *f = fopen(ruta_completa, "wb");

    if (f == NULL) {
        printf("Error: No se pudo crear el archivo en la ruta especificada.\n");
        return;
    }

    for (struct nodo_collectors *nodo_aux=collector;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {
        fwrite(&nodo_aux->inicio,sizeof(nodo_aux->inicio),1,f);
    }

    fclose(f);
    printf("Archivo guardado correctamente en %s\n",ruta_completa);
}