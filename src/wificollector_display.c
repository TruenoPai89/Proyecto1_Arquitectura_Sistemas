/**
 *@file wificollector_display.c
 *@brief Implementacion de funciones para mostrar las celdas almacenadas
 *@author Carlos Condor
 *@date 2025-10-03
 */
#include <stdio.h>
#include "../incl/wificollector_display.h"      //Incluimos la cabecera de display.h donde definimos la funcion
#include "../incl/wificollector_collect.h"      //Incluimos la cabecera de collect.h donde estan nuestro arreglo de la estructura collect

/**
 *@brief Implementacion de funcion wificollector_diplay para mostrar las celdas recolectadas segun desee
 */
void wificollector_display() {
    char respuesta='s';     //Variable donde se almacena respuesta del usuario para seguir mostrando las celdas

    do {
        int ncell=0;
        printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21):  \n");
        scanf("%d",&ncell);
        if(ncell>=1 && ncell<=21) {
            if(collectors[ncell-1].celda!=0) {
                printf("Numero de celda: %d\n",collectors[ncell-1].celda);
                puts(collectors[ncell-1].texto);
            }else {
                printf("Numero de celda: %d\n",collectors[ncell-1].celda);
                printf("No existe informacion sobre la celda %d\n",ncell);
            }
            printf("Desea imprimir la informacion de otra celda? [s/N]: ");
            scanf(" %c",&respuesta);
        }else {
            printf("El numero de la celda es invalido\n");
        }
    } while(respuesta=='S'||respuesta=='s');
}
