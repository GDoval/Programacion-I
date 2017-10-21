

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


/*------------------------------------------------------------------*/

/**brief Busca un índice vacio dentro de una variable de tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return devuelve un entero con el indice vacío, o un -1 si el array se encuentra lleno
**/

int buscarVacioDuenios(eDuenio[], int);


/*------------------------------------------------------------------*/

/**brief Reemplaza el enter que queda al final del string al leerlo con la funcion fgets() por un '\0'
/*param recibe un array de caracteres
**/

void sacarEnter(char[]);


/*------------------------------------------------------------------*/
/**brief Ingresa datos dentro de un array de tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void ingresoDuenio (eDuenio[], int);

/*------------------------------------------------------------------*/

/**brief Busca un índice vacio dentro de una variable de tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return devuelve un entero con el indice vacío, o un -1 si el array se encuentra lleno
**/
int buscarVacioAlquiler(eAlquiler[], int);



/*------------------------------------------------------------------*/
/**brief Ordena un array de tipo estructura a partir de dos criterios
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void ordenarAutosHorario (eAlquiler[], int);


/*------------------------------------------------------------------*/
/**brief Ingresa datos dentro de un array de tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void ingresoAuto (eAlquiler[], eDuenio[], int , int);


/*------------------------------------------------------------------*/
/**brief Imprime por pantalla un listado de los elementos de los array que recibe como parametro
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void imprimirListado (eDuenio[], eAlquiler[], int, int);


/*------------------------------------------------------------------*/
/**brief Busca un entero dentro del array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe el entero a buscar
/*return devuelve un 1 si se encontro el entero dentro de la estructura, o un -1 en caso contrario
**/
int idDuenio(eDuenio[], int, int);


/*------------------------------------------------------------------*/
/**brief Modifica un campo de un array de estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe un entero que indica el criterio de busqueda para la modificacion
**/
void modificarTarjeta (eDuenio[], int, int);


/*------------------------------------------------------------------*/
/**brief Imprime un listado de todos los elementos del array que coinciden con el criterio de busqueda
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void imprimirAudi (eAlquiler[], eDuenio[], int, int);


/*------------------------------------------------------------------*/
/**brief Imprime un listado con los montos a abonar por cada cliente
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*param recibe un array de caracteres que es el criterio a partir del cual se realiza la busqueda
/*param recibe un entero que indica el horario de salida
**/
void calcularEstadia (eDuenio[], eAlquiler[], int, int, char[], int);


/*------------------------------------------------------------------*/
/**brief Valida si el entero pasado como paramentro se encuentra en el rango deseado
/*param recibe un entero a validar
/*param recibe un entero como rango minimo
/*param recibe un entero como rango maximo
/*return retorna un -1 si el entero a validar está dentro del rango, o un 0 en caso contrario.
**/
int validaInt (int, int, int );


/*------------------------------------------------------------------*/
/**brief Imprime por pantalla el total de la recaudacion por tipo de coche
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void totalPorMarca ( eAlquiler[], int);


/*------------------------------------------------------------------*/
/**brief Imprime por pantalla el total de la recaudacion del estacionamiento
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/
void totalEstacionamiento (eAlquiler[], int);

/*------------------------------------------------------------------*/
/**brief Valida que la cadena que se pasa como parametro contenga solo letras
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return retorna -1 si la cadena es valida, 0 en caso contrario.
**/
int validaString (char[]);








