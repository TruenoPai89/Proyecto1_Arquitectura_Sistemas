#include <stdio.h>
#include "wificollector_display.h"
#include "../Wificollector_Collect/wificollector_collect.h"

void wificollector_display() {
    int ncell;
    char respuesta='s';

    do {
        printf("Indique el número de la celda de la que desea conocer su información (1 - 21):  \n");
        scanf("%d",&ncell);
        puts(collectors[ncell-1].texto);
        printf("Desea imprimir la informacion de otra celda? [s/N]: ");
        scanf(" %c",&respuesta);
    } while(respuesta=='S'||respuesta=='s');
}