#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

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