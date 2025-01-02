#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_COLUNAS 1024
#define MAX_CHARS 256

void caractereMaisFrequente(char *linha) {
    int freq[MAX_CHARS] = {0};
    int maxFreq = 0;


    for (int i = 0; linha[i] != '\0'; i++) {
        if (isalpha(linha[i]) && linha[i] != ' ') {
            char ch = tolower(linha[i]);
            freq[(int)ch]++;
            if (freq[(int)ch] > maxFreq) {
                maxFreq = freq[(int)ch];
            }
        }
    }

    printf("Mais frequentes: ");
    for (int i = 0; i < MAX_CHARS; i++) {
        if (freq[i] == maxFreq && maxFreq > 0) {
            printf("%c ", i);
        }
    }
    printf("\n");
}

int main() {
    int linhas;
    char **matriz;


    printf("Informe o numero de linhas: ");
    scanf("%d", &linhas);
    getchar();

    if (linhas <= 0) {
        printf("Numero invalido!\n");
        return 1;
    }


    matriz = (char **)malloc(linhas * sizeof(char *));
    if (matriz == NULL) {
        printf("Erro na alocacao!\n");
        return 1;
    }

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (char *)malloc(MAX_COLUNAS * sizeof(char));
        if (matriz[i] == NULL) {
            printf("Erro na alocacao!\n");

            for (int j = 0; j < i; j++) {
                free(matriz[j]);
            }
            free(matriz);
            return 1;
        }

        printf("Linha %d: ", i + 1);
        fgets(matriz[i], MAX_COLUNAS, stdin);
        matriz[i][strcspn(matriz[i], "\n")] = '\0';
    }

    for (int i = 0; i < linhas; i++) {
        printf("\nLinha %d:\n", i + 1);
        caractereMaisFrequente(matriz[i]);
    }

    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
