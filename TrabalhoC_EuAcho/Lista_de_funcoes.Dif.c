#include "ChecarNumeros.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define true 1
#define false 0
    
bool is_primo(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}


int exec2(int n) {
    if (n > 0) {
        int soma = 0;
        for (int i = 1; i <= n; i++) {
            soma += i * i;
        }
        return soma;
    }
    return -1;
}

int exec3(int n) {
    int i = 2;
    int count = 0;
    int soma = 0;
    if (n > 0) {
        while (count < n) {
            if (primo(i)) {
                soma += i;
                count++;
            }
            i++;
        }
        return soma;
    }
    return -1;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <numero> <opcao>\n", argv[0]);
        printf("Opcao 2: Soma dos quadrados de 1 ate N\n");
        printf("Opcao 3: Soma dos N primeiros numeros primos\n");
        return 1;
    }

    int argInt = atoi(argv[1]);
    char argChar = argv[2][0];

    switch (argChar) {
    case '2':
        printf("Soma dos quadrados de 1 ate %d: %d\n", argInt, exec2(argInt));
        break;
    case '3':
        printf("Soma dos %d primeiros numeros primos: %d\n", argInt, exec3(argInt));
        break;
    default:
        printf("Opcao invalida: %c\n", argChar);
        break;
    }

   return 0;
}