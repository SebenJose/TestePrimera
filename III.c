#include <stdio.h>

#define N 10

void trocaLinhas(int matriz[N][N], int l1, int l2) {
    for (int i = 0; i < N; i++) {
        int temp = matriz[l1][i];
        matriz[l1][i] = matriz[l2][i];
        matriz[l2][i] = temp;
    }
}

void trocaColunas(int matriz[N][N], int c1, int c2) {
    for (int i = 0; i < N; i++) {
        int temp = matriz[i][c1];
        matriz[i][c1] = matriz[i][c2];
        matriz[i][c2] = temp;
    }
}

void trocaDiagonais(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        int temp = matriz[i][i];
        matriz[i][i] = matriz[i][N - 1 - i];
        matriz[i][N - 1 - i] = temp;
    }
}

void somaColunas(int matriz[N][N], int c1, int c2, int destino) {
    for (int i = 0; i < N; i++) {
        matriz[i][destino] = matriz[i][c1] + matriz[i][c2];
    }
}

void multiplicaLinhas(int matriz[N][N], int l1, int l2, int destino) {
    for (int i = 0; i < N; i++) {
        matriz[destino][i] = matriz[l1][i] * matriz[l2][i];
    }
}

void imprimeMatriz(int matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int M[N][N] = {
        {5, 4, 9, 4, 0, 1, 7, 9, 8, 4},
        {2, 2, 7, 5, 2, 2, 1, 4, 5, 9},
        {9, 1, 5, 6, 5, 0, 3, 0, 6, 6},
        {7, 0, 2, 3, 7, 4, 2, 2, 7, 3},
        {5, 3, 3, 1, 9, 8, 4, 2, 4, 4},
        {3, 8, 4, 2, 3, 9, 5, 2, 1, 2},
        {9, 7, 0, 9, 4, 7, 2, 0, 2, 5},
        {1, 9, 0, 8, 0, 6, 3, 5, 9, 9},
        {0, 6, 4, 7, 5, 5, 6, 1, 8, 4},
        {3, 4, 9, 4, 3, 2, 0, 3, 0, 5}
    };

    printf("Matriz\n");
    imprimeMatriz(M);

    trocaLinhas(M, 1, 7);

    trocaColunas(M, 3, 9);

    trocaDiagonais(M);

    somaColunas(M, 4, 5, 0);

    multiplicaLinhas(M, 2, 3, 9);

    printf("\nMatriz saida\n");
    imprimeMatriz(M);

    return 0;
}