#include "listaSequencial.h"

int main (int argc, char *argv[])
{
    //criando uma nova lista (é preciso utilizar a função malloc)
    Lista *l = novaLista();
    
    Item x = 1;
    Item y = 5;
    Item z = 2;
    inserir(x, l);
    inserir(y, l);
    inserir(z, l);
    imprimir(l);
    
    remover(x, l);
    imprimir(l);

    //é preciso liberar o espaço com a função free (que foi requisitado coma função malloc)
    liberarLista(l);

    printf("\nFIM\n\n");

    return 0;
}
