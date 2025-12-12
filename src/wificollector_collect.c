/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_collect.c
 *@brief Implementacion de funciones y de la estructura collectors
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../incl/wificollector_collect.h"


/**
 *@brief Implementacion de la funcion wificollector_collect
 *@param nodo Nodo que contiene las redes
 *@details Pasamos como parametro por referencia al nodo collectors para poder modificarlo en esta funcio void, con ello
 *podemos insertar nodos hayamos creado.
 */
void wificollector_collect(struct nodo_collectors **nodo) {

    struct wificollector_collect collector={0};
    char respuesta='s';         //Variable tipo caracter para guardar la respuesta del usuario

    do {
        int descripcion=0;              //Entero para guardar parte por parte el texto
        char linea[SIZE_TEXT]="\0";      //Array de caracteres para guardar las líneas del
        int ncelda=0;               //Variable tipo entero para guardar el número de celda que queremos
        char cell[SIZE_TEXT];              //Array de caracteres para guardar la ruta relativa de los archivos de texto que tiene la celda deseada

        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&ncelda);
        sprintf(cell,"../input_files/info_cell_%d.txt",ncelda);     //Funcion que permite crear una cadena de caracteres que se guardaran en cell con el formato especificado entre parentesis

        /**
         *En este bloque de condicional se maneja las celdas que esten ya repetidas
         */
        if (controlador_celda_repetida(*nodo,ncelda)!=0) {
            printf("Ya existe informacion de %d\n",ncelda);
        }else{
            /**
             *FILE *f permite manejar archivos creando un puntero en este caso *f que apuntara a un archivo
             *fopen permite abrir un archivo pasando como primer argumento su ruta ya sea absoluta o relativa
             *despues como segundo argumento le indicamos el modo en el que deseamos abrir el archivo en este caso de lectura
             */
            FILE *f=fopen(cell,"r");
            /**
             *Aqui manejaremos un error de manera sencilla con uso de condicionales, si el puntero 'f' no encunetra el archivo con la ruta que hemos
             *especificado, nos retornara un NULL y enviaremos un mensaje que el archivo no se ha abierto o no existe, caso contrario se ejecutara con
             *normalidad la otra parte del codigo
             */
            if(f==NULL) {
                printf("Error al abrir el archivo o archivo no existe\n");
            }
            else {
                /**
                 *En esta seccion del codigo usaremos primero fgets para ir leyendo linea por linea el archivo txt que se ha seleccionado
                 *previamente, el primer argumento es un array de caracteres que guradara las lineas de texto del archivo incluendo los saltos de linea
                 *luego como segundo argumento indicamos el tamaño maximo de lectura en este caso indicamos el tamaño del arreglo que teniamos y por ultimo
                 *como tercer argumento indicamos el archivo de donde vamos a leer
                 *A medida que se lee cada linea se ira guardando en cada parametro de collectors.
                 */

                while(fgets(linea,sizeof(linea),f)) {
                    if (descripcion==0) {
                        strcpy(collector.celda,linea);
                        descripcion++;
                        collector.ncelda=ncelda;
                    }else if (descripcion==1) {
                        strcpy(collector.address,linea);
                        descripcion++;
                    }else if (descripcion==2) {
                        strcpy(collector.essid,linea);
                        descripcion++;
                    }else if (descripcion==3) {
                        strcpy(collector.mode,linea);
                        descripcion++;
                    }else if (descripcion==4) {
                        strcpy(collector.chanel,linea);
                        descripcion++;
                    }else if (descripcion==5) {
                        strcpy(collector.encryption,linea);
                        descripcion++;
                    }else if (descripcion==6) {
                        strcpy(collector.quality,linea);
                        descripcion++;
                    }else if (descripcion==7) {
                        strcpy(collector.frecuency,linea);
                        descripcion++;
                    }else if (descripcion==8) {
                        strcpy(collector.signal_level,linea);
                        descripcion=0;
                        if (lista_vacia(*nodo)==0) {
                            *nodo=crear_nodo(collector);
                        }else {
                            struct nodo_collectors *nodo_aux=crear_nodo(collector);
                            *nodo=insertar(nodo_aux,*nodo);
                        }
                    }

                    linea[0]='\0';          //Ponemos el array línea como vacio para que guarde las nuevas líneas de texto

                }
                fclose(f);                      //Con fclose cerramos el archivo
            }
        }
        printf("Desea anadir otro punto de acceso? [s/N]: \n");     //Preguntamos si se desea añadir otra celda y leemos su respuesta
        scanf(" %c",&respuesta);
/**
*@details Con la ayuda del bucle do-while nos permitira recolectar las celdas que queramos hasta que el usuario indique lo contrario
*/
    } while(respuesta=='S'||respuesta=='s');
}


