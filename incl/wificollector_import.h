/**
*@author Carlos Condor
 *@date 2025-12-11
 *@file wificollector_import.h
 *@brief Declaracion de la funcion wificolllector_import
 */

#ifndef PROGRAMA_WIFICOLLECTOR_IMPORT_H
#define PROGRAMA_WIFICOLLECTOR_IMPORT_H

#define SIZE_TEX_BIN 500
#include "wificollector_collect.h"

/**
 * @brief Declaracion de la funcion wificollector_import para ser usada en otros archivos
 * @param collectors Puntero a puntero que va a la lista de redes para poder añadir las redes del archivo
 */
void wificollector_import(struct nodo_collectors **collectors);
#endif //PROGRAMA_WIFICOLLECTOR_IMPORT_H