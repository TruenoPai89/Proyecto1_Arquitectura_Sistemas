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
void wificollector_display(struct nodo_collectors *collectors) {

    char respuesta='s';     //Variable donde se almacena respuesta del usuario para seguir mostrando las celdas

    do {
        struct nodo_collectors *nodo_aux;
        int ncell=0;
        printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21):  \n");
        scanf("%d",&ncell);
        if(ncell>=1 && ncell<=21) {                                                              //Nos ayuda a controlar que los numero ingresados esten entre 1 y 21
            if (controlador_celda_repetida(collectors,ncell)!=0) {        //Permite verificar si existe dicha celda o no
                for (nodo_aux=collectors;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {                                            //Recorre el array de collector para impimir la celda seleccionada
                    if(nodo_aux->inicio.ncelda==ncell) {
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
