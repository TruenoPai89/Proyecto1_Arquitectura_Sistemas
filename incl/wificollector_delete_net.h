/**
*@author Carlos Condor
 *@date 2025-11-07
 *@file wificollector_delete_net.h
 *@brief Cabecera para declaracion de funciones
 */

#ifndef PROGRAMA_WIFICOLLECTOR_DELETE_NET_H
#define PROGRAMA_WIFICOLLECTOR_DELETE_NET_H

#include "wificollector_collect.h"
/**
 *@brief Declaracion de la funcion
 * @param collectors Entero con el tamaño del arreglo de collectors
 */
void wificollector_delete_net(struct nodo_collectors **collectors);


struct nodo_collectors* elminar_nodo(struct nodo_collectors *nodo_raiz,char essid[SIZE_TEXT]);
int coincidencias_essid(struct nodo_collectors *nodo_raiz,char essid[SIZE_TEXT]) ;

#endif //PROGRAMA_WIFICOLLECTOR_DELETE_NET_H