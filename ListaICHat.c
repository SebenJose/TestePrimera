#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

        /*preciso estudar isso aqui e intender ou entender sla*/

// Função para contar a ocorrência dos caracteres em uma string
void contarCaracteres(char *linha, int *contador) {
    for (int i = 0; linha[i] != '\0'; i++) {
        if (isalpha(linha[i])) { // Considere apenas caracteres alfabéticos
            char c = tolower(linha[i]); // Converte para caixa baixa
            contador[c - 'a']++;
        }
    }
}

// Função para encontrar o(s) caractere(s) mais repetido(s) em uma linha
void encontrarMaisRepetidos(int *contador) {
    int max = 0;
    // Encontrar o valor máximo
    for (int i = 0; i < 26; i++) {
        if (contador[i] > max) {
            max = contador[i];
        }
    }

    // Mostrar os caracteres mais repetidos
    for (int i = 0; i < 26; i++) {
        if (contador[i] == max && max > 0) {
            printf("%c ", i + 'a');
        }
    }
}

int main() {
    int linhas, colunas;

    // Entrada: tamanho da matriz
    printf("Informe o número de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    // Alocação dinâmica da matriz de strings
    char **matriz = (char **)malloc(linhas * sizeof(char *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (char *)malloc((colunas + 1) * sizeof(char)); // +1 para o '\0'
    }

    // Limpar buffer do teclado
    getchar();

    // Leitura das strings
    printf("Digite as strings:\n");
    for (int i = 0; i < linhas; i++) {
        fgets(matriz[i], colunas + 1, stdin);
        matriz[i][strcspn(matriz[i], "\n")] = '\0'; // Remover o '\n'
    }

    // Processamento de cada linha
    printf("\nCaractere(s) mais repetido(s) em cada linha:\n");
    for (int i = 0; i < linhas; i++) {
        int contador[26] = {0}; // Array para contar ocorrências dos caracteres
        contarCaracteres(matriz[i], contador);

        printf("Linha %d: ", i + 1);
        encontrarMaisRepetidos(contador);
        printf("\n");
    }

    // Liberação da memória
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}
