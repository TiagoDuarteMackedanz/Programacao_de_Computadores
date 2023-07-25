/* Fibonacci com Função */

#include <stdio.h>

int fatorial (int n); // sempre declarar as funções como se fossem "variáveis"
int fibonacci (int n); // sempre declarar as funções como se fossem "variáveis"

int main() {
	printf ("%d\n", fatorial(6)); //imprime o valor que já foi fornecido, exemplo 6
	printf ("%d\n", fibonacci(12)); //imprime o valor que já foi fornecido, exemplo 12
	
	return 0;
}
//Após o Main as demais são as funções que são feitas para serem chamadas dentro de um determinado programa.

//Função Fatorial:
	int fatorial (int n) {
		if ((n==0) || (n==1))
			return 1;
		else
			return n*fatorial(n-1);
}
//Função Fibonacci:
	int fibonacci (int n) {
		if ((n==1)||(n==2))
			return 1;
		else
		return fibonacci(n-1)+fibonacci(n-2);
}

//A Função é feita abaixo do Main, onde dentro do Main, são chamadas as Funções.
