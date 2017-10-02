#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[20];
}eAlumno;

typedef struct{
    int id;
    char descripcion[20];
}eMateria;

typedef struct{
    int legajo;
    int idMateria;
}eInscripcion;




int main()
{
    eAlumno Alumnos[]={{1, "Jose"}, {3, "Alberto"}, {4, "Juan"}, {7, "Luis"}, {10, "Ana"}, {9, "Silvia"}, {8, "Maria"}, {15, "Sofia"}, {18, "Martin"}, {11, "Dalia"}};
    eMateria Materias[]={{1, "Progamacion"}, {2, "Matematicas"},{3, "Quimica"}, {4, "Fisica"}, {5, "Electronica"}};
    eInscripcion Inscripciones[]={{1,2}, {1,3}, {3,2}, {4,4}, {3,5}, {3,1}, {4,1}, {1,1}, {8,1}, {9,3}, {10,2}, {10,5}, {10, 3}, {8, 1}};


    mostrarAlumnoConMaterias(Alumnos, Materias, Inscripciones,10, 5,15);
    printf("\n---------------------------\n");
    mostrarMateriasConCantidadInscriptos(Materias,Inscripciones, 5, 15);

    return 0;
}

void mostrarMateriasConCantidadInscriptos(eMateria materias[], eInscripcion inscriptos[], int tamMat, int tamIns)
{
    int cont;
    printf("\n----Cantidad de inscriptos por materia----\n");
    for (int i = 0; i < tamMat; i++)
    {
        cont = 0;
        printf("%s:", materias[i].descripcion);
        for (int j = 0; j < tamIns; j++)
        {
            if (materias[i].id == inscriptos[j].idMateria)
                cont++;
        }
        printf("%d\n", cont);
    }
}

void mostrarAlumnoConMaterias(eAlumno lista[], eMateria materias[], eInscripcion inscritos[], int tamAlum, int tamMate, int tamIns)
{
    int flag;
    for (int i = 0; i < tamAlum; i++)
    {
        flag = 0;
        printf("\nAlumno %s, legajo %d, inscripto en: \n", lista[i].nombre, lista[i].legajo);
        for (int j = 0; j < tamIns; j++)
        {
            if (lista[i].legajo == inscritos[j].legajo)
            {
                flag = 1;
                for (int k = 0; k < tamMate; k++)
                {
                    if (inscritos[j].idMateria == materias[k].id)
                    {
                        printf("%s\n",materias[k].descripcion);
                    }

                }
            }
        }
        if (flag == 0)
        {
            printf("en ninguna materia.\n");
        }
    }
}
