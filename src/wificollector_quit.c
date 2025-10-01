#include "../incl/wificollector_quit.h"
#include <stdio.h>

char wificollector_quit(char *prespuesta) {

    char aux;

    printf("Esta seguro de que desea salir del programa? [s/N]:\n");
    scanf(" %c", &aux);
    *prespuesta = aux;
    return *prespuesta;
}