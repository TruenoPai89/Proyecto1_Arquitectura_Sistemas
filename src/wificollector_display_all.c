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
void wificollector_display_all(struct nodo_collectors *collectors) {
    struct nodo_collectors *nodo_aux;
    for (nodo_aux=collectors;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {
        if (nodo_aux!=NULL) {
            puts(nodo_aux->inicio.celda);
            puts(nodo_aux->inicio.address);
            puts(nodo_aux->inicio.essid);
            puts(nodo_aux->inicio.mode);
            puts(nodo_aux->inicio.chanel);
            puts(nodo_aux->inicio.encryption);
            puts(nodo_aux->inicio.quality);
            puts(nodo_aux->inicio.frecuency);
            puts(nodo_aux->inicio.signal_level);
        }
    }
}