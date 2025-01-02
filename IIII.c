#include <stdio.h>
#include <string.h>

    int main (){

        char nome1[20], nome2[20];
        int tamS1, tamS2, tamV1 = 20, tamV2 = 20, p;

        scanf(" %[^\n]", nome1);
        scanf(" %[^\n]", nome2);

        tamS1 = strlen (nome1);

        for (tamS2 = 0; nome2[tamS2] != '\0'; tamS2++){
            if (tamS2 < tamV1 - tamS1 ){
                for (p = 0; p < tamS2; p++, tamS1++){
                    nome1[tamS1] = nome2[p];
                }
                    nome1[tamS1] = '5';
                
                printf(" nome1: %s ", nome1);
                printf( "nome2: %s ", nome2);
            
            }else{

                printf("Impossivel concatenar as 2 strings por tamanho \n ");
            }
        }
return 0;
    }