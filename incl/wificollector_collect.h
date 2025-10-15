/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_collect.h
 *@brief Declaracion de estructura collect y definicion de funciones
 */

#ifndef WIFICOLLECTOR_COLLECT_H
#define WIFICOLLECTOR_COLLECT_H

#define SIZE_TEXT 80
#define SIZE_ARRAY 200

/**
 *@struct wificollector_collect
 *@brief Estructura para almacenamiento de celdas
 *@param ncelda Número entero que guarda el numero de la celda
 *@param celda Nombre de la celda almacenada en texto
 *@param address Cadena de caracteres donde se almacenara el address
 *@param essid Cadena de caracteres donde se almacenara el essid
 *@param mode Cadena de caracteres donde se almacenara el mode
 *@param chanel Cadena de caracteres donde se almacenara el chanel
 *@param encryption Cadena de caracteres donde se almacenara encryption
 *@param quality Cadena de caracteres donde se almacenara quality
 *@param frecuency Cadena de caracteres donde se almacenara frecuency
 *@param signal_level Cadena de caracteres donde se almacenara signal_level
 *@details Aquí creamos la estructura de collectors que almacenara las celdas que nosostros queramos, este struct permitira guardar las diferentes partes
 *que contienen las diferentes celdas
 */
struct wificollector_collect {
    int ncelda;
    char celda[SIZE_TEXT];
    char address[SIZE_TEXT];
    char essid[SIZE_TEXT];
    char mode[SIZE_TEXT];
    char chanel[SIZE_TEXT];
    char encryption[SIZE_TEXT];
    char quality[SIZE_TEXT];
    char frecuency[SIZE_TEXT];
    char signal_level[SIZE_TEXT];
};

/**
 * Definimos un array de estructura de wificollector llamado collectors con un tamaño 21, aquí no se asigna memoria, solo se declara que esta variable
 * existe y está en otro archivo para asi poder manejar estos datos de collectors desde otros archivos.
 */
extern struct wificollector_collect collectors[SIZE_ARRAY];

/**
 *@brief Definicion de la funcion wifi_collect para ser usado en otros archivos
 */
void wificollector_collect(int *);


/**
 *@brief Implementacion de la funcion wificollector_collect para la visualizacion de celdas almacenadas por pantalla
 *@param collectors_aux Array de wificollector_collect donde se guardan las celdas
 *@param ncelda_aux Variable de control para comprobar si ya existe dicha celda
 *@return Numero de veces que existe dicha celda
 *@details Si existe alguna celda repetida el valor de retorno será mayor a cero, pero de no existir retornará cero y guardará la celda
 */
int controlador_celda_repetida(struct wificollector_collect collectors_aux[SIZE_ARRAY],int ncelda_aux);
#endif
