#include <stdio.h>
#include <stdlib.h>

void fillArray(int *array[], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            array[i][j] = 0;
        }
    }
}

void createArray(int *array[], int x, int y)
{
    int *tmp;
    for(int i = 0; i < x; i++)
    {
        tmp = malloc(sizeof(int) * y);
        array[i] = tmp;
    }
    fillArray(array, x, y);
}

void resizeArray(int *array[], int x, int y)
{
    int *tmp;
    for(int i = 0; i < x; i++)
    {
        tmp = (int *)realloc(array[i], sizeof(int) * y);
        array[i] = tmp;
    }
    fillArray(array, x, y);
}

void printArray(int *array[], int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void freeArray(int *array[], int x)
{
    for(int i = 0; i < x; i++)
    {
        free(array[i]);
    }
    free(array);
}

int main()
{

    /*
        Pini snake

        gcc -Wall snake.c -o snake && ./snake

        Lo más importante para que este coso funciones es la función malloc() y realloc() de la librería estandar de c.
        Es un poco rudimentario pero si quieres perfeccionarlo y hacerlo más legible tendrías que buscar la implementación en C de la librería "vector<>" de C++.
        :)
    */

    const int x = 10;
    const int y = 10;
    int **array;
    // Crear un array de punteros a int. Toda la memoria asignada por la función malloc() y realloc() no se asigna en el "stack", sino en el "heap";
    array = (int**)malloc(sizeof(int*) * x);

    // Esto asigna a cada puntero dentro de array la dirección de un array de y elementos.
    createArray(array, x, y);

    // Print del array
    printArray(array, x, y);
    printf("\n");

    // Esto cambia de lugar el array de puntero a un sitio con más espacio (20 elementos más, antes eran 10) manteniendo la información anterior.
    array = realloc(array, sizeof(int*) * 20);
    // Esto hace lo mismo que la línea anterior pero para cada puntero dentro del array
    resizeArray(array, 20, 20);
    printArray(array, 20, 20);

    // Esta función no es necesaria porque el programa se termina. Pero de no ser así sería importante para liberar el espacio de memoria ocupado por el array en el "heap"
    freeArray(array, 20);

    return 0;
}