/**
 *@brief Funcion para controlar las celdas guardadas en el struct collectors
 *@param ncelda_aux Entero que lleva el número de celda que el usuario desea
 *@param lista Lista donde están las redes
 *@details La funcion recibe el struct y revisa si existe dicha celda recorriendo la lista una con la ayuda de un nodo auxiliar, cuando encuentra la coicidendia
 *devuelve un número que significara que ya existe dicha red
 */
int controlador_celda_repetida(struct nodo_collectors *lista,int ncelda_aux) {
    int controlador=0;
    struct nodo_collectors *nodo_aux;
    for (nodo_aux=lista;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {
        if (nodo_aux->siguiente!=NULL) {
            if (nodo_aux->inicio.ncelda==ncelda_aux) {
                controlador++;
            }
        }
    }
    return controlador;
}

/**
 * @brief Implementacion de la funcion crear_nodo
 * @param datos Estructura que ira dentro de nuestro nodo_collectors
 * @return Devuelve la dirreccion de memoria que se le ha asignado al nodo
 * @details Recibimos una estructura con todos los datos de una red y la asignamos a un nodo que tiene reservada memoria
 * una vez se asigna memoria se rellena los campos de inicio con la estructura y siguiente lo inicializamos como NULL ya
 * el siguiente nodo estara vacio
 */
struct nodo_collectors* crear_nodo(struct wificollector_collect datos) {
    struct nodo_collectors *nuevo_nodo = calloc(1,sizeof(struct nodo_collectors));

    nuevo_nodo->inicio=datos;
    nuevo_nodo->siguiente=NULL;
    return nuevo_nodo;
}

/**
 *@brief Implementacion de la funcion insertar
 * @param nodo_nuevo Nodo con nuevos datos a ser enlazados
 * @param nodo_raiz Nodo principal donde se almacena todos los datos
 * @return Regresa una dirreccion de memoria con los nodos enlazados
 * @details Recibimos como parametros 2 nodos, el principal y el nuevo, la funcion se apoya de un auxiliar que permite
 * recorrer la lista principal hasta llegar al final y asi enlazar los nuevos nodos
 */
struct nodo_collectors* insertar(struct nodo_collectors* nodo_nuevo,struct nodo_collectors* nodo_raiz) {
    struct nodo_collectors *nodo_aux1=nodo_raiz;

        if (nodo_aux1->siguiente==NULL) {
            nodo_aux1->siguiente=nodo_nuevo;
        }else {
            nodo_aux1->siguiente=insertar(nodo_nuevo,nodo_aux1->siguiente);
        }

    return nodo_aux1;
}

/**
 * @brief Implementacion de la funcion contar_elementos
 * @param lista Lista de redes
 * @return Devuelve un entero con el numerous de elementos
 */
int contar_elementos(struct nodo_collectors* lista) {
    int suma = 0;
    struct nodo_collectors* ptr;
    for(ptr = lista; ptr != NULL; ptr = ptr->siguiente){
        suma++;
    }
    return suma;
}

/**
 * @brief Implementacion de la funcion lista_vacia
 * @param nodo_inicial Nodo o lista de redes
 * @return Devuelve un entero que indicara si esta lista o nodo esta vacia
 * @details Recibimos un nodo o lista como parametro por valor y verificamos si el primer nodo es vacio, si es el caso retorna 0 indicando que
 * está sin datos, si no es asi retorna 1 y muestra que se encuentra con datos
 */
int lista_vacia(struct nodo_collectors *nodo_inicial) {
    if (nodo_inicial==NULL) {
        return 0;
    }else {
        return 1;
    }
}