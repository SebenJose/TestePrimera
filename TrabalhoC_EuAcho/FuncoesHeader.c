#include "NumberChecks.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

char primo(int n) {
    if (n <= 1) return 'N';
    if (n == 2) return 'S';
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 'N';
    }
    return 'S';
}

char par(int n) {
    return (n % 2 == 0) ? 'S' : 'N';
}

char quadrado(int n) {
    int raiz = sqrt(n);
    return (raiz * raiz == n) ? 'S' : 'N';
}

char multiplo6(int n) {
    return ((n % 2 == 0) && (n % 3 == 0)) ? 'S' : 'N';
}

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
            if (is_primo(i)) {
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
        printf("Opção 2: Soma dos quadrados de 1 até N\n");
        printf("Opção 3: Soma dos N primeiros números primos\n");
        return 1;
    }

    int argInt = atoi(argv[1]);
    char argChar = argv[2][0];

    switch (argChar) {
    case '1':
        printf("PRIMO: %c\n", primo(argInt));
        break;
    case '2':
        printf("Soma dos quadrados de 1 até %d: %d\n", argInt, exec2(argInt));
        break;
    case '3':
        printf("Soma dos %d primeiros números primos: %d\n", argInt, exec3(argInt));
        break;
    default:
        printf("Opção inválida: %c\n", argChar);
        break;
    }

    return 0;
}