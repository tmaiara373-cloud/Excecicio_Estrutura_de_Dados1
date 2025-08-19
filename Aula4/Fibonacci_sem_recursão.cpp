#include <stdio.h>

int main() {
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int fib_anterior = 0;   // f1
    int fib_atual = 1;      // f2
    int fib_proximo;         // próximo número da sequência

    if (n == 1) {
        fib_proximo = 0;
    } else if (n == 2) {
        fib_proximo = 1;
    } else {
        for (int i = 3; i <= n; i++) {
            fib_proximo = fib_anterior + fib_atual; // soma dos dois últimos
            fib_anterior = fib_atual;               // atualiza o anterior
            fib_atual = fib_proximo;                // atualiza o atual
        }
    }

    printf("f%d = %d\n", n, fib_proximo);

    return 0;
}
