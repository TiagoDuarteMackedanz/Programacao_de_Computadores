/* exercicio 3 - Se i e j são variáveis inteiras e p e q ponteiros 
 para int, quais das seguintes expressões de atribuição são ilegais? */

#include <stdio.h>

int main() {
	
	int i=3, j=5;
	int *p, *q;
	
	p = &i;
	q = &j;

		//printf ("%d", p = &i); //legal
		
		//*printf ("%d", *q = &j); //falhou
		
		//printf ("%d", p = &*&i); //legal
		
		//printf ("%d", i = (*&)j); //falhou
		
		//printf ("%d", i = *&j); //legal //5
	
		//printf ("%d", i = *&*&j); //legal //5
		
		//printf ("%d", q = *p); //legal //3
		
		printf ("%d", i = (*p)^+ + *q); //legal //6
		
	return 0;
	}
