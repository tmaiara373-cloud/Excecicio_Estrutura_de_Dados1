#include <stdio.h>
struct realType {
	int valor; //numero real em casas decimais
};

//criar um numero real
struct realType criarNumero(int left, int right){
	struct realType num;
	if (left < 0)
		num.valor= left * 100 - right; //negativo
	else	
		num.valor= left * 100 + right; //positivo
	return num;		
	
}

//soma
struct realType add(struct realType a, struct realType b){
	struct realType r;
	r.valor= a.valor + b.valor;
	return r;
}

//subtracao
struct realType subtract(struct realType a, struct realType b){
	struct realType r;
	r.valor= a.valor - b.valor;
	return r;
}

//multiplicacao
struct realType multiply(struct realType a, struct realType b){
	struct realType r;
	r.valor= (a.valor * b.valor)/100;
	return r;
}

//mostrar numero
void mostrar(struct realType num){
	int inteiro = num.valor/100;
	int decimal = num.valor % 100;
	if (decimal<0) decimal *= -1; //evita -3.-20
	printf("%d,%02d",inteiro, decimal);
}

int main(){
	struct realType n1,n2;
	int left, right;
	
	printf("Digite o primeiro numero com parte inteira e decimal separadas: ");
	scanf("%d %d", &left, &right);
	n1= criarNumero(left, right);
	
	printf("Digite o segundo numero com parte inteira e decimal separadas: ");
	scanf("%d %d", &left, &right);
	n2= criarNumero(left,right);
	
	struct realType soma = add(n1,n2);
	struct realType dif = subtract(n1,n2);
	struct realType mult = multiply(n1,n2);
	
	printf("\nResultados:\n");
	printf("Soma: ");mostrar(soma);
	printf("\n");
	printf("Subtracao: ");mostrar(dif);
	printf("\n");
	printf("Multiplicacao: ");mostrar(mult);
	printf("\n");
	
	return 0;
}
