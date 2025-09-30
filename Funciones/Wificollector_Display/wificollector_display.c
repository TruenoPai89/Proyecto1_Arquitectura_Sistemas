#include <stdio.h>
#include "wificollector_display.h"
#include "../Wificollector_Collect/wificollector_collect.h"

void wificollector_display() {
    char respuesta='s';

    do {
        int ncell=0;
        printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21):  \n");
        scanf("%d",&ncell);
        //if(collectors[ncell-1])
        puts(collectors[ncell-1].texto);
        printf("Desea imprimir la informacion de otra celda? [s/N]: ");
        scanf(" %c",&respuesta);
    } while(respuesta=='S'||respuesta=='s');
}