#include <stdio.h>
#include "wificollector_display.h"
#include "../Wificollector_Collect/wificollector_collect.h"

void wificollector_display() {
    char respuesta='s';

    do {
        int ncell=0;
        printf("Indique el numero de la celda de la que desea conocer su informacion (1 - 21):  \n");
        scanf("%d",&ncell);
        if(ncell>=1 && ncell<=21) {
            if(collectors[ncell-1].celda!=0) {
                printf("Numero de celda: %d\n",collectors[ncell-1].celda);
                puts(collectors[ncell-1].texto);
            }else {
                printf("Numero de celda: %d\n",collectors[ncell-1].celda);
                printf("No existe informacion sobre la celda %d\n",ncell);
            }
            printf("Desea imprimir la informacion de otra celda? [s/N]: ");
            scanf(" %c",&respuesta);
        }else {
            printf("El numero de la celda es invalido\n");
        }
    } while(respuesta=='S'||respuesta=='s');
}