#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

#define true 1
#define false 0
typedef short int bool; 


bool primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

//Crie uma função em C que, dado um número inteiro n > 0 permita realizar a soma utilizando a seguinte regra: 1 + 2 + 3 .. + n
int exec2 (int n ){

    if (n > 0){
        int i; 
        int soma = 0; 
        for(i =1; i <= n; i++ ){
            soma += pow(i,2);
        }
        return soma;
    }
     return -1; 
}

/*Escreva uma função em C que, receba como parâmetro um número inteiro não-negativo n, e
retorne a soma dos n primeiros números primos.
*/
int exec3 (int n){
    int i = 1; 
    int count = 0;
    int soma = 0;
    if (n > 0){
       while (count <= n ){
            if(primo(i)){
                soma += i; 
                count++;
            }
        i++;
       }return soma;
    } return -1;
}

int main(int argc, char *argv[]) {
    int i; 
    char arg[10]; 
    for (i= 0; i < argc; i++){
        char argFor[10];
        printf("%c |\t", *(argv[i]));
    }
    char argChar = (*(argv[2]));  
    int argInt = atoi((*(argv+1)));
   
    switch (argChar)
    {
    case '2':
        printf("%d", exec2(argInt));     
        break;
    case '3':
        printf("%d", exec3(argInt));
        break;
    default:
        printf("%c |\t", *(argv[i]));
        break;
    }
    
    return 0; 

}
