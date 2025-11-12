/**
*@author Carlos Condor
 *@date 2025-11-07
 *@file wificollector_delete_net.c
 *@brief Implementacion de funciones para eliminar una red
 */

#include "../incl/wificollector_delete_net.h"
#include "../incl/wificollector_collect.h"
#include <stdio.h>
#include <string.h>

/**
 *@brief Declaracion de la funcion
 * @param m_espacio_aux Entero con el tamaño del arreglo de collectors
 * @details La funcion wificollector_delete_net se encarga de eliminar una red que se encuentre en el arreglo collectors
 * mediante su ESSID, si no se encuentra la red no se realiza ninguna acción, para poder encontrar la red se usa un bucle
 * for para recorrer el array hasta el número que indique m_espacio_aux, con el uso de condicionales y la funcion strstr
 * nos aseguramos de encontrar a la red que coincida con el ESSID proporcionado, una vez se encuentra la celda, vamos desplazando
 * cada una de las celdas que existan después de la misma, empezamos a desplazarlo hacia la derecha y asi eliminamos la
 * celda querida y no dejamos un hueco vacio en el arreglo
 */
void wificollector_delete_net(int m_espacio_aux) {

    char respuesta='\0';

    do {
        int coincidencia=0;
        char essid[SIZE_TEXT]="\0";
        printf("Indique el ESSID (entre “”): \n");
        scanf("%s", essid);
        for (int i=0; i<m_espacio_aux; i++) {
            if (strstr(collectors[i].essid,essid)!=NULL) {
                printf("Eliminando la red %s\n",essid);
                coincidencia++;
            }
            if (coincidencia!=0 && collectors[i].ncelda!=0) {
                collectors[i]=collectors[i+1];
            }
        }
        printf("Desea eliminar otra red: ");
        scanf(" %c",&respuesta);
    }while (respuesta=='S'||respuesta=='s');
}
