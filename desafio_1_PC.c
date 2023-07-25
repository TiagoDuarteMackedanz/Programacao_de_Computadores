//Tiago Duarte Mackedanz - Turma: M11 - Programação de Computadores

#include <stdio.h>
#include <math.h>

//Declarando as Funcoes
double somar (double num1, double num2);
double subtrair (double num1, double num2);
double multiplicar (double num1, double num2);
double dividir (double num1, double num2);
long fatorial (double num1);

//Main
int main () {
	
	int calculadora; 
	double valor1, valor2, resultado;

		do {
		printf ("\n\nBem-Vindo a Calculadora!\n\n");
		printf (" #1# - Soma\n #2# - Subtracao\n #3# - Multiplicacao\n #4# - Divisao\n #5# - Fatorial\n #0# - Sair\n\n"); //operações
		printf ("Digite o Numero da Operacao Correspondente: ");
		scanf("%d", &calculadora);
		
		switch (calculadora) {
			case 1:
				printf("\n#Soma#\n");
				printf("Digite o Primeiro Valor: ");
				scanf("%lf", &valor1);
				printf("Digite o Segundo Valor: ");
				scanf("%lf", &valor2);
				resultado = somar(valor1, valor2);
				printf("O Resultado da Soma: %.2f", resultado);
				break;
			case 2:
				printf("\n#Subtracao#\n");
				printf("Digite o Primeiro Valor: ");
				scanf("%lf", &valor1);
				printf("Digite o Segundo Valor: ");
				scanf("%lf", &valor2);
				resultado = subtrair(valor1, valor2);
				printf("O Resultado da Subtracao: %.2f", resultado);
				break;
			case 3:
				printf("\n#Multiplicacao#\n");
				printf("Digite o Primeiro Valor: ");
				scanf("%lf", &valor1);
				printf("Digite o Segundo Valor: ");
				scanf("%lf", &valor2);
				resultado = multiplicar(valor1, valor2);
				printf("O Resultado da Multiplicacao: %.2f", resultado);
				break;
			case 4:
				printf("\n#Divisao#\n");
				printf("Digite o Primeiro Valor: ");
				scanf("%lf", &valor1);
				printf("Digite o Segundo Valor: ");
				scanf("%lf", &valor2);
				resultado = dividir(valor1, valor2);
				if (valor2==0){
				printf ("Erro! Divisao por Zero!");
				}
				else{
				printf("O Resultado da Divisao: %.2f", resultado);	
				}
				break;
			case 5:
				printf("\n#Fatorial#\n");
				printf("Digite o Numero para Saber seu Fatorial: ");
				scanf("%lf", &valor1);
				resultado = fatorial(valor1);
				if (resultado<0) {
				printf("Erro! Fatorial nao Existe para Numeros Negativos!");
				}
				else {
				printf("O Resultado do Fatorial: %.0lf", resultado);	
				}
				
				break;
			default:
				if ((calculadora<0) || (calculadora>5)) {
				printf("\nNenhuma Operacao Valida Selecionada!\n");
				}
				break;
		}
	}
		while (calculadora!=0);
			printf ("\nVoce Saiu!");
	
	return 0;
}

//Funcoes
double somar (double num1, double num2) {
	return num1+num2;
}

double subtrair (double num1, double num2) {
	return num1-num2;
}

double multiplicar (double num1, double num2) {
	return num1*num2;
}

double dividir (double num1, double num2) {
	return num1/num2;	
}

long fatorial (double num1) {
	if (num1<0) {
	return-1;
	}
	if ((num1==0) || (num1==1)) {
	return 1;
	}
	else {
	long num_int = lround(num1);
	return num_int * fatorial(num_int - 1);
	}
}	
