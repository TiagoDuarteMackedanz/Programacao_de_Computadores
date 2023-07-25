/* Fatorial Com Função */

#include <stdio.h>

int fatorial (int n);

int main() {
	printf ("%d", fatorial(6));
	
	return 0;
}

	int fatorial (int n) {
		if ((n==0) || (n==1))
			return 1;
		else
			return n*fatorial(n-1);
}
