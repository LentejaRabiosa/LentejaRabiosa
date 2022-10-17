#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int **data;
    int x, y;
} Array;

void fillArray(Array *array, int x, int y)
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            array->data[i][j] = 0;
        }
    }
}

void createArray(Array *array, int x, int y)
{
    array->data = (int **)malloc(sizeof(int *) * x);
    array->x = x;
    array->y = y;
    for(int i = 0; i < x; i++)
    {
        array->data[i] = (int *)malloc(sizeof(int) * y);
    }
    fillArray(array, x, y);
}

void resizeArray(Array *array, int x, int y)
{
    array->data = (int **)realloc(array->data, sizeof(int *) * x);
    array->x = x;
    array->y = y;
    for(int i = 0; i < x; i++)
    {
        array->data[i] = (int *)realloc(array->data[i], sizeof(int) * y);
    }
    fillArray(array, x, y);
}

void printArray(Array *array)
{
    for(int i = 0; i < array->x; i++)
    {
        for(int j = 0; j < array->y; j++)
        {
            printf("%d ", array->data[i][j]);
        }
        printf("\n");
    }
}

void freeArray(Array *array)
{
    for(int i = 0; i < array->x; i++)
    {
        free(array->data[i]);
    }
    free(array->data);
    array->data = NULL;
}

int main()
{

    /*
        Pini snake v2

        gcc -Wall snake.c -o snake && ./snake

        Lo más importante para que este coso funciones es la función malloc() y realloc() de la librería estandar de c.
        Es un poco rudimentario pero si quieres perfeccionarlo y hacerlo más legible tendrías que buscar la implementación en C de la librería "vector<>" de C++.
        :)
    */

    const int x = 10;
    const int y = 10;
    Array array;

    createArray(&array, x, y);
    printArray(&array);
    printf("\n");

    resizeArray(&array, 20, 30);
    printArray(&array);

    freeArray(&array);

    return 0;
}
