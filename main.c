#include <stdio.h>
#include "Funciones/Wificollector_Collect/wificollector_collect.h"
#include "Funciones/Wificollector_Quit/wificollector_quit.h"
#include "Funciones/Wificollector_Display/wificollector_display.h"

int main() {
    char respuesta="";

    do {
        int option=0;

        printf("[2024] SUCEM S.L. Recolector de redes inalámbricas\n");
        printf("[ 1] wificollector_quit\n");
        printf("[ 2] wificollector_collect\n");
        printf("[ 3] wificollector_display\n");
        printf("[ 4] wificollector_display_all\n");
        printf("Ingrese un valor: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                wificollector_quit(&respuesta);
                break;
            case 2:
                wificollector_collect();
                break;
            case 3:
                wificollector_display();
            default:
                return 0;
        }
    }while(respuesta !='s' && respuesta!='S');
}
