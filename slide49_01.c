/*
slide49_01
 */
 
#include <stdio.h>

int main()
{
	int a,b,c,n,i,soma;
	
	a=1;
	b=1;
	
	scanf("%d", &n);
	printf("%d \n%d ", a, b);
	
	for(i=1; i<=n; i++){
		
	c = a + b;
	soma = soma + c;
	
	printf("\n%d ", c);
	
	a = b;
	b = c;
	}
	
	printf("\nA soma foi de: %d", soma);
	
	return 0;
}

