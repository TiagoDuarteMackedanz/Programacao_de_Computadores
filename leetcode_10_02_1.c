/* Aula 22/02/2023 */
// Peter's Smokes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	
	int n,k,total, total1;
	
	printf("Digite quantos Cigarros Peter vai fumar: ");
	scanf("%d", &n);
	printf("Digite quantos Cigarros se faz com as bitucas: ");
	scanf("%d", &k);
	
	total=n-k;
	total1=n+total;
	
	printf("Total de Cigarros que Peter vai ter: %d", total1);
	
	return 0;
}

