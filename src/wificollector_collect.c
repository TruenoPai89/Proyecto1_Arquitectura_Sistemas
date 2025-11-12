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

struct wificollector_collect *collectors=NULL;

/**
 *@brief Definicion de la funcion wificollector_collect
 * @param posicion_celda Dirreccion de memoria de la variable posicion_celda en main.c
 * @param m_espacio_aux Dirreccion de memoria de la variable m_espacio en main que actualiza el tamaño que tiene el arreglo
 */
void wificollector_collect(int *posicion_celda, int *m_espacio_aux) {
    /**
     *En este condicional nos permitira reservar el espacio de memoria una sola vez
     */
    if ((*posicion_celda)==0) {
        collectors= malloc(sizeof(struct wificollector_collect)*(*m_espacio_aux));
    }

    char respuesta='s';         //Variable tipo caracter para guardar la respuesta del usuario

    do {
        int descripcion=0;              //Entero para guardar parte por parte el texto
        char linea[SIZE_TEXT]="\0";      //Array de caracteres para guardar las líneas del
        int ncelda=0;               //Variable tipo entero para guardar el número de celda que queremos
        char cell[SIZE_TEXT];              //Array de caracteres para guardar la ruta relativa de los archivos de texto que tiene la celda deseada

        printf("Posicion: %d\n",*posicion_celda);
        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&ncelda);
        sprintf(cell,"../input_files/info_cell_%d.txt",ncelda);     //Funcion que permite crear una cadena de caracteres que se guardaran en cell con el formato especificado entre parentesis

        /**
         *En este bloque de condicional se maneja las celdas que esten ya repetidas
         */
        if (controlador_celda_repetida(collectors,ncelda,*m_espacio_aux)!=0) {
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
                        strcpy(collectors[*posicion_celda].celda,linea);
                        descripcion++;
                        collectors[*posicion_celda].ncelda=ncelda;
                    }else if (descripcion==1) {
                        strcpy(collectors[*posicion_celda].address,linea);
                        descripcion++;
                    }else if (descripcion==2) {
                        strcpy(collectors[*posicion_celda].essid,linea);
                        descripcion++;
                    }else if (descripcion==3) {
                        strcpy(collectors[*posicion_celda].mode,linea);
                        descripcion++;
                    }else if (descripcion==4) {
                        strcpy(collectors[*posicion_celda].chanel,linea);
                        descripcion++;
                    }else if (descripcion==5) {
                        strcpy(collectors[*posicion_celda].encryption,linea);
                        descripcion++;
                    }else if (descripcion==6) {
                        strcpy(collectors[*posicion_celda].quality,linea);
                        descripcion++;
                    }else if (descripcion==7) {
                        strcpy(collectors[*posicion_celda].frecuency,linea);
                        descripcion++;
                    }else if (descripcion==8) {
                        strcpy(collectors[*posicion_celda].signal_level,linea);
                        descripcion=0;
                        (*posicion_celda)++;
                    }
                    linea[0]='\0';          //Ponemos el array línea como vacio para que guarde las nuevas líneas de texto

                    /**
                     *Este bloque se encarga de aumentar el tamaño del arreglo mediante la funcion realloc, para ello
                     *usamos la variable de la dirreccion m_espacio_aux
                     */
                    if ((*posicion_celda)%5==0 && (*posicion_celda)!=0 && descripcion==0) {
                        printf("Aumentando la memoria\n");
                        *m_espacio_aux+=5;
                        struct wificollector_collect *ptr_collectors_aux=realloc(collectors,sizeof(struct wificollector_collect)*(*m_espacio_aux));
                        if (ptr_collectors_aux==NULL) {
                            printf("Error al aumentar tamaño\n");
                            free(collectors);
                            exit(1);
                        }
                        collectors=ptr_collectors_aux;
                        printf("Memoria aumentada\n");
                    }
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
 *@param ptr_collectors_aux Direccion de memoria de collectors
 *@param ncelda_aux Entero que lleva el número de celda que el usuario desea
 *@param m_espacio_aux Entero que lleva el tamaño del arreglo
 *@details La funcion recibe el struct y revisa si existe dicha celda recorriendo el arreglo de tamaño m_espacio_aux y lo confirma con la variable ncelda_aux
 */
int controlador_celda_repetida(struct wificollector_collect *ptr_collectors_aux,int ncelda_aux,int m_espacio_aux) {
    int controlador=0;
    for (int i=0;i<m_espacio_aux;i++) {
        if (ptr_collectors_aux!=NULL) {
            if (ptr_collectors_aux[i].ncelda==ncelda_aux) {
                controlador++;
            }
        }
    }
    return controlador;
}