#include <stdio.h>

#include "../incl/wificollector_export.h"

void wificollector_export(struct nodo_collectors *collector) {
    char nombre_archivo[SIZE_TEXT];
    char ruta_completa[SIZE_TEXT];

    printf("Indique el nombre del fichero: ");
    scanf("%s", nombre_archivo); // Leemos el nombre

    sprintf(ruta_completa, "../bin/%s.bin", nombre_archivo);


    FILE *f = fopen(ruta_completa, "wb");

    if (f == NULL) {
        printf("Error: No se pudo crear el archivo en la ruta especificada.\n");
        return;
    }

    for (struct nodo_collectors *nodo_aux=collector;nodo_aux!=NULL;nodo_aux=nodo_aux->siguiente) {
        fwrite(&nodo_aux->inicio,sizeof(nodo_aux->inicio),1,f);
    }

    fclose(f);
    printf("Archivo guardado correctamente en %s\n",ruta_completa);
}