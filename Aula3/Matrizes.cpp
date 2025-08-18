#include <stdio.h>

int main() {
    int linhasA, colunasA, linhasB, colunasB;
    int i, j, k;

    printf("Digite o numero de linhas da matriz A: ");
    scanf("%d", &linhasA);
    printf("Digite o numero de colunas da matriz A: ");
    scanf("%d", &colunasA);

    printf("Digite o numero de linhas da matriz B: ");
    scanf("%d", &linhasB);
    printf("Digite o numero de colunas da matriz B: ");
    scanf("%d", &colunasB);

    if(colunasA != linhasB) {
        printf("Erro: para multiplicar, colunas de A devem ser iguais a linhas de B.\n");
        return 1;
    }

    int matrizA[10][10], matrizB[10][10], soma[10][10], mult[10][10];

    // Preenchendo matriz A
    printf("Digite os elementos da matriz A:\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasA; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    // Preenchendo matriz B
    printf("Digite os elementos da matriz B:\n");
    for(i = 0; i < linhasB; i++) {
        for(j = 0; j < colunasB; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    // Soma (só se dimensões iguais)
    if(linhasA == linhasB && colunasA == colunasB) {
        for(i = 0; i < linhasA; i++) {
            for(j = 0; j < colunasA; j++) {
                soma[i][j] = matrizA[i][j] + matrizB[i][j];
            }
        }
        printf("\nSoma das matrizes:\n");
        for(i = 0; i < linhasA; i++) {
            for(j = 0; j < colunasA; j++) {
                printf("%d ", soma[i][j]);
            }
            printf("\n");
        }
    } else {
        printf("\nNao e possivel somar matrizes de tamanhos diferentes.\n");
    }

    // Multiplicação
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            mult[i][j] = 0;
            for(k = 0; k < colunasA; k++) {
                mult[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }

    printf("\nMultiplicacao das matrizes:\n");
    for(i = 0; i < linhasA; i++) {
        for(j = 0; j < colunasB; j++) {
            printf("%d ", mult[i][j]);
        }
        printf("\n");
    }

    return 0;
}
