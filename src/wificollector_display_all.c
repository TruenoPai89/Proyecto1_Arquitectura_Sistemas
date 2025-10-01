#include "../incl/wificollector_display_all.h"
#include <stdio.h>
#include "../incl/wificollector_collect.h"

void wificollector_display_all() {

    int ncell=0;

    for (int i = 0; i <= 20; i++) {
        if (collectors[i].celda!=0) {
            puts(collectors[i].texto);
        }else {
            ncell=i;
            printf("No hay informacion de la celda numero: %d\n",ncell+1);
        }
    }
}