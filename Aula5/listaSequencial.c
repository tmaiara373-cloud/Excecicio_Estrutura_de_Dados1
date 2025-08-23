#include "listaSequencial.h"

// Tipo de dado da lista
typedef int Item;

// Estrutura da lista
typedef struct ListaSequencial {
    Item itens[MAX];
    int n;
} Lista;


Lista *novaLista()
{
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l != NULL) {
        l->n = 0;
    }
    return l;
}

int buscar(Item x, Lista *l)
{
     for (int i = 0; i < l->n; i++) {
        if (l->itens[i] == x) return i;
    }
    return -1;
}

bool inserir(Item x, Lista *l)
{
    if (l->n == MAX) {
        printf("Overflow!\n");
        return false;
    }
    if (buscar(x, l) != -1) {
        printf("O elemento já existe!\n");
        return false;
    }
    int i = l->n - 1;
    while (i >= 0 && l->itens[i] > x) {
        l->itens[i + 1] = l->itens[i];
        i--;
    }
    l->itens[i + 1] = x;
    l->n++;
    return true;
}

bool remover(Item x, Lista *l)
{
    if (l->n == 0) {
        printf("Underflow!\n");
        return false;
    }
    int pos = buscar(x, l);
    if (pos == -1) {
        printf("Elemento inexistente!\n");
        return false;
    }
    for (int i = pos; i < l->n - 1; i++) {
        l->itens[i] = l->itens[i + 1];
    }
    l->n--;
    return true;
}

void imprimir(Lista *l)
{
    printf("Lista: ");
    for (int i = 0; i < l->n; i++) {
        printf("%d ", l->itens[i]);
    }
    printf("\n");
}

void liberarLista(Lista *l)
{
    free(l);
}
