#include <stdio.h>
#include <stdlib.h>

int main()
{
    char resp = 's';
    int* puntero;
    int* aux;
    int f = 0; // es la variable de control a partir de la cual se va a incrementar el tamaño del array
    puntero = malloc(sizeof(int)); // se arma un puntero y se le asigna un bloque de memoria dinamico*
    while (resp == 's')
    {
        if (f > 0) //empieza a usar realloc si se quiere ingresar mas de un numero
        {
            aux = realloc(puntero, sizeof(int)); // se genera un nuevo puntero, incrementando en 1 sizeof(int) el tamaño de la memoria
            puntero = aux; // se asigna al viejo puntero la nueva direccion de memoria, con el tamañp incrementado
        }// falta validar que aux no sea NULL
        printf("\nNumero : ");
        scanf("%d", &(*(puntero+f))); //se carga un numero en memoria. F se va incrementando con cada vuelta del while
        for (int i = 0; i <= f; i++)
        {
            printf("\nNumero: %d", *(puntero+i)); // se imprime los numeros guardados en la direccion de memoria
        }
        printf("\nSeguir cargando? ");
        setbuf(stdin, NULL);
        scanf("%c", &resp);
        f++;
    }
    free(puntero); // se libera la memoria del puntero
    return 0;
}
