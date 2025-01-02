/*
Faça um programa em C que, usando um vetor de inteiros de tamanho 2.000.000, mostre os 
    números primos compreendidos entre o intervalo de 0 a 2.000.000, bem como a quantidade
    de primos que obteve.

OBS.: complilador dá falha de segmentação com valores um pouco maiores de 2.095.000
*/
#include <stdio.h>
#include <math.h>

int main()
{
    unsigned int primos[2000000] = {0};
    int tam = 2000000, limite = sqrt(tam);
    int nro, pos, qtde;
    
    // eliminando os múltiplos de nro
    for(nro = 3; nro <= limite; nro+=2)
        for(pos = nro * 2; pos < tam; pos+=nro);
            primos[pos] = 1;
    
    // imprimindo a lista de primos
    printf("Lista de primos de 0 até %d: 0, 1, 2", tam);
    for(pos = 3, qtde = 0; pos <= tam; pos+=2)
        if(primos[pos] == 0){
            printf(", %d", pos);
            qtde++;
        }
        
    printf("\n\nQuantidade de primos: %d\n\n", qtde);
    
    return 0;
}