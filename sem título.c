/* Escreva um programa para ler as notas das duas avaliações de um aluno no semestre,
calcular e escrever a média semestral e uma mensagem indicando se ele foi aprovado,
reprovado ou está em exame. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void) {
	
	float nota1, nota2, media;
	
	printf ("Digite o valor da primeira prova: ");
	scanf ("%f", &nota1);
	
	printf ("Digite o valor da segunda prova: ");
	scanf ("%f", &nota2);
	
	media=(nota1+nota2)/2;
	
	if (nota >= 7) {
	printf ("Aprovado!");
	}
	
	if (nota =< 7) {
	printf ("Exame");
	}
	
	if (nota >= 7) {
	printf ("Reprovado");
	}
	
	return 0;
}

