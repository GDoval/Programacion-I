

typedef struct
{
    int idDuenio;
    char nombreApellido[60];
    char direccion[30];
    int tarjetaCredito;
    int estado;
}eDuenio;

typedef struct
{
    char patente[15];
    int marca;
    int idDuenio;
    int horarioEntrada;
    int horarioSalida;
    int estado;
} eAlquiler;


int buscarVacioDuenios(eDuenio[], int); // busca un indice vacio dentro del vector que se pasa como parametro
void sacarEnter(char[]); // saca el enter que queda al usar el fgets
void ingresoDuenio (eDuenio[], int); //entrada de datos en la estructura
int buscarVacioAlquiler(eAlquiler[], int); // busca un indice vacio dentro de la estructura
void ordenarAutosHorario (eAlquiler[], int); //ordena la estructura por dos criterios
