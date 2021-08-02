# Advanced Linux Programming - Lenguaje de Programacion 3
Para ejecutar el programa:
```bash
    cd capitulo1
    make
    ./reciprocal 7
```

## Teoria - Capitulo 1
### Compilacion
Para compiler el programa en C usamos gcc:
```bash
    //Resultaria en la creacion de un archivo objeto main.o
    gcc -c main.c

```


Para compiler el programa en C++ usamos g++:
```bash
    //Resultaria e la creacion de un archivo objeto reciprocal.o
    g++ -c reciprocal.cpp

```



#### Observacion: 
1) El flag -c indica al compilador que solo tiene que crear un archivo de objeto. Si no se coloca el -c entonces va a intentar a enlazar el programa a crear un ejecutable.
2) Muchas veces necesitas otras librerias, encabezados, etc.
Entonces con la bandera -I, indica al compilador donde debe buscar los encabezados.(Aun que por defecto el compilador busca en el mismo directorio)
```bash
//Ejemplo:
    g++ -c -I ../include reciprocal.cpp
```
3) Existe la posibilidad de agregar macros directo en el compilador.
```bash
    g++ -c -D NDEBUG=3 reciprocal.cpp
```
4) Existe la posibilidad de optimizar directo en el compilador.
```bash
    g++ -c -02 reciprocal.cpp
```

### Enlazado de Archivos .o
Ahora que tenemos los .o, debemos enlazarlos.
```bash
    g++ -o reciprocal main.o reciprocal.o 
```

#### Observacion
1) -o Flag indica el nombre del ejecutable.
2) Para ejecuar el programa:
```bash
    ./reciprocal
``` 
3) Se debe utilizar el flag -l para poder enlazar una libreria externa (GUI, etc)
```bash
    g++ -o reciprocal main.o reciprocal.o -lpam
```

O podemos utilizar el -L para especificar un directorio a buscar la libreria. 

### Automatizando con Make
Make nos pemite a nosotros poder ejecuta nuestro programa mediante un conjunto de reglas.

```make
# Podemos ver que para generar los .o necesitamos de main.o y reciprocal.o
#CFLAGS ES UNA VARIABLE DE LAS BANDERAS ASOCIADAS 
reciprocal: main.o reciprocal.o
	g++ $(CFLAGS) -o reciprocal main.o reciprocal.o

# Para generar el main.o necesitamos del main.c y reciprocal.hpp
main.o: main.c reciprocal.hpp
	gcc $(CFLAGS) -c main.c

# Para generar el reciprocal.o necesitamos del reciprocal.c y reciprocal.hpp
reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp

#Finalmente limpiamos todo los .o y ejecutables
clean:
	rm -f *.o reciprocal
```

### DEBUG con GDB
