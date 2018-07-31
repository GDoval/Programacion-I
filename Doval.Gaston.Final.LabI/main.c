#include <stdio.h>
#include <stdlib.h>
#include "Arraylist.h"
#include "funciones.h"

int main()
{
    ArrayList* lista_letras = al_newArrayList();
    parsear_datos(lista_letras);
    set_Vocal(lista_letras, 0, 'a');
    set_Consonante(lista_letras, 0, 'j');
    //imprimir(lista_letras);
    char palabra[100];
    printf("Ingrese palabra: ");
    setbuf(stdin, NULL);
    fgets(palabra, 101, stdin);
    sacarEnter(palabra);
    //ordenar_Descendente(lista_letras, palabra);
    ordenar_Ascendente(lista_letras, palabra);
    return 0;
}
