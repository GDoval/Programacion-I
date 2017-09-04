#include <stdio.h>
#include <stdlib.h>

int main()
{
     int leg[]={128, 356, 198, 215, 320};
     int aux;

     for(int i=0; i< 4; i++){
        for(int j = i+1; j < 5; j++ ){

                if(leg[i]< leg[j])
                {
                    aux = leg[j];
                    leg[j] = leg[i];
                    leg[i] = aux;
                }
        }
     }

      for(int j = 0; j < 5; j++ ){

            printf(" %d ", leg[j]);
      }

      printf("\n\n");



    return 0;
}
