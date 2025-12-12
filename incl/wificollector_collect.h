/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_collect.h
 *@brief Declaracion de estructura collect y definicion de funciones
 */

#ifndef WIFICOLLECTOR_COLLECT_H
#define WIFICOLLECTOR_COLLECT_H

#define SIZE_TEXT 80
/**
 *@brief Estructura para almacenamiento de celdas
 *@struct wificollector_collect
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
 * @brief Estructura de nodo_collectors
 * @param inicio Estructura wificollector_collect
 * @param siguiente Puntero que apunta al siguiente nodo
 * @details Estructura de nodo_collectors que contrendra a la estructura wificollector_collect y un puntero que va al siguiente nodo
 */
struct nodo_collectors {
    struct wificollector_collect inicio;
    struct nodo_collectors* siguiente;
};


/**
 *@brief Declaracion de la funcion wificollector_collect
 *@param nodo Nodo que contiene las redes
 */
void wificollector_collect(struct nodo_collectors **nodo);


/**
 *@brief Declaracion de la funcion para controlar las celdas guardadas en el struct collectors
 *@param ncelda_aux Entero que lleva el número de celda que el usuario desea
 *@param lista Lista donde están las redes
 */
int controlador_celda_repetida(struct nodo_collectors *lista,int ncelda_aux);  // cambiar

/**
 * @brief Declaracion de la funcion crear_nodo
 * @param datos Estructura que ira dentro de nuestro nodo_collectors
 * @return Devuelve la dirreccion de memoria que se le ha asignado al nodo
 */
struct nodo_collectors* crear_nodo(struct wificollector_collect datos);

/**
 * @brief Declaracion de la funcion contar_elementos
 * @param lista Lista de redes
 * @return Devuelve un entero con el numerous de elementos
 */
int contar_elementos(struct nodo_collectors* lista);

/**
 * @brief Declaracion de la funcion lista_vacia
 * @param nodo_inicial Nodo o lista de redes
 * @return Devuelve un entero que indicara si esta lista o nodo esta vacia
 */
int lista_vacia(struct nodo_collectors *nodo_inicial);

/**
 *@brief Declaracion de la funcion insertar
 * @param nodo_nuevo Nodo con nuevos datos a ser enlazados
 * @param nodo_raiz Nodo principal donde se almacena todos los datos
 */
struct nodo_collectors* insertar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz);
#endif
