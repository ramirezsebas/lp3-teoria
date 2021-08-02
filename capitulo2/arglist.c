#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("El nombre del programa es : %s\n", argv[0]);

    if (argc > 1){
        printf("La Cantidad de Argumentos pasados: %d\n", argc);
        printf("Los argumentos son: \n");

        int i;
        for (i = 1; i < argc; i++)
        {
            printf("El argumento %d es %s\n", i, argv[i]);
        }
    }
    else{
        printf("No se ha pasado ningun argumento");
    }

    return 0;
}