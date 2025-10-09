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
#define SIZE_MAX 200

struct wificollector_collect collectors[21]={0}; //Definimos que el array de collectors estara vacio inicialemnete y aqui se asigna memoria a este array
/**
 *@brief Implemntacion de la funcion wificollector_collect para la visualizacion de celdas almacenadas por pantalla
 */
void wificollector_collect() {
    char respuesta='s';         //Variable tipo caracter para guardar la respuesta del usuario

    do {
        char linea[1000]="\0";      //Array de caracteres para guardar las lineas del
        int ncelda=0;               //Variable tipo entero para guardar el numero de celda que queremos
        char cell[80];              //Array de caracteres para guardar la ruta relativa de los archivos de texto que tiene la celda deseada
        char texto[1000]="\0";      //Array de caracteres que guarda toda la informacion del archivo de texto


        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&ncelda);
        sprintf(cell,"../input_files/info_cell_%d.txt",ncelda);     //Funcion que me permite crear un cadena de caracteres que se guardaran en cell con el formato especificado entre parentesis

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
             *Luego dentro del bucle while se estara concatenando el array linea en el array texto despues limpiaremos el array linea para que el bucle
             *se vuelva a repetir, el bucle terminara cuando fgets haya llegado al final del archivo.
             */

            while(fgets(linea,sizeof(linea),f)) {
                strcat(texto,linea);        //Parte donde se concatena las lineas de texto en el array texto
                linea[0]='\0';          //Ponemos el array linea como vacio para que guarde las nuevas lineas de texto
            }
            fclose(f);                      //Con fclose cerramos el archivo
            collectors[ncelda-1].celda=ncelda;  //Copiamos el numero de celda que seleccionamos al apartado de celda de la estructura collectors
            strcpy(collectors[ncelda-1].texto,texto);       //Copiamos el texto leido en el apartado de texto de la estructura collectors
        }

        printf("Desea anadir otro punto de acceso? [s/N]: \n");     //Preguntamos si se desea añadir otra celda y leemos su respuesta
        scanf(" %c",&respuesta);

    } while(respuesta=='S'||respuesta=='s');
}
/**
*@details Con la ayuda del bucle do-while nos permitira recolectar las celdas que queramos hasta que el usuario indique lo contrario
*/
