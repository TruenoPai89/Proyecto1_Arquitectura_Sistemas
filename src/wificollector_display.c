/**
 *@file wificollector_display.c
 *@brief Implementacion de funciones para mostrar las celdas almacenadas
 *@author Carlos Condor
 *@date 2025-10-03
 */
#include <stdio.h>
#include "../incl/wificollector_display.h"      //Incluimos la cabecera de display.h donde definimos la funcion
#include "../incl/wificollector_collect.h"      //Incluimos la cabecera de collect.h donde están nuestro arreglo de la estructura collect


/**
 *@brief Implementacion de funcion wificollector_diplay para mostrar las celdas recolectadas según desee
 */
void wificollector_display(int m_espacio_aux) {
    char respuesta='s';     //Variable donde se almacena respuesta del usuario para seguir mostrando las celdas

    do {
        int ncell=0;
        printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21):  \n");
        scanf("%d",&ncell);
        if(ncell>=1 && ncell<=21) {                                                              //Nos ayuda a controlar que los numero ingresados esten entre 1 y 21
            if (controlador_celda_repetida(collectors,ncell,m_espacio_aux)!=0) {        //Permite verificar si existe dicha celda o no
                for (int i=0; i<m_espacio_aux; i++) {                                            //Recorre el array de collector para impimir la celda seleccionada
                    if(collectors[i].ncelda==ncell) {
                        puts(collectors[i].celda);
                        puts(collectors[i].address);
                        puts(collectors[i].essid);
                        puts(collectors[i].mode);
                        puts(collectors[i].chanel);
                        puts(collectors[i].encryption);
                        puts(collectors[i].quality);
                        puts(collectors[i].frecuency);
                        puts(collectors[i].signal_level);
                    }
                }
            }else {
                printf("No existe informacion de la celda %d\n",ncell);
            }
            printf("Desea imprimir la informacion de otra celda? [s/N]: ");         //Controla el número de veces que se desea imprimir una celda
            scanf(" %c",&respuesta);
        }else {
            printf("El numero de la celda es invalido\n");
        }
    } while(respuesta=='S'||respuesta=='s');
}
