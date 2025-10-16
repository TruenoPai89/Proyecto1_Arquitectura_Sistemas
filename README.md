# Proyecto Arquitectura de Sistemas
## Descripcion
El objetivo de este proyecto es el emplear conocimientos basicos de programacion en C para el desarrollo 
de una aplicacion de consola y que la misma pueda ser ejecutada en un entorno linux.
## ¿Qué hace el programa?
Esta es una app de consola con un menú para recolectar (leer de ficheros) y mostrar una celda concreta o volcar todas las celdas Wi-Fi guardadas; además, permite salir con confirmación. 

**1) wificollector_quit:** Pide confirmación y fija la respuesta para terminar el bucle de main.

**2) wificollector_collect:** Solicita un nº de celda (1–21), abre `../input_files/info_cell_<n>.txt` y guarda sus 9 líneas en la estructura global `colectors`. 
Evita duplicados con la funcion `controlador_celda_repetida`.

**3) wificollector_display:** Pide un nº de celda y, recorre el array y si existe, imprime sus 9 campos. 
Esto se repite mientras el usuario responda `s` o `S`.

**4) wificollector_display_all:** Recorre todo el array de la structura `colectors` e imprime las celdas con ncelda != 0.
 


## Estructura del proyecto
```
programa/
├─ exe/
│  └─ Makefile
├─ incl/
│  ├─ wificollector_collect.h
│  ├─ wificollector_display.h
│  ├─ wificollector_display_all.h
│  └─ wificollector_quit.h
├─ input_files/
│  └─ info_cell_1.txt ... info_cell_21.txt
├─ src/
│  ├─ main.c
│  ├─ wificollector_collect.c
│  ├─ wificollector_display.c
│  ├─ wificollector_display_all.c
│  └─ wificollector_quit.c
```

## Qué aporta cada archivo
### 1) main.c: 
* Muestra el menú, lee la opción y llama a la función correspondiente.
* Mantiene un bucle do-while que solo termina cuando `wificollector_quit` establece `respuesta = 's'/'S'`.
 main

### 2) wificollector_collect.c
* Define el array global `collectors[SIZE_ARRAY]` donde `SIZE_ARRAY` es igual a 200 y lo inicializa a cero.

* Construye la ruta `../input_files/info_cell_%d.txt`, abre en modo lectura y reparte cada línea a su campo `(CELDA… SIGNAL LEVEL)`.

* Evita duplicados con `controlador_celda_repetida`.

* La posicion de cada celda es controlado por el puntero de entero `*posicion_celda` que está en `main.c`
y permite colocar cada estructura de un puesto determinado según se van recolectando.

### 3) wificollector_display.c
* Pide un nº de celda (1–21); si existe (según `controlador_celda_repetida`), recorre el array e imprime los 9 campos de la celda elegida.

* Permite repetir mientras el usuario responda s.

### 4) wificollector_display_all.c
* Recorre todo el array y, si ncelda != 0, imprime los 9 campos, caso contrario no imprime nada

### 5) wificollector_quit.c
* Pide confirmación ([s/N]) y, por puntero, copia la respuesta en la variable `respuesta` de `main.c`.

## Flujo de datos y estructura usada
Estructura (declarada en la cabecera `wificollector_collect.h`; visible por sus campos en el código):
* `ncelda`
* `celda` 
* `address` 
* `essid` 
* `mode` 
* `chanel` 
* `encryption` 
* `quality` 
* `frecuency` 
* `signal_level`

El array global `collectors[SIZE_ARRAY]` vive en `wificollector_collect.c` y se comparte vía extern en las cabeceras.

## Compilación y ejecución
Para poder ejecutar el programa deberemos dirigirnos a la carpeta exe y una vez dentro ejecutar el comando `make`
que mediante el archivo Makefile que está en la carpeta creara los ejecutables dentro de la misma.

````
main: main.o wificollector_collect.o wificollector_display.o wificollector_display_all.o wificollector_quit.o
main.o:
	gcc -c ../src/main.c
wificollector_collect.o:
	gcc -c ../src/wificollector_collect.c
wificollector_display.o:
	gcc -c ../src/wificollector_display.c
wificollector_display_all.o:
	gcc -c ../src/wificollector_display_all.c
wificollector_quit.o:
	gcc -c ../src/wificollector_quit.c
clean:
	rm main \
	*.o
````
Una vez hecho esto solo debemos escribir `./main`

## Errores comunes y consejos
* Ruta relativa: si no encuentra el TXT, revisa desde dónde ejecutas el binario (la ruta fija es ../input_files/).
 wificollector_collect

* Índice fuera de rango: introduce valores entre 1 y 21. display ya avisa si no es válido.
 wificollector_display

* Celdas repetidas: no se sobreescriben; elimina/ajusta manualmente si quieres recargar una celda con contenido nuevo. 


