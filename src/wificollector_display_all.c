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
 * @details La funcion imprimira todas las celdas que se encuentren guardadas en la estructura collectors y de no existir imprimira que no existe
 *  información de la misma.
 */
void wificollector_display_all() {

    for (int i = 0; i <= 20; i++) {
        if (collectors[i].ncelda!=0) {
            puts(collectors[i].celda);
            puts(collectors[i].address);
            puts(collectors[i].essid);
            puts(collectors[i].mode);
            puts(collectors[i].chanel);
            puts(collectors[i].encryption);
            puts(collectors[i].quality);
            puts(collectors[i].frecuency);
            puts(collectors[i].signal_level);
        }else {
            //ncell=i;
            //printf("No hay informacion de la celda numero: %d\n",ncell+1);
        }
    }
}