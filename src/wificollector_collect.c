/**
 *@author Carlos Condor
 *@date 2025-10-03
 *@file wificollector_collect.c
 *@brief Implementacion de funciones y de la estructura collectors
 *@brief Definicion de las cabeceras
 */
#include <stdio.h>
#include <string.h>
#include "../incl/wificollector_collect.h"

/**
 * @brief Definimos el array de collectors para que se le asigne memoria y lo inicializamos como vacio.
 */
struct wificollector_collect collectors[SIZE_ARRAY]={0};

/**
 *@brief Definicion de la funcion wificollector_collect
 * @param posicion_celda Dirreccion de memoria de la variable posicion_celda en main.c
 */
void wificollector_collect(int *posicion_celda) {
    char respuesta='s';         //Variable tipo caracter para guardar la respuesta del usuario

    do {
        int aux=*posicion_celda;        //Variable de control para guardar las celdas en las posiciones según vayan entrando
        int descripcion=0;              //Entero para guardar parte por parte el texto
        char linea[SIZE_TEXT]="\0";      //Array de caracteres para guardar las líneas del
        int ncelda=0;               //Variable tipo entero para guardar el número de celda que queremos
        char cell[SIZE_TEXT];              //Array de caracteres para guardar la ruta relativa de los archivos de texto que tiene la celda deseada


        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&ncelda);
        sprintf(cell,"../input_files/info_cell_%d.txt",ncelda);     //Funcion que permite crear una cadena de caracteres que se guardaran en cell con el formato especificado entre parentesis

        /**
         *FILE *f permite manejar archivos creando un puntero en este caso *f que apuntara a un archivo
         *fopen permite abrir un archivo pasando como primer argumento su ruta ya sea absoluta o relativa
         *despues como segundo argumento le indicamos el modo en el que deseamos abrir el archivo en este caso de lectura
         */
        if (controlador_celda_repetida(collectors,ncelda)!=0) {
            printf("Ya existe informacion de %d\n",ncelda);
        }else{
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
                 *A medida que se lee cada linea se ira guardando en cada parametro de collectors que sera controlado por un if.
                 */

                while(fgets(linea,sizeof(linea),f)) {
                    if (descripcion==0) {
                        strcpy(collectors[aux].celda,linea);
                        descripcion++;
                        collectors[aux].ncelda=ncelda;
                    }else if (descripcion==1) {
                        strcpy(collectors[aux].address,linea);
                        descripcion++;
                    }else if (descripcion==2) {
                        strcpy(collectors[aux].essid,linea);
                        descripcion++;
                    }else if (descripcion==3) {
                        strcpy(collectors[aux].mode,linea);
                        descripcion++;
                    }else if (descripcion==4) {
                        strcpy(collectors[aux].chanel,linea);
                        descripcion++;
                    }else if (descripcion==5) {
                        strcpy(collectors[aux].encryption,linea);
                        descripcion++;
                    }else if (descripcion==6) {
                        strcpy(collectors[aux].quality,linea);
                        descripcion++;
                    }else if (descripcion==7) {
                        strcpy(collectors[aux].frecuency,linea);
                        descripcion++;
                    }else if (descripcion==8) {
                        strcpy(collectors[aux].signal_level,linea);
                        descripcion=0;
                        aux++;
                    }
                    linea[0]='\0';          //Ponemos el array línea como vacio para que guarde las nuevas líneas de texto
                }
                fclose(f);                      //Con fclose cerramos el archivo
                *posicion_celda=aux;            //Con el puntero posicion_celda modificamos directamente a la variable posicion_celda en main.c
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
 *@details La funcion recibe el struct y revisa si existe dicha celda con la variable ncelda_aux
 */
int controlador_celda_repetida(struct wificollector_collect collectors_aux[SIZE_ARRAY],int ncelda_aux) {
    int controlador=0;
    for (int i=0;i<SIZE_ARRAY;i++) {
        if (collectors_aux[i].ncelda==ncelda_aux) {
            controlador++;
        }
    }
    return controlador;
}
