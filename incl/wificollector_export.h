/**
*@author Carlos Condor
 *@date 2025-12-11
 *@file wificollector_export.h
 *@brief Declaracion de funciones para exportar archivos binarios a la lista
 */

#ifndef PROGRAMA_WIFICOLLECTOR_EXPORT_H
#define PROGRAMA_WIFICOLLECTOR_EXPORT_H

#include "wificollector_collect.h"

/**
 *@brief Declaracion de la funcion wificollector_export para ser usado en otros archivos
 * @param collector Parametro que accede a la lista con las celdas a exportar
 */
void wificollector_export(struct nodo_collectors *collector);

#endif //PROGRAMA_WIFICOLLECTOR_EXPORT_H