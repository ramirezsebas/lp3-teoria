# Advanced Linux Programming - Lenguaje de Programacion 3

Para Ejecitar arglist.c:
```bash
    make
    ./arglist param1 param2 paramN
```

## Lista de Argumentos
```c
    #include<stdio.h>

    int main(int argc, char* argv){
        return 0;
    }
```
Tambien podemos pasar argumentos a nuestro programa (Ejecutable), asi podemos recibir una entrada del usuario y realizar cierta logica con esos argumentos.

La funcion main vemos que nos provee a nosotros dos parametros:
    1. argc - Numero entero que nos indica la cantidad de parametros que paso el usuario.
    2. argv - Arreglo de Cadenas siendo estas cadenas los argumentos que se ha pasado.

## Convenciones de Banderas (Opciones)
1. Forma Corta: Consiste en un guion junto a un solo carater(Letra mayuscula o minuscula)
2. Forma Larga: Consiste en dos guiones junto a una palabra que representa al argumento

### Ejemplo
-h -> Forma Corta
--help -> Forma Larga

