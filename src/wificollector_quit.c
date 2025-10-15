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
 *@brief Funcion para cambiar la respuesta de la variable respuesta en main.c
 * @param prespuesta Dirreccion de memoria del caracter respuesta del archivo main.c
 */
void wificollector_quit(char *prespuesta) {

    char aux;

    printf("Esta seguro de que desea salir del programa? [s/N]:\n");
    scanf(" %c", &aux);
    *prespuesta = aux;
}