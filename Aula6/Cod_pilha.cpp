#include <stdio.h>
#include <stdbool.h>

#define MAX 5   // tamanho máximo da pilha
typedef int Item;


typedef struct {
    Item itens[MAX];
    int topo;
} Pilha;

// Inicializa a pilha
void criaPilha(Pilha *p) {
    p->topo = 0;
}

// Verifica se a pilha está cheia
bool estaCheio(Pilha *p) {
    return (p->topo == MAX);
}

// Verifica se a pilha está vazia
bool estaVazio(Pilha *p) {
    return (p->topo == 0);
}

// Insere um elemento na pilha (push)
bool empilhar(Item x, Pilha *p) {
    if (estaCheio(p)) {
        printf("Erro: pilha cheia!\n");
        return false;
    }
    p->itens[p->topo] = x;
    p->topo++;
    return true;
}

// Remove um elemento da pilha (pop)
Item desempilhar(Pilha *p) {
    if (estaVazio(p)) {
        printf("Erro: pilha vazia!\n");
        return -1; // valor de erro
    }
    p->topo--;
    return p->itens[p->topo];
}

// Imprime todos os elementos da pilha
void imprimir(Pilha *p) {
    if (estaVazio(p)) {
        printf("Pilha vazia!\n");
        return;
    }
    printf("Elementos da pilha:\n");
    for (int i = p->topo - 1; i >= 0; i--) {
        printf("%d\n", p->itens[i]);
    }
}


int main() {
    Pilha p;
    criaPilha(&p);

    int opcao;
    do {
        printf("\n=== MENU PILHA ===\n");
        printf("1 - Empilhar\n");
        printf("2 - Desempilhar\n");
        printf("3 - Imprimir\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            int valor;
            printf("Digite o valor a empilhar: ");
            scanf("%d", &valor);
            empilhar(valor, &p);
        }
        else if (opcao == 2) {
            int removido = desempilhar(&p);
            if (removido != -1)
                printf("Removido: %d\n", removido);
        }
        else if (opcao == 3) {
            imprimir(&p);
        }
        else if (opcao == 0) {
            printf("Saindo...\n");
        }
        else {
            printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
