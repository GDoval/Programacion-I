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

int buscarVacio (eProgramador[], int);
void ingresoProgramador (eProgramador[], eProgProy[], int);
void imprimirProgramador (eProgramador[], eCategoria[], eProyecto[], eProgProy[], int);
