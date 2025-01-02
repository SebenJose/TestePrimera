#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int linhas;
    int colunas;
    int **valores;
} Matriz;

Matriz *criarMatriz(int linhas, int colunas);
void liberarMatriz(Matriz *matriz);
void lerMatrizDeArquivo(Matriz *matriz, FILE *arquivo);
void escreverMatrizEmArquivo(Matriz *matriz, FILE *arquivo);
Matriz *somarMatrizes(Matriz *m1, Matriz *m2);
Matriz *subtrairMatrizes(Matriz *m1, Matriz *m2);
Matriz *multiplicarMatrizes(Matriz *m1, Matriz *m2);
void trocarMatrizes(Matriz **m1, Matriz **m2);

int main() {
    Matriz *matriz1 = NULL, *matriz2 = NULL, *resultado = NULL;
    int opcao, trocar;
    char nomeEntrada[50], nomeSaida[50];

    printf("Digite o nome do arquivo de entrada: ");
    scanf("%s", nomeEntrada);

    printf("Digite o nome do arquivo de saida: ");
    scanf("%s", nomeSaida);

    FILE *entrada = fopen(nomeEntrada, "r");
    if (!entrada) {
        printf("Erro ao abrir arquivo de entrada.\n");
        return 1;
    }

    FILE *saida = fopen(nomeSaida, "w");
    if (!saida) {
        printf("Erro ao abrir arquivo de saida.\n");
        fclose(entrada);
        return 1;
    }

    while (1) {
        fscanf(entrada, "%d", &opcao);

        if (opcao == 4) {
            break;
        }

        if (opcao >= 1 && opcao <= 3) {
            if (!matriz1 || !matriz2) {
                int linhas1, colunas1, linhas2, colunas2;

                fscanf(entrada, "%d %d", &linhas1, &colunas1);
                matriz1 = criarMatriz(linhas1, colunas1);
                lerMatrizDeArquivo(matriz1, entrada);

                fscanf(entrada, "%d %d", &linhas2, &colunas2);
                matriz2 = criarMatriz(linhas2, colunas2);
                lerMatrizDeArquivo(matriz2, entrada);
            }

            switch (opcao) {
                case 1:
                    resultado = somarMatrizes(matriz1, matriz2);
                    break;
                case 2:
                    resultado = subtrairMatrizes(matriz1, matriz2);
                    break;
                case 3:
                    resultado = multiplicarMatrizes(matriz1, matriz2);
                    break;
            }

            if (resultado) {
                fprintf(saida, "Resultado da operacao:\n");
                escreverMatrizEmArquivo(resultado, saida);
                liberarMatriz(resultado);
                resultado = NULL;
            } else {
                fprintf(saida, "Operacao nao pode ser realizada devido a incompatibilidade de tamanhos.\n");
            }

            fscanf(entrada, "%d", &trocar);
            if (trocar) {
                trocarMatrizes(&matriz1, &matriz2);
            }
        }
    }

    liberarMatriz(matriz1);
    liberarMatriz(matriz2);
    fclose(entrada);
    fclose(saida);

    return 0;
}

Matriz *criarMatriz(int linhas, int colunas) {
    Matriz *matriz = (Matriz *)malloc(sizeof(Matriz));
    if (!matriz) {
        printf("Erro de alocacao de memoria.\n");
        return NULL;
    }
    matriz->linhas = linhas;
    matriz->colunas = colunas;
    matriz->valores = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz->valores[i] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(Matriz *matriz) {
    if (matriz) {
        for (int i = 0; i < matriz->linhas; i++) {
            free(matriz->valores[i]);
        }
        free(matriz->valores);
        free(matriz);
    }
}

void lerMatrizDeArquivo(Matriz *matriz, FILE *arquivo) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            fscanf(arquivo, "%d", &matriz->valores[i][j]);
        }
    }
}

void escreverMatrizEmArquivo(Matriz *matriz, FILE *arquivo) {
    for (int i = 0; i < matriz->linhas; i++) {
        for (int j = 0; j < matriz->colunas; j++) {
            fprintf(arquivo, "%d ", matriz->valores[i][j]);
        }
        fprintf(arquivo, "\n");
    }
}

Matriz *somarMatrizes(Matriz *m1, Matriz *m2) {
    if (m1->linhas != m2->linhas || m1->colunas != m2->colunas) {
        return NULL;
    }
    Matriz *resultado = criarMatriz(m1->linhas, m1->colunas);
    for (int i = 0; i < m1->linhas; i++) {
        for (int j = 0; j < m1->colunas; j++) {
            resultado->valores[i][j] = m1->valores[i][j] + m2->valores[i][j];
        }
    }
    return resultado;
}

Matriz *subtrairMatrizes(Matriz *m1, Matriz *m2) {
    if (m1->linhas != m2->linhas || m1->colunas != m2->colunas) {
        return NULL;
    }
    Matriz *resultado = criarMatriz(m1->linhas, m1->colunas);
    for (int i = 0; i < m1->linhas; i++) {
        for (int j = 0; j < m1->colunas; j++) {
            resultado->valores[i][j] = m1->valores[i][j] - m2->valores[i][j];
        }
    }
    return resultado;
}

Matriz *multiplicarMatrizes(Matriz *m1, Matriz *m2) {
    if (m1->colunas != m2->linhas) {
        return NULL;
    }
    Matriz *resultado = criarMatriz(m1->linhas, m2->colunas);
    for (int i = 0; i < m1->linhas; i++) {
        for (int j = 0; j < m2->colunas; j++) {
            resultado->valores[i][j] = 0;
            for (int k = 0; k < m1->colunas; k++) {
                resultado->valores[i][j] += m1->valores[i][k] * m2->valores[k][j];
            }
        }
    }
    return resultado;
}

void trocarMatrizes(Matriz **m1, Matriz **m2) {
    Matriz *temp = *m1;
    *m1 = *m2;
    *m2 = temp;
}
