#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef int Item;

typedef struct {
    Item itens[MAX];
    int inicio;
    int fim;
} Fila;

void inicializaFila(Fila *f) {
    f->inicio = 0;
    f->fim = 0;
}

bool estaVazio(Fila *f) {
    return f->inicio == f->fim;
}

bool estaCheio(Fila *f) {
    return (f->fim + 1) % MAX == f->inicio;
}

void enfileira(Fila *f, Item x) {
    if (estaCheio(f)) {
        printf("Erro: fila cheia!\n");
        return;
    }
    f->itens[f->fim] = x;
    f->fim = (f->fim + 1) % MAX;
}

int desenfileira(Fila *f) {
    if (estaVazio(f)) {
        printf("Erro: fila vazia!\n");
        return -1;
    }
    int x = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    return x;
}

void imprimeFila(Fila *f) {
    if (estaVazio(f)) {
        printf("Fila vazia!\n");
        return;
    }
    printf("Fila: ");
    int i = f->inicio;
    while (i != f->fim) {
        printf("%d ", f->itens[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    Fila f;
    inicializaFila(&f);

    int opcao, valor;
    do {
        printf("\n--- MENU FILA ---\n");
        printf("1 - Enfileirar (inserir)\n");
        printf("2 - Desenfileirar (remover)\n");
        printf("3 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) { // se não digitou número
            printf("Entrada invalida. Digite um numero.\n");
            limparBuffer();
            continue;
        }

        switch(opcao) {
            case 1:
                printf("Digite um valor: ");
                if (scanf("%d", &valor) != 1) {
                    printf("Entrada invalida. Digite um numero.\n");
                    limparBuffer();
                } else {
                    enfileira(&f, valor);
                }
                break;
            case 2: {
                int removido = desenfileira(&f);
                if (removido != -1)
                    printf("Removido: %d\n", removido);
                break;
            }
            case 3:
                imprimeFila(&f);
                break;
            case 0:
                printf("Programa encerrado.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
        limparBuffer(); // limpa qualquer enter residual
    } while(opcao != 0);

    return 0;
}
