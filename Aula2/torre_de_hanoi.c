#include <stdio.h>

void hanoi (int n, char origem, char trabalho, char destino){
    if (n > 0){
        hanoi(n - 1, origem, destino, trabalho);
        printf("Mover disco %d de %c para %c\n",n, origem, destino);
        hanoi(n - 1, trabalho, origem, destino);
    }

}
int main (){
    int discos=3;
    hanoi(discos, 'A', 'B', 'C');
    return 0;
}

//Atualizacao
