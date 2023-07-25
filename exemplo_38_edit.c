/* */

#include <stdio.h>

void imprime(int num[10]); //cabeçalho da função é um vetor inteiro de 10 posições

int main()
{
	int t[10], i;
	for (i = 0; i < 10; i++)
		t[i] = i;
	imprime(t); //chamando função imprime com "t" o vetor, colocando o nome do vetor passa ele inteiro
	return 0;
}

void imprime(int num[10]) //explicitamente que o vetor tem 10 elementos
{
	int i;
	for (i = 0; i < 10; i++)
		printf("%d ", num[i]);
}

//melhor maneira de fazer uma comparação é essa sem necessidade de fazer um "Bubble Sort".
