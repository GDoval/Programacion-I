#include <stdio.h>
#include <stdlib.h>
typedef struct{
    char modelo[20];
    int nucleos;
} eProcesador;

typedef struct {

    char marca [20];
    eProcesador procesador;
    int ram;
    float precio;
} eNotebook;

void mostrarNotebook (eNotebook);
void cargarNotebook (eNotebook*);

int main()
{
    eNotebook n;// = {"Intel",{"I7", 4}, 18, 1000.50};
    cargarNotebook(&n);
    mostrarNotebook(n);
    return 0;
}



void mostrarNotebook (eNotebook note)
{
    printf("\nMarca: %s", note.marca);
    printf("\nModelo: %s", note.procesador.modelo);
    printf("\nNucleos: %d", note.procesador.nucleos);
    printf("\nRAM: %d", note.ram);
    printf("\nPrecio: %.2f\n", note.precio);

}


void cargarNotebook (eNotebook* x)
{
    printf("Ingrese marca: ");
    fflush(stdin);
    fgets(x->marca, 20, stdin);
    printf("\nIngrese modelo de procesador: ");
    fflush(stdin);
    fgets(x->procesador.modelo, 20, stdin);
    printf("\nIngrese cantidad de nucleos: ");
    scanf("%d", &x->procesador.nucleos);
    printf("\nIngrese cantidad de RAM: ");
    scanf("%d", &x->ram);
    printf("\nIngrese precio: ");
    scanf("%f", &x->precio);
}
