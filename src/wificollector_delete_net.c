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
void wificollector_delete_net(struct nodo_collectors **collectors) {

    char respuesta='\0';
    do {
        char essid[SIZE_TEXT]="\0";
        int n_coincidencias=0;
        printf("Indique el ESSID (entre “”): ");
        scanf("%s", essid);
        n_coincidencias=coincidencias_essid((*collectors),essid);
        printf("Eliminando la red %s\n",essid);
        for (int i=0;i<n_coincidencias;i++) {
            (*collectors)=elminar_nodo((*collectors),essid);
        }
        printf("Desea eliminar otra red [s/N]: ");
        scanf(" %c",&respuesta);
    }while (respuesta=='S'||respuesta=='s');
}

struct nodo_collectors* elminar_nodo(struct nodo_collectors *nodo_raiz,char essid[SIZE_TEXT]) {
    struct nodo_collectors *nodo_aux=nodo_raiz;
    if (strstr(nodo_aux->inicio.essid,essid)!=NULL) {
        nodo_aux=nodo_aux->siguiente;
    }else {
        nodo_aux->siguiente=elminar_nodo(nodo_aux->siguiente,essid);
    }
    return nodo_aux;
}

int coincidencias_essid(struct nodo_collectors *nodo_raiz,char essid[SIZE_TEXT]) {
    struct nodo_collectors *nodo_aux;
    int coincidencias=0;
    for (nodo_aux=nodo_raiz;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {
        if (strstr(nodo_aux->inicio.essid,essid)!=NULL) {
            coincidencias++;
        }
    }
    return coincidencias;
}