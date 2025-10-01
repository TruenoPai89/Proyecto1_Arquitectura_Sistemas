#include <stdio.h>
#include <string.h>
#include "../incl/wificollector_collect.h"

struct wificollector_collect collectors[21]={0};

void wificollector_collect() {
    char respuesta='s';

    do {
        char linea[1000]="\0";
        int ncelda=0;
        int poscion_celda=0;
        char cell[100];
        char texto[1000]="\0";
        printf("Que celda quiere recolectar? (1 - 21): \n");
        scanf("%d",&ncelda);
        sprintf(cell,"../input_files/info_cell_%d.txt",ncelda);

        FILE *f=fopen(cell,"r");
        if(f==NULL) {
            printf("Error al abrir el archivo\n");
        }
        else {
            poscion_celda=ncelda-1;

            while(fgets(linea,sizeof(linea),f)) {
                strcat(texto,linea);
                linea[1000]="\0";
            }
            fclose(f);
            collectors[poscion_celda].celda=ncelda;
            strcpy(collectors[poscion_celda].texto,texto);
        }

        printf("Desea anadir otro punto de acceso? [s/N]: \n");
        scanf(" %c",&respuesta);

    } while(respuesta=='S'||respuesta=='s');

}
