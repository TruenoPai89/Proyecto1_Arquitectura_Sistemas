#include <stdio.h>
#include <string.h>
#include "wificollector_collect.h"

struct wificollector_collect collectors[21];

void wificollector_collect() {
    char respuesta='s';
    char linea[1000]="";

    do {
        int poscion_celda=0;
        char cell[100];
        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&poscion_celda);
        sprintf(cell,"../cells/info_cell_%d.txt",poscion_celda);

        FILE *f=fopen(cell,"r");
        if(f==NULL) {
            printf("Error al abrir el archivo\n");
        }
        else {
            collectors[poscion_celda-1].celda=poscion_celda;
            while(fgets(linea,sizeof(linea),f)) {
                strcat(collectors[poscion_celda-1].texto,linea);
            }
            fclose(f);
            printf("Desea añadir otro punto de acceso? [s/N]: \n");
            scanf(" %c",&respuesta);
        }

    } while(respuesta=='S'||respuesta=='s');

}
