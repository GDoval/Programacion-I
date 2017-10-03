typedef struct{
    int id;
    char nombre[50];
    int idCate;
    int idProye;
    int estado;
    int sueldo;
}eProgramador;

typedef struct
{
    int idProyec;
    char desc[50];
} eProyecto;

typedef struct
{
    int idProg;
    int idProyec;
    int idCate;
    int horasTrabajadas;
    int estado;
} eProgProy;

typedef struct
{
    char desc[50];
    int idCat;
    int valorHora;
} eCategoria;


/*------------------------------------------------------------*/


/**brief Busca un indice vacio dentro del array pasado como argumento
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/

int buscarVacio (eProgramador[], int);

/*------------------------------------------------------------*/

/**brief Inserta registros dentro de una estructura
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/

void ingresoProgramador (eProgramador[], eProgProy[], int);

/*------------------------------------------------------------*/

/**brief Imprime por pantalla un listado de los elementos de los arrays que se le pasan como argumento
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
**/

void imprimirProgramador (eProgramador[], eCategoria[], eProyecto[], eProgProy[], int);
/*------------------------------------------------------------*/

/**brief Busca el campo comun entre dos estructuras relacionadas
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return Retorna un entero
**/

int buscarProyecto (eProgramador[], int, eProgProy[], int);

/*------------------------------------------------------------*/

/**brief Busca el campo comun entre dos estructuras relacionadas
/*param recibe un array del tipo estructura
/*param recibe un array del tipo estructura
/*param recibe un entero con la cantidad de elementos del array
/*return Retorna un entero
**/

int buscarHorasTrabajo (eProgramador[], int, eProgProy[], int);

/*------------------------------------------------------------*/
/**brief Reemplaza el enter que queda al final del string al leerlo con la funcion fgets() por un '\0'
/*param recibe un array de caracteres
**/

void sacarEnter(char[]);
/*------------------------------------------------------------*/

/**brief Realiza una baja logica dentro del array que se le pasa como argumento
/*param recibe un array del tipo estructura
/*param recibe el entero que se usa como criterio para realizar la baja
/*param recibe un entero con la cantidad de elementos del array
**/

void borrarProgramador (eProgramador[], eCategoria[], eProyecto[], eProgProy[], int, int);
/*------------------------------------------------------------*/
/**brief Valida que el entero pasado como argumento sea 1, 2 ó 3
/*param recibe un entero
/* Devuelve 0 si la cadena no es valida, -1 si lo e
**/

int validarCate (int);

/*------------------------------------------------------------*/

/**brief Valida que la cadena pasada como argumento contenga solo letras
/*param recibe un array de caracteres
/* Devuelve 0 si la cadena no es valida, -1 si lo es
**/

int validaString (char[]);


/*------------------------------------------------------------*/
void modificarProgramador (eProgramador[], eProgProy[], int, int);
