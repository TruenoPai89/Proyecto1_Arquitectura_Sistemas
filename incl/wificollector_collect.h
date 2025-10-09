/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_collect.h
 *@brief Declaracion de estructura collect y definicion de funciones
 */

#ifndef WIFICOLLECTOR_COLLECT_H
#define WIFICOLLECTOR_COLLECT_H

#define SIZE 1000

/**
 *@struct wificollector_collect
 *@brief Estructura para almacenamiento de celdas
 *@param celda Numero de la celda almacenada
 *@param texto Array donde se almacenara el texto del archivo a leer
 *Aqui creamos la estructura de collectors que tiene como parametros un int celda donde se guardara el numero de celda
 *y un array de caracteres que guardara el texto que la celda que se seleccione.
 */
struct wificollector_collect {
    int celda;
    char texto[SIZE];
};

/**
 * Definimos un array de estructura de wificollector llamado collectors con un tamaño 21, aqui no se asigna memoria, solo se declara que esta variable
 * existe y esta en otro archivo para asi poder manejar estos datos de collectors desde otros archivos.
 */
extern struct wificollector_collect collectors[21];

/**
 *@brief Definicion de la funcion wifi_collect para ser usado en otros archivos
 */
void wificollector_collect();
#endif
