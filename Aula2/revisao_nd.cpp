#include <stdio.h>

struct realType {
    int left;   // parte inteira
    int right;  // parte decimal (sempre positivo)
};

// (a) Criar número real a partir de left e right
struct realType criarNumero(int left, int right) {
    struct realType num;
    num.left = left;
    if (right < 0) right *= -1; // garante parte decimal positiva
    num.right = right;
    return num;
}

// (b) Retornar o número real como double
double converterParaDouble(struct realType num) {
    double valor = num.left + num.right / 100.0;
    if (num.left < 0)
        valor = num.left - num.right / 100.0; 
    return valor;
}

// (c) Soma
struct realType add(struct realType a, struct realType b) {
    double resultado = converterParaDouble(a) + converterParaDouble(b);
    int inteiro = (int)resultado;
    int decimal = (resultado - inteiro) * 100;
    if (decimal < 0) decimal *= -1;
    return criarNumero(inteiro, decimal);
}

// Subtração
struct realType subtract(struct realType a, struct realType b) {
    double resultado = converterParaDouble(a) - converterParaDouble(b);
    int inteiro = (int)resultado;
    int decimal = (resultado - inteiro) * 100;
    if (decimal < 0) decimal *= -1;
    return criarNumero(inteiro, decimal);
}

// Multiplicação
struct realType multiply(struct realType a, struct realType b) {
    double resultado = converterParaDouble(a) * converterParaDouble(b);
    int inteiro = (int)resultado;
    int decimal = (resultado - inteiro) * 100;
    if (decimal < 0) decimal *= -1;
    return criarNumero(inteiro, decimal);
}

// Mostrar
void mostrar(struct realType num) {
    printf("%d,%02d", num.left, num.right);
}

int main() {
    struct realType n1, n2;
    int left, right;

    printf("Digite o primeiro numero (parte inteira e decimal separadas): ");
    scanf("%d %d", &left, &right);
    n1 = criarNumero(left, right);

    printf("Digite o segundo numero (parte inteira e decimal separadas): ");
    scanf("%d %d", &left, &right);
    n2 = criarNumero(left, right);

    struct realType soma = add(n1, n2);
    struct realType dif = subtract(n1, n2);
    struct realType mult = multiply(n1, n2);

    printf("\nResultados:\n");
    printf("Soma: "); mostrar(soma); printf("\n");
    printf("Subtracao: "); mostrar(dif); printf("\n");
    printf("Multiplicacao: "); mostrar(mult); printf("\n");

    return 0;
}
