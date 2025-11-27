/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file main.c
 *@brief Archivo principal que contiene todas las funciones del programa
 *@brief Delcacracion de las cabeceras necesarias para el fucnionamiento del programa
 */
#include <stdio.h>
#include <stdlib.h>
#include "../incl/wificollector_collect.h"
#include "../incl/wificollector_quit.h"
#include "../incl/wificollector_delete_net.h"
#include "../incl/wificollector_display.h"
#include "../incl/wificollector_display_all.h"


/**
 * @brief Funcion principal donde se llaman a las funciones de otros archivos
 * @details Se usará un bucle do-while para poder ejecutar el programa las veces que el usuario desee, con un switch se podra seleccionar las diferentes
 * opciones que se mostraran por pantalla.
 */

int main() {
    char respuesta='\0';
    struct nodo_collectors *collectors=NULL;

    do {
        int option=0;

        printf("[2024] SUCEM S.L. Recolector de redes inalámbricas\n");
        printf("[ 1] wificollector_quit\n");
        printf("[ 2] wificollector_collect\n");
        printf("[ 3] wificollector_delete_net \n");
        printf("[ 4] wificollector_display\n");
        printf("[ 5] wificollector_display_all\n");
        printf("Ingrese un valor: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                wificollector_quit(&respuesta);
                break;
            case 2:
                wificollector_collect(&collectors);
                break;
            case 3:
                wificollector_delete_net(collectors);
                break;
            case 4:
                wificollector_display(collectors);
                break;
            case 5:
                wificollector_display_all(collectors);
                break;
            default:
                return 0;
        }
    }while(respuesta !='s' && respuesta!='S');
    free(collectors);
    return 0;
}
