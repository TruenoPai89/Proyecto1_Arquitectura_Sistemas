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
 * @param m_espacio_aux Entero con el tamaño del arreglo collectors
 * @details La funcion imprimira todas las celdas que se encuentren guardadas en la estructura collectors con tamaño m_espacio_aux
 */
void wificollector_display_all(int m_espacio_aux) {

    for (int i = 0; i <= m_espacio_aux; i++) {
        if (collectors!=NULL) {
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
            continue;
        }
    }
}