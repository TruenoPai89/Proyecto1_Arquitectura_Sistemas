#include "wificollector_display_all.h"
#include <stdio.h>
#include "../Wificollector_Collect/wificollector_collect.h"

void wificollector_display_all() {

    for (int i = 0; i <= 20; i++) {
        if (collectors[i].celda!=0) {
            puts(collectors[i].texto);
        }else {
            printf("No hay informacion de la celda numero: %d\n",i);
        }
    }
}
