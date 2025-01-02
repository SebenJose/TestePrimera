#include <stdio.h>
#include <math.h>

    int main (){

        int Vetor [2000000];
        int Primo;
        int Num;

        for (int i = 0; i < 2000000; i++) {
            Primo = 0;

            for (int o = 2; o < sqrt (i); o++) {
                if ( i % o == 0){
                    Primo = 1;
                    break;
                }
            }

            if (Primo == 1){
                Vetor[Num] = i;
                Num++;
            }
        }
        printf("%d\n", Vetor[1]);

    return 0;
   }