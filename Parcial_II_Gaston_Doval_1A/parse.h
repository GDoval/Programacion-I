#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nombre[100];
    char mail[150];
}ePersona;


/** \brief Parsea un archivo .csv
 *
 * \param recibe un puntero a FILE
 * \param recibe un puntero a ArrayList
 * \return devuelve 0 si todo OK, -1 en caso contrario.
 *
 */

int parseLista (FILE*, ArrayList* );



/** \brief Genera una nueva lista depurando una lista ya cargada
 *
 * \param recibe un puntero a ArrayList
 * \param recibe un puntero a ArrayList
 * \param recibe un puntero a ArrayList
 * \return
 *
 */

int nuevaLista (ArrayList*, ArrayList*, ArrayList*);

void imprimir(ArrayList*);

void sacarEnter(char[]);

