/* Aula 22/02/2023 */
// Peter's Smokes

#include <stdio.h>


int main() {
	
	int cigarro,bituca,total,total1, total2, total3;
	
	do {
	printf("Digite quantos Cigarros Peter vai fumar: ");
	scanf("%d", &cigarro);
	
	printf("Digite quantos Cigarros se faz com as bitucas: ");
	scanf("%d", &bituca);
	
	total = cigarro/bituca;
	total1 = cigarro + total;
	total2 = total/bituca;
	total3 = total1+total2;
	
	printf("Total de Cigarros que Peter vai ter: %d\n\n", total3);
	}
	while ((cigarro>0) && (bituca>0));
	
	return 0;
}

