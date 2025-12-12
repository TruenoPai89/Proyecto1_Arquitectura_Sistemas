# Proyecto Arquitectura de Sistemas
https://github.com/TruenoPai89/Proyecto1_Arquitectura_Sistemas.git
## Descripcion
El objetivo de este proyecto es el emplear conocimientos basicos de programacion en C para el desarrollo 
de una aplicacion de consola y que la misma pueda ser ejecutada en un entorno linux.
## ¿Qué hace el programa?
Esta es una app de consola con un menú para recolectar (leer de ficheros) y mostrar una celda concreta o volcar todas las celdas Wi-Fi guardadas; además, permite salir con confirmación. 

**1) wificollector_quit:** Pide confirmación y fija la respuesta para terminar el bucle de main.

**2) wificollector_delete_net:** Solicita la ESSID de la red a la que se desea eliminar y recorre el arreglo buscando alguna red que tengga ese nombre.

**3) wificollector_collect:** Solicita un nº de celda (1–21), abre `../input_files/info_cell_<n>.txt` y guarda sus 9 líneas en la estructura global `colectors`. 
Evita duplicados con la funcion `controlador_celda_repetida`.

**4) wificollector_display:** Pide un nº de celda y, recorre el array y si existe, imprime sus 9 campos. 
Esto se repite mientras el usuario responda `s` o `S`.

**5) wificollector_display_all:** Recorre todo el array de la structura `colectors` e imprime las celdas con ncelda != 0.
 


## Estructura del proyecto
```
programa/
├─ exe/
│  └─ Makefile
├─ incl/
│  ├─ wificollector_collect.h
│  ├─ wificollector_delete_net.h
│  ├─ wificollector_display.h
│  ├─ wificollector_display_all.h
│  └─ wificollector_quit.h
├─ input_files/
│  └─ info_cell_1.txt ... info_cell_21.txt
├─ src/
│  ├─ main.c
│  ├─ wificollector_collect.c
│  ├─ wificollector_delete_net.c
│  ├─ wificollector_display.c
│  ├─ wificollector_display_all.c
│  └─ wificollector_quit.c    
```

## Qué aporta cada archivo
### 1) main.c
* Muestra el menú, lee la opción y llama a la función correspondiente.
* Mantiene un bucle do-while que solo termina cuando `wificollector_quit` establece `respuesta = 's'/'S'`.
 main

### 2) wificollector_collect.c
* Se asigna memoria mediante `calloc` con un tamaño inicial de 5, dependiendo de si el usuario desea ingresar más celdas el
tamaño se ampliará 5 veces más con la funcion `realloc`, para ello se ocupara la variable `m_espacio` que esta definida en `main.c`
, la misma se irá ampliando en el mismo archivo `wificollector_collect`.

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

### 2) wificolector_delete_net.c
* Solicita ESSID de la red que deseamos eliminar y mediante el uso de un bucle que se repetira `m_espacio` busca alguna 
red que tenga dicha ESSID
* Sí encuentra alguna red con esta coincidencia empieza a desplazar las redes que existan después de la red a eliminar


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

Se asigna memoria mediante el uso de la funcion `malloc` con un tamaño inicial de 5 y sé irá ampliando dependiendo de si 
se requiere espacio.
## Compilación y ejecución
Para poder ejecutar el programa deberemos dirigirnos a la carpeta exe y una vez dentro ejecutar el comando `make`
que mediante el archivo Makefile que está en la carpeta creara los ejecutables dentro de la misma.

````
main: main.o wificollector_collect.o wificollector_display.o wificollector_display_all.o wificollector_quit.o wificollector_delete_net.o
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
wificollector_delete_net.o:
	gcc -c ../src/wificollector_quit.c
clean:
	rm main \
	*.o
````
Una vez hecho esto solo debemos escribir `./main`

## Errores comunes y consejos
* **Ruta relativa:** Si no encuentra el TXT, revisa desde dónde ejecutas el binario (la ruta fija es `../input_files/info_cell_%d.txt`).

* **Índice fuera de rango:** Introduce valores entre 1 y 21. display ya avisa si no es válido.

* **Celdas repetidas:** No se sobreescriben, informa que ya existe dicha celda y vuelve a preguntar si desea añadir otra. 


