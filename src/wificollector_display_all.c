/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_display_all.c
 *@brief Declaracion de las cabecedras necesarias para imprimir las celdas
 */
#include "../incl/wificollector_display_all.h"
#include <stdio.h>
#include "../incl/wificollector_collect.h"

/**
 * @brief Deficion de la funcion wificollector_display_all
 * @details La funcion imprimira todos las celdas que se encuentren guardadas en la estructura collectors y de no existir imprimira que no existe
 * existe informacion de la misma.
 */
void wificollector_display_all() {

    int ncell=0;

    for (int i = 0; i <= 20; i++) {
        if (collectors[i].celda!=0) {
            puts(collectors[i].texto);
        }else {
            ncell=i;
            printf("No hay informacion de la celda numero: %d\n",ncell+1);
        }
    }
}