#include <stdio.h>
#include <stdlib.h>

#define TAM 3

int validarPositivo(int);

int main()
{

    int vec[TAM];
    int flag = 0;
    int mayor;




  for(int i=0; i< TAM; i++){

        printf("\nIngrese un numero: ");
        fflush(stdin);
        scanf("%d", &vec[i]);

        while( !validarPositivo(vec[i]) ){
            printf("\nError. El numero debe ser positivo. Reingrese: ");
            fflush(stdin);
            scanf("%d", &vec[i]);
        }

  }

  //busco el mayor dentro del vector

   for(int i=0; i< TAM; i++){

        if(vec[i] >= mayor || flag == 0){
            mayor = vec[i];
            flag = 1;
        }
   }

   printf("\nEl mayor numero ingresado es %d y lo hizo en las posiciones ", mayor);

   for(int i=0; i< TAM; i++){
        if(vec[i] == mayor){
            printf("\n%d", i +1);
        }
   }


  printf("\n\n");
   for(int i=0; i< TAM; i++){

        printf(" %d", vec[i]);
   }

    printf("\n\n");

    return 0;
}

int validarPositivo(int num){

   /* if(num >= 0){
        return 1;
    }
    else{
        return 0;
    }
*/
    int esValido = 0;

    if(num >= 0){
        esValido = 1;
    }

    return esValido;

}
