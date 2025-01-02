#include <stdio.h>
#include <math.h>

char primo(int n) {
    if (n <= 1) return 'N';
    if (n == 2) return 'S';
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 'N';
    }
    return 'S';
}

char par(int n) {
    if (n % 2 == 0) return 'S';
    return 'N';
}

char quadrado(int n) {
    int raiz = sqrt(n);
    if (raiz * raiz == n) return 'S';
    return 'N';
}

char multiplo6(int n) {
    if ((n % 2 == 0) && (n % 3 == 0)) return 'S';
    return 'N';
}

int main() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    printf("PRIMO: %c\n", primo(n));
    printf("PAR: %c\n", par(n));
    printf("QUADRADO PERFEITO: %c\n", quadrado(n));
    printf("MULTIPLO DE 6: %c\n", multiplo6(n));
    return 0;
}
