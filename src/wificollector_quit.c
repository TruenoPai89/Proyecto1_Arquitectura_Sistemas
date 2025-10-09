/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_quit.c
 *@brief Definicion de la funcion wificollector_quit
 *@brief Definicion de las cabeceras necesarias
 */
#include "../incl/wificollector_quit.h"
#include <stdio.h>

/**
 *
 * @param prespuesta dirreccion de memoria del caracter respuesta del archivo main.c
 * @return el cambio en el caracter de respuesta de main.c
 */
char wificollector_quit(char *prespuesta) {

    char aux;

    printf("Esta seguro de que desea salir del programa? [s/N]:\n");
    scanf(" %c", &aux);
    *prespuesta = aux;
    return *prespuesta;
}