/* Faça um programa que lê n números decimais, armazenando-os 
em um vetor. Após, o programa identifica o menor número do vetor e 
imprime sua posição. */

#include <stdio.h>

int main() {
	
	int numero[50];
	int i, maior, armaz;
	
	for (i = 0; i < 100; i++) {
		printf("Numero %d:\n", i + 1);
		scanf("%d", &numero[i]);
	}
	
	return 0;
}
